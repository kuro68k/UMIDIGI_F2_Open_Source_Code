/*
 * Copyright (c) 2016, ARM Limited and Contributors. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * Neither the name of ARM nor the names of its contributors may be used
 * to endorse or promote products derived from this software without specific
 * prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#include <arch_helpers.h>
#include <arm_gic.h>
#include <assert.h>
#include <bl_common.h>
#include <bl31_fiq_handler.h>
#include <cci.h>
#include <console.h>
#include <context_mgmt.h>
#include <debug.h>
#include <interrupt_mgmt.h>
#include <l2c.h>
#include <log.h>
#include <mcucfg.h>
#include <fiq_cache.h>
#include <mmio.h>
#include <mt_spm.h>
#include <mtspmc.h>
#include <mtk_aee_debug.h>
#include <mtk_plat_common.h>
#include <mtk_sip_svc.h>
#include <plat_debug.h>
#include <plat_private.h>
#include <plat_pm.h>	/* gic_setup(void) */
#include <platform.h>
#include <platform_def.h>
#include <string.h>
#include <wfifo.h>
#include <xlat_tables_v2.h>
#include <scu.h>
#include <pccif.h>

/*******************************************************************************
 * Declarations of linker defined symbols which will help us find the layout
 * of trusted SRAM
 ******************************************************************************/
unsigned long __RO_START__;
unsigned long __RO_END__;

unsigned long __COHERENT_RAM_START__;
unsigned long __COHERENT_RAM_END__;

/*
 * The next 2 constants identify the extents of the code & RO data region.
 * These addresses are used by the MMU setup code and therefore they must be
 * page-aligned.  It is the responsibility of the linker script to ensure that
 * __RO_START__ and __RO_END__ linker symbols refer to page-aligned addresses.
 */
#define BL31_RO_BASE (unsigned long)(&__RO_START__)
#define BL31_RO_LIMIT (unsigned long)(&__RO_END__)

/*
 * The next 2 constants identify the extents of the coherent memory region.
 * These addresses are used by the MMU setup code and therefore they must be
 * page-aligned.  It is the responsibility of the linker script to ensure that
 * __COHERENT_RAM_START__ and __COHERENT_RAM_END__ linker symbols
 * refer to page-aligned addresses.
 */
#define BL31_COHERENT_RAM_BASE (unsigned long)(&__COHERENT_RAM_START__)
#define BL31_COHERENT_RAM_LIMIT (unsigned long)(&__COHERENT_RAM_END__)

/*
 * Placeholder variables for copying the arguments that have been passed to
 * BL3-1 from BL2.
 */
#define BOOT_REASON_INVALID 0xffffffff
static entry_point_info_t bl32_image_ep_info;
static entry_point_info_t bl33_image_ep_info;
static unsigned int gboot_reason = BOOT_REASON_INVALID;
static unsigned int gis_abnormal_boot = NO_ABNORMAL_BOOT_TAG;
struct boot_tag_ram_console_info ram_console_info = { 0 };

static const int cci_map[] = {
	PLAT_MT_CCI_CLUSTER0_SL_IFACE_IX,
	PLAT_MT_CCI_CLUSTER1_SL_IFACE_IX
};

/* Table of regions to map using the MMU.  */
const mmap_region_t plat_mmap[] = {
	/* for TF text, RO, RW */
	MAP_REGION_FLAT(MTK_DEV_RNG0_BASE, MTK_DEV_RNG0_SIZE,
			MT_DEVICE | MT_RW | MT_SECURE),
	MAP_REGION_FLAT(MTK_DEV_RNG1_BASE, MTK_DEV_RNG1_SIZE,
			MT_DEVICE | MT_RW | MT_SECURE),
	MAP_REGION_FLAT(MTK_DEV_RNG2_BASE, MTK_DEV_RNG2_SIZE,
			MT_DEVICE | MT_RW | MT_SECURE),
	MAP_REGION_FLAT(MTK_DEV_RNG3_BASE, MTK_DEV_RNG3_SIZE,
			MT_DEVICE | MT_RW | MT_SECURE),
	MAP_REGION_FLAT(PLAT_MT_CCI_BASE & ~(PAGE_SIZE_MASK), CCI_SIZE,
								MT_DEVICE | MT_RW | MT_SECURE),
	MAP_REGION_FLAT(MTK_SSPM_BASE, MTK_SSPM_SIZE,
			MT_DEVICE | MT_RW | MT_SECURE),

	MAP_REGION_FLAT(SSPM_MBOX_3_BASE, SSPM_MBOX_3_SIZE,
			MT_DEVICE | MT_RW | MT_SECURE),

	MAP_REGION_FLAT(MTK_CHIP_SRAM_BASE, PAGE_SIZE,
			MT_DEVICE | MT_RW | MT_SECURE),
	MAP_REGION_FLAT(MDPERI_MDSBC_KEY_CONFIG & ~(PAGE_SIZE_MASK),
			MDPERI_MDSBC_KEY_SIZE, MT_DEVICE | MT_RW | MT_SECURE),
	{ 0 }

};

unsigned int plat_get_syscnt_freq2(void)
{
	return SYS_COUNTER_FREQ_IN_TICKS;
}

void plat_cci_init(void)
{
	/*
	 * Initialize CCI driver
	 */
	cci_init(PLAT_MT_CCI_BASE, cci_map, ARRAY_SIZE(cci_map));
}

void plat_cci_enable(void)
{
	/*
	 * Enable CCI coherency for this cluster.
	 */
	cci_enable_snoop_dvm_reqs(MPIDR_AFFLVL1_VAL(read_mpidr()));
}

void plat_cci_disable(void)
{
	cci_disable_snoop_dvm_reqs(MPIDR_AFFLVL1_VAL(read_mpidr()));
}

void ram_console_info_get(struct boot_tag_ram_console_info *rci)
{
	if (rci == NULL)
		return;
	*rci = ram_console_info;
}

uint32_t plat_get_spsr_for_bl32_entry(void)
{
	/*
	 * The Secure Payload Dispatcher service is responsible for
	 * setting the SPSR prior to entry into the BL3-2 image.
	 */
	return 0;
}

static void platform_setup_cpu(void)
{
	INFO("%s()\n", __func__);

	mmio_write_32(MP0_RW_RSVD0, 0x00000001);
	INFO("addr of cci_adb400_dcm_config: 0x%x\n",
	mmio_read_32(CCI_ADB400_DCM_CONFIG));
	INFO("addr of sync_dcm_config: 0x%x\n",
	mmio_read_32(SYNC_DCM_CONFIG));

	INFO("mp0_spmc: 0x%x\n", mmio_read_32(MP0_SPMC));
	INFO("mp1_spmc: 0x%x\n", mmio_read_32(MP1_SPMC));
}

/*******************************************************************************
 * Return a pointer to the 'entry_point_info' structure of the next image for
 * the security state specified. BL33 corresponds to the non-secure image type
 * while BL32 corresponds to the secure image type. A NULL pointer is returned
 * if the image does not exist.
 ******************************************************************************/
entry_point_info_t *bl31_plat_get_next_image_ep_info(uint32_t type)
{
	entry_point_info_t *next_image_info;

	next_image_info = (type == NON_SECURE) ? &bl33_image_ep_info : &bl32_image_ep_info;

	/* None of the images on this platform can have 0x0 as the entrypoint */
	/* TODO: Our fiqd is with NULL entrypoint */
	/* if (next_image_info->pc) */
	return next_image_info;
	/* else */
	/*	return NULL; */
}

/*******************************************************************************
 * Perform any BL3-1 early platform setup. Here is an opportunity to copy
 * parameters passed by the calling EL (S-EL1 in BL2 & S-EL3 in BL1) before they
 * are lost (potentially). This needs to be done before the MMU is initialized
 * so that the memory layout can be used while creating page tables.
 * BL2 has flushed this information to memory, so we are guaranteed to pick up
 * good data.
 ******************************************************************************/
void bl31_early_platform_setup(bl31_params_t *from_bl2,
			       void *plat_params_from_bl2)
{
	struct mtk_bl_param_t *pmtk_bl_param_t = (struct mtk_bl_param_t *)from_bl2;
	struct atf_arg_t *teearg;
	struct boot_tag *pboot_tag;
	struct boot_tag *tags;

#if !defined(ATF_BYPASS_DRAM)
	config_L2_size();
#endif
	/* preloader is in 32 bit state, high 32bits of 64 bit GP registers are UNKNOWN if CPU change to 64 bit state
	 *  So we need to clear high 32bit, which may be random value
	 */
	pmtk_bl_param_t = (struct mtk_bl_param_t *)((uint64_t)pmtk_bl_param_t & 0x00000000ffffffff);
	pboot_tag = (struct boot_tag *)(pmtk_bl_param_t->bootarg_loc);
	teearg  = (struct atf_arg_t *)pmtk_bl_param_t->tee_info_addr;

	console_init(teearg->atf_log_port, UART_CLOCK, UART_BAUDRATE);
	memcpy((void *)&gteearg, (void *)teearg, sizeof(struct atf_arg_t));

	/* Iterate each BOOT TAG from preloader */
	for (tags = pboot_tag; tags->hdr.size; tags = boot_tag_next(tags)) {
		switch (tags->hdr.tag) {
		case BOOT_TAG_BOOT_REASON:
			gboot_reason = tags->u.boot_reason.boot_reason;
			INFO("BOOT_REASON: %d\n", tags->u.boot_reason.boot_reason);
			break;
		case BOOT_TAG_IS_ABNORMAL_BOOT:
			gis_abnormal_boot = tags->u.is_abnormal_boot.is_abnormal_boot;
			INFO("IS_ABNORMAL_BOOT: %d\n", tags->u.is_abnormal_boot.is_abnormal_boot);
			break;
		case BOOT_TAG_RAM_CONSOLE_INFO:
			ram_console_info = tags->u.ram_console_info;
			INFO("RAM_CONSOLE_INFO: addr:0x%x, size:0x%x, type:0x%x, offset:0x%x\n",
				tags->u.ram_console_info.sram_addr,
				tags->u.ram_console_info.sram_size,
				tags->u.ram_console_info.def_type,
				tags->u.ram_console_info.memory_info_offset);
			break;
		}
	}
	if (gis_abnormal_boot == NO_ABNORMAL_BOOT_TAG)
		INFO("Preloader is without is_abnormal_boot tag, try to keep data in crash buffer\n");

#if !defined(ATF_BYPASS_DRAM)
	assert(gboot_reason != BOOT_REASON_INVALID);
	/* init system counter in ATF */
	setup_syscnt();
	setup_systimer();
#endif /* #if defined(ATF_BYPASS_DRAM) */

	VERBOSE("bl31_setup\n");

	assert(from_bl2 != NULL);
	/* Populate entry point information for BL3-2 and BL3-3 */
	SET_PARAM_HEAD(&bl32_image_ep_info,
				PARAM_EP,
				VERSION_1,
				0);
	SET_SECURITY_STATE(bl32_image_ep_info.h.attr, SECURE);
	bl32_image_ep_info.pc = teearg->tee_entry;
	bl32_image_ep_info.spsr = plat_get_spsr_for_bl32_entry();

	SET_PARAM_HEAD(&bl33_image_ep_info,
				PARAM_EP,
				VERSION_1,
				0);
	/*
	 * Tell BL3-1 where the non-trusted software image
	 * is located and the entry state information
	 */
	/* BL33_START_ADDRESS */
	bl33_image_ep_info.pc = pmtk_bl_param_t->bl33_start_addr;
	bl33_image_ep_info.spsr = plat_get_spsr_for_bl33_entry();
	/* BOOT_ARGUMENT_LOCATION */
	bl33_image_ep_info.args.arg4 = pmtk_bl_param_t->bootarg_loc;
	/* BOOT_ARGUMENT_SIZE */
	bl33_image_ep_info.args.arg5 = pmtk_bl_param_t->bootarg_size;
	SET_SECURITY_STATE(bl33_image_ep_info.h.attr, NON_SECURE);
}

/*******************************************************************************
 * Platform code used to process boot reason
 ******************************************************************************/
void plat_boot_process(unsigned int boot_reason)
{
}

/*******************************************************************************
 * Perform any BL3-1 platform setup code
 ******************************************************************************/
void bl31_platform_setup(void)
{
	uint32_t flags = 0;
	int cpu = platform_get_core_pos(read_mpidr());

	VERBOSE("%s()\n", __func__);
	enable_cpu_status_for_cache(cpu);
	plat_boot_process(gboot_reason);
	platform_setup_cpu();
	plat_delay_timer_init();

	/* Enable mcusys emi wfifo */
	enable_emi_wfifo();

#if 0 /* fixme for common interface */
	/* Initialize the gic cpu and distributor interfaces */
	plat_mt_gic_init();
	arm_gic_setup();
#else
	/* Initialize the gic cpu and distributor interfaces */
	gic_setup();
#endif
	/* Topologies are best known to the platform. */
	mt_setup_topology();

#if !defined(ATF_BYPASS_DRAM)
	/* Initialize spm at boot time */
	spm_boot_init();
#endif

	/* Register EL3 interrupt handler */
	set_interrupt_rm_flag(flags, NON_SECURE);

	uint32_t rc = register_interrupt_type_handler(INTR_TYPE_EL3,
						bl31_el3_fiq_handler,
						flags);
	assert(rc == 0);
	NOTICE("call pccif1_hw_init\n");
	pccif1_hw_init();
}

/*******************************************************************************
 * Perform any BL3-1 platform setup code after LK stage
 ******************************************************************************/
void bl31_post_platform_setup(void)
{
	static uint8_t post_plat_setup_once_flag;
	/* only support in booting flow */
	if (post_plat_setup_once_flag == 0) {

		post_plat_setup_once_flag = 1;
		console_init(gteearg.atf_log_port, UART_CLOCK, UART_BAUDRATE);

		/* clear_all_on_mux() must be executed after lk dump */
		INFO("clear_all_on_mux\n");
		clear_all_on_mux();

#if !defined(MTK_FPGA_LDVT) && !defined(ATF_BYPASS_DRAM)
		/* spmc_init() should be later than clear_all_on_mux() */
		spmc_init();
#endif
		console_uninit();
	}
}

/*******************************************************************************
 * Perform the very early platform specific architectural setup here. At the
 * moment this is only intializes the mmu in a quick and dirty way.
 ******************************************************************************/
void bl31_plat_arch_setup(void)
{
	INFO("%s()\n", __func__);

	plat_cci_init();
	plat_cci_enable();
	enable_scu(read_mpidr());

	struct atf_arg_t *teearg = &gteearg;
	if (teearg->atf_log_buf_size != 0)
	{
		INFO("mmap atf buffer : 0x%lx, 0x%x\n\r", teearg->atf_log_buf_start,
			teearg->atf_log_buf_size);
		mmap_add_region((teearg->atf_log_buf_start & ~(PAGE_SIZE_MASK)),
			(teearg->atf_log_buf_start & ~(PAGE_SIZE_MASK)), teearg->atf_log_buf_size,
			MT_DEVICE | MT_RW | MT_NS);
	}

	if (ram_console_info.sram_addr && ram_console_info.sram_size) {
		uint32_t pmore = 0;

		if (!IS_PAGE_ALIGNED(ram_console_info.sram_addr))
			pmore += PAGE_SIZE;
		if (!IS_PAGE_ALIGNED(ram_console_info.sram_size))
			pmore += PAGE_SIZE;
		INFO("mmap ram_console: 0x%x, 0x%x, (pmore:0x%x)\n\r",
			ram_console_info.sram_addr, ram_console_info.sram_size, pmore);
		/* address and size need to be PAGE_SIZE alignment */
		mmap_add_region((ram_console_info.sram_addr & ~(PAGE_SIZE_MASK)),
			(ram_console_info.sram_addr & ~(PAGE_SIZE_MASK)),
			(ram_console_info.sram_size + pmore) & (~(PAGE_SIZE_MASK)),
			MT_DEVICE | MT_RW | MT_NS);
	} else {
		INFO("mmap ram_console: illegal addr:0x%x, size:0x%x\n",
			ram_console_info.sram_addr, ram_console_info.sram_size);
	}

#if !defined(ATF_BYPASS_DRAM)
	/* Build up platform page table and enable MMU */
	configure_mmu_el3(plat_mmap);
#endif

	/* Initialize for ATF log buffer */
	if (teearg->atf_log_buf_size != 0) {
		teearg->atf_aee_debug_buf_size = ATF_AEE_BUFFER_SIZE;
		teearg->atf_aee_debug_buf_start =
			(teearg->atf_log_buf_start + teearg->atf_log_buf_size - ATF_AEE_BUFFER_SIZE);
		mt_log_setup(teearg->atf_log_buf_start, teearg->atf_log_buf_size,
					teearg->atf_aee_debug_buf_size, gis_abnormal_boot);
		INFO("ATF log service is registered (0x%lx, aee:0x%lx)\n",
					teearg->atf_log_buf_start, teearg->atf_aee_debug_buf_start);
	} else {
		teearg->atf_aee_debug_buf_size = 0;
		teearg->atf_aee_debug_buf_start = 0;
	}
	/* Platform code before bl31_main */
	/* compatible to the earlier chipset */

	/* Show debug info to ATF log buffer & UART */
	NOTICE("BL31_BASE=0x%x, BL31_TZRAM_SIZE=0x%x\n", BL31_BASE, BL31_TZRAM_SIZE);
	NOTICE("TZRAM2_BASE=0x%x, TZRAM2_SIZE=0x%x\n", TZRAM2_BASE, TZRAM2_SIZE);
}

entry_point_info_t *bl31_plat_get_next_kernel64_ep_info(void)
{
	entry_point_info_t *next_image_info;
	unsigned long el_status;
	unsigned int mode;

	el_status = 0;
	mode = 0;

	/* Kernel image is always non-secured */
	next_image_info = &bl33_image_ep_info;

	/* Figure out what mode we enter the non-secure world in */
	el_status = read_id_aa64pfr0_el1() >> ID_AA64PFR0_EL2_SHIFT;
	el_status &= ID_AA64PFR0_ELX_MASK;

	INFO("Kernel_EL %d\n", el_status?2:1);
	if (el_status)
		mode = MODE_EL2;
	else
		mode = MODE_EL1;

	NOTICE("Kernel is 64Bit\n");
	next_image_info->spsr = SPSR_64(mode, MODE_SP_ELX, DISABLE_ALL_EXCEPTIONS);
	next_image_info->pc = get_kernel_info_pc();
	next_image_info->args.arg0 = get_kernel_info_r0();
	next_image_info->args.arg1 = get_kernel_info_r1();

	NOTICE("pc=0x%lx, r0=0x%lx, r1=0x%lx\n",
			next_image_info->pc,
			next_image_info->args.arg0,
			next_image_info->args.arg1);


	SET_SECURITY_STATE(next_image_info->h.attr, NON_SECURE);

	/* None of the images on this platform can have 0x0 as the entrypoint */
	if (next_image_info->pc)
		return next_image_info;
	else
		return NULL;
}

entry_point_info_t *bl31_plat_get_next_kernel32_ep_info(void)
{
	entry_point_info_t *next_image_info;
	unsigned int mode;

	mode = 0;

	/* Kernel image is always non-secured */
	next_image_info = &bl33_image_ep_info;

	/* Figure out what mode we enter the non-secure world in */
	mode = MODE32_hyp;
	/*
	 * TODO: Consider the possibility of specifying the SPSR in
	 * the FIP ToC and allowing the platform to have a say as
	 * well.
	 */

	NOTICE("Kernel is 32Bit\n");
	next_image_info->spsr = SPSR_MODE32(mode, SPSR_T_ARM, SPSR_E_LITTLE,
							(DAIF_FIQ_BIT | DAIF_IRQ_BIT | DAIF_ABT_BIT));
	next_image_info->pc = get_kernel_info_pc();
	next_image_info->args.arg0 = get_kernel_info_r0();
	next_image_info->args.arg1 = get_kernel_info_r1();
	next_image_info->args.arg2 = get_kernel_info_r2();

	NOTICE("pc=0x%lx, r0=0x%lx, r1=0x%lx, r2=0x%lx\n",
			next_image_info->pc,
			next_image_info->args.arg0,
			next_image_info->args.arg1,
			next_image_info->args.arg2);

	SET_SECURITY_STATE(next_image_info->h.attr, NON_SECURE);

	/* None of the images on this platform can have 0x0 as the entrypoint */
	if (next_image_info->pc)
		return next_image_info;
	else
		return NULL;
}

void bl31_prepare_kernel_entry(uint64_t k32_64)
{
	entry_point_info_t *next_image_info;
	uint32_t image_type;

	/* Determine which image to execute next */
	image_type = NON_SECURE; /* bl31_get_next_image_type(); */

	/* Leave lk then jump to kernel */
	mtk_lk_stage = 0;
	wdt_kernel_cb_addr = 0;

	/* Program EL3 registers to enable entry into the next EL */

	if (k32_64 == 0)
		next_image_info = bl31_plat_get_next_kernel32_ep_info();
	else
		next_image_info = bl31_plat_get_next_kernel64_ep_info();

	assert(next_image_info);
	assert(image_type == GET_SECURITY_STATE(next_image_info->h.attr));

	INFO("BL3-1: Preparing for EL3 exit to %s world, Kernel\n",
		(image_type == SECURE) ? "secure" : "normal");
	INFO("BL3-1: Next image address = 0x%llx\n",
		(unsigned long long) next_image_info->pc);
	INFO("BL3-1: Next image spsr = 0x%x\n", next_image_info->spsr);
	cm_init_my_context(next_image_info);
	cm_prepare_el3_exit(image_type);
}

