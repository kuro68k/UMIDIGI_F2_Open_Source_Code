#ifndef _DRAMC_H_
#define _DRAMC_H_

//#define SPM_BASE			0x10B00000
#define APMCU_PCM_REG0_DATA		(SPM_BASE + 0x100)
#define APMCU_DPY_CH2_PWR_CON		(SPM_BASE + 0x320)
#define APMCU_DPY_CH3_PWR_CON		(SPM_BASE + 0x324)
#define APMCU_DRAMC_DPY_CLK_SW_CON_SEL	(SPM_BASE + 0x460)
#define APMCU_DRAMC_DPY_CLK_SW_CON	(SPM_BASE + 0x464)
#define APMCU_DRAMC_DPY_CLK_SW_CON_SEL2	(SPM_BASE + 0x468)
#define APMCU_DRAMC_DPY_CLK_SW_CON2	(SPM_BASE + 0x46C)
#define APMCU_DRAMC_DPY_CLK_SW_CON_SEL3	(SPM_BASE + 0x470)
#define APMCU_DRAMC_DPY_CLK_SW_CON_SEL4	(SPM_BASE + 0x490)
#define APMCU_DRAMC_DPY_CLK_SW_CON4	(SPM_BASE + 0x494)

#define DRAMC_AO_CHC_BASE		0x10342000
#define DRAMC_AO_CHC_DQSOSCR		(DRAMC_AO_CHC_BASE + 0xC8)
#define DRAMC_AO_CHC_DUMMY_RD		(DRAMC_AO_CHC_BASE + 0xD0)
#define DRAMC_AO_CHC_SHUCTRL		(DRAMC_AO_CHC_BASE + 0xD4)
#define DRAMC_AO_CHC_SHUSTATUS		(DRAMC_AO_CHC_BASE + 0xE4)

#define DRAMC_AO_CHD_BASE		0x1034A000
#define DRAMC_AO_CHD_DQSOSCR		(DRAMC_AO_CHD_BASE + 0xC8)
#define DRAMC_AO_CHD_DUMMY_RD		(DRAMC_AO_CHD_BASE + 0xD0)
#define DRAMC_AO_CHD_SHUCTRL		(DRAMC_AO_CHD_BASE + 0xD4)
#define DRAMC_AO_CHD_SHUSTATUS		(DRAMC_AO_CHD_BASE + 0xE4)

#define APMCU_DDRPHY2AO_BASE		0x10340000
#define DDRPHY_CHC_MISC_CG_CTRL0	(APMCU_DDRPHY2AO_BASE + 0x284)

#define APMCU_DDRPHY3AO_BASE		0x10348000
#define DDRPHY_CHD_MISC_CG_CTRL0	(APMCU_DDRPHY3AO_BASE + 0x284)

#define APMCU_INFRACFG_AO_BASE			0x10000000
#define APMCU_INFRA_TOPAXI_PROTECTEN_1_SET	(APMCU_INFRACFG_AO_BASE+0x2A8)
#define APMCU_INFRA_TOPAXI_PROTECTEN_1_CLR	(APMCU_INFRACFG_AO_BASE+0x2AC)

#define APMCU_TOPCKGEN_BASE		0x10210000
#define APMCU_CLK_SCP_CFG_2		(APMCU_TOPCKGEN_BASE + 0x408)

#define APMCU_PWR_RST_B			(0x1 << 0)
#define APMCU_PWR_ISO			(0x1 << 1)
#define APMCU_PWR_CLK_DIS		(0x1 << 4)

#define APMCU_DPY_CH2_PROT_BIT_MASK	(0x1 << 2)
#define APMCU_DPY_CH2_SRAM_PDN		(0xF << 8)
#define APMCU_DPY_CH2_SRAM_PDN_ACK	(0x4 << 12)
#define APMCU_DPY_CH2_SRAM_PDN_ACK_BIT2	(0x1 << 14)
#define APMCU_DPY_CH3_PROT_BIT_MASK	(0x1 << 3)
#define APMCU_DPY_CH3_SRAM_PDN		(0xF << 8)
#define APMCU_DPY_CH3_SRAM_PDN_ACK	(0x8 << 12)
#define APMCU_DPY_CH3_SRAM_PDN_ACK_BIT3	(0x1 << 15)

extern uint32_t sip_dram_smc_chcd(unsigned int OnOff);

#endif
