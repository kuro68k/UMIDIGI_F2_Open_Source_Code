MTK_ATF_SUPPORT=yes
MTK_TEE_SUPPORT=no
TRUSTONIC_TEE_SUPPORT=no
TRUSTONIC_TEE_VERSION=410
MTK_MACH_TYPE=mt6768
MTK_ATF_VERSION=v1.6
MTK_TEE_DRAM_SIZE=0x1300000
SECURE_DEINT_SUPPORT=no
#ATF_BYPASS_DRAM=yes
ifeq ($(TARGET_BUILD_VARIANT), eng)
MTK_ATF_RAM_DUMP=yes
endif
MICROTRUST_TEE_SUPPORT=no
MICROTRUST_TEE_VERSION=300
MTK_FIQ_CACHE_SUPPORT=yes
KEYMASTER_RPMB=no
KEYMASTER_WRAPKEY=yes
MTK_DRCC=yes
MTK_CM_MGR=yes
MTK_ENABLE_GENIEZONE=no
#PLATFORM_OPTION="MTK_FPGA_LDVT = yes"
MTK_ENABLE_MPU_HAL_SUPPORT=yes
HW_ASSISTED_COHERENCY=1
ifeq ($(TARGET_BUILD_VARIANT), user)
  MTK_DEBUGSYS_LOCK = yes
endif
MTK_INDIRECT_ACCESS_SUPPORT=no