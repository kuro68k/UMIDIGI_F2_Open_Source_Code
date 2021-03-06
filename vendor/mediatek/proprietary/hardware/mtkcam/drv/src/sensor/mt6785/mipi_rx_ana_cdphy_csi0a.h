#ifndef __mipi_rx_ana_cdphy_csi0a_reg_REGS_H__
#define __mipi_rx_ana_cdphy_csi0a_reg_REGS_H__

typedef unsigned int FIELD;

typedef PACKING union
{
    PACKING struct
    {
	FIELD RG_CSI0A_CPHY_EN		: 1;
	FIELD RG_CSI0A_EQ_PROTECT_EN	: 1;
	FIELD RG_CSI0A_BG_LPF_EN	: 1;
	FIELD RG_CSI0A_BG_CORE_EN	: 1;
	FIELD rsv_4			: 1;
	FIELD RG_CSI0A_DPHY_L0_CKMODE_EN : 1;
	FIELD RG_CSI0A_DPHY_L0_CKSEL	: 1;
	FIELD rsv_7			: 1;
	FIELD RG_CSI0A_DPHY_L1_CKMODE_EN : 1;
	FIELD RG_CSI0A_DPHY_L1_CKSEL	: 1;
	FIELD rsv_10			: 1;
	FIELD RG_CSI0A_DPHY_L2_CKMODE_EN : 1;
	FIELD RG_CSI0A_DPHY_L2_CKSEL	: 1;
	FIELD rsv_13			: 3;
	FIELD RG_CSI0A_BYTE_CK_RSTB_SEL : 1;
	FIELD RG_CSI0A_BYTE_CK_SWALLOW_ENB : 1;
	FIELD rsv_18			: 2;
	FIELD RG_CSI0A_DPHY_L0_CK_GATING_RSTB : 1;
	FIELD RG_CSI0A_DPHY_L1_CK_GATING_RSTB : 1;
	FIELD RG_CSI0A_DPHY_L2_CK_GATING_RSTB : 1;
	FIELD RG_CSI0A_CDPHY_EQ_LATCH_EN : 1;
	FIELD rsv_24			: 8;
    } Bits;
    UINT32 Raw;
} REG_MIPI_RX_ANA00_CSI0A, *PREG_MIPI_RX_ANA00_CSI0A;

typedef PACKING union
{
    PACKING struct
    {
	FIELD RG_CSI0A_BG_LPRX_VTH_SEL	: 3;
	FIELD rsv_3			: 1;
	FIELD RG_CSI0A_BG_LPRX_VTL_SEL	: 3;
	FIELD rsv_7			: 1;
	FIELD RG_CSI0A_BG_HSDET_VTH_SEL : 3;
	FIELD rsv_11			: 1;
	FIELD RG_CSI0A_BG_HSDET_VTL_SEL : 3;
	FIELD rsv_15			: 1;
	FIELD RG_CSI0A_BG_VREF_SEL	: 4;
	FIELD rsv_20			: 4;
	FIELD RG_CSI0A_BG_MON_VREF_SEL	: 4;
	FIELD RG_CSI0A_FORCE_HSRT_EN	: 1;
	FIELD rsv_29			: 3;
    } Bits;
    UINT32 Raw;
} REG_MIPI_RX_ANA04_CSI0A, *PREG_MIPI_RX_ANA04_CSI0A;

typedef PACKING union
{
    PACKING struct
    {
	FIELD RG_CSI0A_L0P_T0A_HSRT_CODE : 5;
	FIELD rsv_5			: 3;
	FIELD RG_CSI0A_L0N_T0B_HSRT_CODE : 5;
	FIELD rsv_13			: 3;
	FIELD RG_CSI0A_L1P_T0C_HSRT_CODE : 5;
	FIELD rsv_21			: 3;
	FIELD RG_CSI0A_L1N_T1A_HSRT_CODE : 5;
	FIELD rsv_29			: 3;
    } Bits;
    UINT32 Raw;
} REG_MIPI_RX_ANA08_CSI0A, *PREG_MIPI_RX_ANA08_CSI0A;

typedef PACKING union
{
    PACKING struct
    {
	FIELD RG_CSI0A_L2P_T1B_HSRT_CODE : 5;
	FIELD rsv_5			: 3;
	FIELD RG_CSI0A_L2N_T1C_HSRT_CODE : 5;
	FIELD rsv_13			: 19;
    } Bits;
    UINT32 Raw;
} REG_MIPI_RX_ANA0C_CSI0A, *PREG_MIPI_RX_ANA0C_CSI0A;

typedef PACKING union
{
    PACKING struct
    {
	FIELD RG_CSI0A_DPHY_L0_DELAYCAL_EN : 1;
	FIELD RG_CSI0A_DPHY_L0_DELAYCAL_RSTB : 1;
	FIELD RG_CSI0A_DPHY_L0_VREF_SEL : 6;
	FIELD RG_CSI0A_DPHY_L1_DELAYCAL_EN : 1;
	FIELD RG_CSI0A_DPHY_L1_DELAYCAL_RSTB : 1;
	FIELD RG_CSI0A_DPHY_L1_VREF_SEL : 6;
	FIELD RG_CSI0A_DPHY_L2_DELAYCAL_EN : 1;
	FIELD RG_CSI0A_DPHY_L2_DELAYCAL_RSTB : 1;
	FIELD RG_CSI0A_DPHY_L2_VREF_SEL : 6;
	FIELD RG_CSI0A_CPHY_T0_CDR_DELAYCAL_EN : 1;
	FIELD RG_CSI0A_CPHY_T0_CDR_DELAYCAL_RSTB : 1;
	FIELD RG_CSI0A_CPHY_T0_VREF_SEL : 6;
    } Bits;
    UINT32 Raw;
} REG_MIPI_RX_ANA10_CSI0A, *PREG_MIPI_RX_ANA10_CSI0A;

typedef PACKING union
{
    PACKING struct
    {
	FIELD RG_CSI0A_CPHY_T1_CDR_DELAYCAL_EN : 1;
	FIELD RG_CSI0A_CPHY_T1_CDR_DELAYCAL_RSTB : 1;
	FIELD RG_CSI0A_CPHY_T1_VREF_SEL : 6;
	FIELD rsv_8			: 24;
    } Bits;
    UINT32 Raw;
} REG_MIPI_RX_ANA14_CSI0A, *PREG_MIPI_RX_ANA14_CSI0A;

typedef PACKING union
{
    PACKING struct
    {
	FIELD RG_CSI0A_L0_T0AB_EQ_OS_CAL_EN : 1;
	FIELD RG_CSI0A_L0_T0AB_EQ_MON_EN : 1;
	FIELD RG_CSI0A_L0_T0AB_EQ_SCA	: 1;
	FIELD RG_CSI0A_L0_T0AB_EQ_SCB	: 1;
	FIELD RG_CSI0A_L0_T0AB_EQ_IS	: 2;
	FIELD RG_CSI0A_L0_T0AB_EQ_BW	: 2;
	FIELD RG_CSI0A_L0_T0AB_EQ_SRA	: 4;
	FIELD RG_CSI0A_L0_T0AB_EQ_SRB	: 4;
	FIELD RG_CSI0A_XX_T0CA_EQ_OS_CAL_EN : 1;
	FIELD RG_CSI0A_XX_T0CA_EQ_MON_EN : 1;
	FIELD RG_CSI0A_XX_T0CA_EQ_SCA	: 1;
	FIELD RG_CSI0A_XX_T0CA_EQ_SCB	: 1;
	FIELD RG_CSI0A_XX_T0CA_EQ_IS	: 2;
	FIELD RG_CSI0A_XX_T0CA_EQ_BW	: 2;
	FIELD RG_CSI0A_XX_T0CA_EQ_SRA	: 4;
	FIELD RG_CSI0A_XX_T0CA_EQ_SRB	: 4;
    } Bits;
    UINT32 Raw;
} REG_MIPI_RX_ANA18_CSI0A, *PREG_MIPI_RX_ANA18_CSI0A;

typedef PACKING union
{
    PACKING struct
    {
	FIELD RG_CSI0A_XX_T0BC_EQ_OS_CAL_EN : 1;
	FIELD RG_CSI0A_XX_T0BC_EQ_MON_EN : 1;
	FIELD RG_CSI0A_XX_T0BC_EQ_SCA	: 1;
	FIELD RG_CSI0A_XX_T0BC_EQ_SCB	: 1;
	FIELD RG_CSI0A_XX_T0BC_EQ_IS	: 2;
	FIELD RG_CSI0A_XX_T0BC_EQ_BW	: 2;
	FIELD RG_CSI0A_XX_T0BC_EQ_SRA	: 4;
	FIELD RG_CSI0A_XX_T0BC_EQ_SRB	: 4;
	FIELD RG_CSI0A_L1_T1AB_EQ_OS_CAL_EN : 1;
	FIELD RG_CSI0A_L1_T1AB_EQ_MON_EN : 1;
	FIELD RG_CSI0A_L1_T1AB_EQ_SCA	: 1;
	FIELD RG_CSI0A_L1_T1AB_EQ_SCB	: 1;
	FIELD RG_CSI0A_L1_T1AB_EQ_IS	: 2;
	FIELD RG_CSI0A_L1_T1AB_EQ_BW	: 2;
	FIELD RG_CSI0A_L1_T1AB_EQ_SRA	: 4;
	FIELD RG_CSI0A_L1_T1AB_EQ_SRB	: 4;
    } Bits;
    UINT32 Raw;
} REG_MIPI_RX_ANA1C_CSI0A, *PREG_MIPI_RX_ANA1C_CSI0A;

typedef PACKING union
{
    PACKING struct
    {
	FIELD RG_CSI0A_XX_T1CA_EQ_OS_CAL_EN : 1;
	FIELD RG_CSI0A_XX_T1CA_EQ_MON_EN : 1;
	FIELD RG_CSI0A_XX_T1CA_EQ_SCA	: 1;
	FIELD RG_CSI0A_XX_T1CA_EQ_SCB	: 1;
	FIELD RG_CSI0A_XX_T1CA_EQ_IS	: 2;
	FIELD RG_CSI0A_XX_T1CA_EQ_BW	: 2;
	FIELD RG_CSI0A_XX_T1CA_EQ_SRA	: 4;
	FIELD RG_CSI0A_XX_T1CA_EQ_SRB	: 4;
	FIELD RG_CSI0A_L2_T1BC_EQ_OS_CAL_EN : 1;
	FIELD RG_CSI0A_L2_T1BC_EQ_MON_EN : 1;
	FIELD RG_CSI0A_L2_T1BC_EQ_SCA	: 1;
	FIELD RG_CSI0A_L2_T1BC_EQ_SCB	: 1;
	FIELD RG_CSI0A_L2_T1BC_EQ_IS	: 2;
	FIELD RG_CSI0A_L2_T1BC_EQ_BW	: 2;
	FIELD RG_CSI0A_L2_T1BC_EQ_SRA	: 4;
	FIELD RG_CSI0A_L2_T1BC_EQ_SRB	: 4;
    } Bits;
    UINT32 Raw;
} REG_MIPI_RX_ANA20_CSI0A, *PREG_MIPI_RX_ANA20_CSI0A;

typedef PACKING union
{
    PACKING struct
    {
	FIELD rsv_0			: 24;
	FIELD RG_CSI0A_RESERVE		: 8;
    } Bits;
    UINT32 Raw;
} REG_MIPI_RX_ANA24_CSI0A, *PREG_MIPI_RX_ANA24_CSI0A;

typedef PACKING union
{
    PACKING struct
    {
	FIELD RG_CSI0A_CPHY_T0_CDR_DIRECT_EN : 1;
	FIELD RG_CSI0A_CPHY_T0_CDR_AUTOLOAD_EN : 1;
	FIELD RG_CSI0A_CPHY_T0_CDR_LPF_CTRL : 2;
	FIELD rsv_4			: 16;
	FIELD RG_CSI0A_CPHY_T0_HSDET_SEL : 2;
	FIELD rsv_22			: 2;
	FIELD RG_CSI0A_CPHY_T0_CDR_MANUAL_EN : 1;
	FIELD rsv_25			: 7;
    } Bits;
    UINT32 Raw;
} REG_MIPI_RX_ANA28_CSI0A, *PREG_MIPI_RX_ANA28_CSI0A;

typedef PACKING union
{
    PACKING struct
    {
	FIELD RG_CSI0A_CPHY_T0_CDR_INIT_CODE : 5;
	FIELD rsv_5			: 3;
	FIELD RG_CSI0A_CPHY_T0_CDR_EARLY_CODE : 5;
	FIELD rsv_13			: 3;
	FIELD RG_CSI0A_CPHY_T0_CDR_LATE_CODE : 5;
	FIELD rsv_21			: 11;
    } Bits;
    UINT32 Raw;
} REG_MIPI_RX_ANA2C_CSI0A, *PREG_MIPI_RX_ANA2C_CSI0A;

typedef PACKING union
{
    PACKING struct
    {
	FIELD RG_CSI0A_CPHY_T0_CDR_AB_WIDTH : 5;
	FIELD rsv_5			: 3;
	FIELD RG_CSI0A_CPHY_T0_CDR_BC_WIDTH : 5;
	FIELD rsv_13			: 3;
	FIELD RG_CSI0A_CPHY_T0_CDR_CA_WIDTH : 5;
	FIELD rsv_21			: 3;
	FIELD RG_CSI0A_CPHY_T0_CDR_CK_DELAY : 5;
	FIELD rsv_29			: 3;
    } Bits;
    UINT32 Raw;
} REG_MIPI_RX_ANA30_CSI0A, *PREG_MIPI_RX_ANA30_CSI0A;

typedef PACKING union
{
    PACKING struct
    {
	FIELD RG_CSI0A_CPHY_T1_CDR_DIRECT_EN : 1;
	FIELD RG_CSI0A_CPHY_T1_CDR_AUTOLOAD_EN : 1;
	FIELD RG_CSI0A_CPHY_T1_CDR_LPF_CTRL : 2;
	FIELD rsv_4			: 16;
	FIELD RG_CSI0A_CPHY_T1_HSDET_SEL : 2;
	FIELD rsv_22			: 2;
	FIELD RG_CSI0A_CPHY_T1_CDR_MANUAL_EN : 1;
	FIELD rsv_25			: 7;
    } Bits;
    UINT32 Raw;
} REG_MIPI_RX_ANA34_CSI0A, *PREG_MIPI_RX_ANA34_CSI0A;

typedef PACKING union
{
    PACKING struct
    {
	FIELD RG_CSI0A_CPHY_T1_CDR_INIT_CODE : 5;
	FIELD rsv_5			: 3;
	FIELD RG_CSI0A_CPHY_T1_CDR_EARLY_CODE : 5;
	FIELD rsv_13			: 3;
	FIELD RG_CSI0A_CPHY_T1_CDR_LATE_CODE : 5;
	FIELD rsv_21			: 11;
    } Bits;
    UINT32 Raw;
} REG_MIPI_RX_ANA38_CSI0A, *PREG_MIPI_RX_ANA38_CSI0A;

typedef PACKING union
{
    PACKING struct
    {
	FIELD RG_CSI0A_CPHY_T1_CDR_AB_WIDTH : 5;
	FIELD rsv_5			: 3;
	FIELD RG_CSI0A_CPHY_T1_CDR_BC_WIDTH : 5;
	FIELD rsv_13			: 3;
	FIELD RG_CSI0A_CPHY_T1_CDR_CA_WIDTH : 5;
	FIELD rsv_21			: 3;
	FIELD RG_CSI0A_CPHY_T1_CDR_CK_DELAY : 5;
	FIELD rsv_29			: 3;
    } Bits;
    UINT32 Raw;
} REG_MIPI_RX_ANA3C_CSI0A, *PREG_MIPI_RX_ANA3C_CSI0A;

typedef PACKING union
{
    PACKING struct
    {
	FIELD RG_CSI0A_CPHY_FMCK_SEL	: 2;
	FIELD rsv_2			: 2;
	FIELD RG_CSI0A_ASYNC_OPTION	: 4;
	FIELD CSR_CSI0A_DPHY_L0_ASYNC_FIFO_CG_DIS : 1;
	FIELD CSR_CSI0A_DPHY_L1_ASYNC_FIFO_CG_DIS : 1;
	FIELD CSR_CSI0A_DPHY_L2_ASYNC_FIFO_CG_DIS : 1;
	FIELD rsv_11			: 1;
	FIELD CSR_CSI0A_DPHY_L0_DELAY_APPLY_SEL : 1;
	FIELD CSR_CSI0A_DPHY_L1_DELAY_APPLY_SEL : 1;
	FIELD CSR_CSI0A_DPHY_L2_DELAY_APPLY_SEL : 1;
	FIELD rsv_15			: 1;
	FIELD RG_CSI0A_CPHY_SPARE_REG	: 16;
    } Bits;
    UINT32 Raw;
} REG_MIPI_RX_ANA40_CSI0A, *PREG_MIPI_RX_ANA40_CSI0A;

typedef PACKING union
{
    PACKING struct
    {
	FIELD RGS_CSI0A_CDPHY_L0_T0AB_OS_CAL_CPLT : 1;
	FIELD RGS_CSI0A_CPHY_T0CA_OS_CAL_CPLT : 1;
	FIELD RGS_CSI0A_CPHY_T0BC_OS_CAL_CPLT : 1;
	FIELD RGS_CSI0A_CDPHY_L1_T1AB_OS_CAL_CPLT : 1;
	FIELD RGS_CSI0A_CPHY_T1CA_OS_CAL_CPLT : 1;
	FIELD RGS_CSI0A_CDPHY_L2_T1BC_OS_CAL_CPLT : 1;
	FIELD rsv_6			: 2;
	FIELD RGS_CSI0A_OS_CAL_CODE	: 8;
	FIELD rsv_16			: 16;
    } Bits;
    UINT32 Raw;
} REG_MIPI_RX_ANA48_CSI0A, *PREG_MIPI_RX_ANA48_CSI0A;

typedef PACKING union
{
    PACKING struct
    {
	FIELD CSR_CSI_CLK_MON		: 1;
	FIELD CSR_CSI_CLK_EN		: 1;
	FIELD rsv_2			: 6;
	FIELD CSR_CSI_MON_MUX		: 8;
	FIELD CSR_CSI_RST_MODE		: 2;
	FIELD rsv_18			: 6;
	FIELD CSR_SW_RST		: 4;
	FIELD rsv_28			: 4;
    } Bits;
    UINT32 Raw;
} REG_MIPI_RX_WRAPPER80_CSI0A, *PREG_MIPI_RX_WRAPPER80_CSI0A;

typedef PACKING union
{
    PACKING struct
    {
	FIELD CSI_DEBUG_OUT		: 32;
    } Bits;
    UINT32 Raw;
} REG_MIPI_RX_WRAPPER84_CSI0A, *PREG_MIPI_RX_WRAPPER84_CSI0A;

typedef PACKING union
{
    PACKING struct
    {
	FIELD CSR_SW_MODE_0		: 32;
    } Bits;
    UINT32 Raw;
} REG_MIPI_RX_WRAPPER88_CSI0A, *PREG_MIPI_RX_WRAPPER88_CSI0A;

typedef PACKING union
{
    PACKING struct
    {
	FIELD CSR_SW_MODE_1		: 32;
    } Bits;
    UINT32 Raw;
} REG_MIPI_RX_WRAPPER8C_CSI0A, *PREG_MIPI_RX_WRAPPER8C_CSI0A;

typedef PACKING union
{
    PACKING struct
    {
	FIELD CSR_SW_MODE_2		: 32;
    } Bits;
    UINT32 Raw;
} REG_MIPI_RX_WRAPPER90_CSI0A, *PREG_MIPI_RX_WRAPPER90_CSI0A;

typedef PACKING union
{
    PACKING struct
    {
	FIELD CSR_SW_VALUE_0		: 32;
    } Bits;
    UINT32 Raw;
} REG_MIPI_RX_WRAPPER94_CSI0A, *PREG_MIPI_RX_WRAPPER94_CSI0A;

typedef PACKING union
{
    PACKING struct
    {
	FIELD CSR_SW_VALUE_1		: 32;
    } Bits;
    UINT32 Raw;
} REG_MIPI_RX_WRAPPER98_CSI0A, *PREG_MIPI_RX_WRAPPER98_CSI0A;

typedef PACKING union
{
    PACKING struct
    {
	FIELD CSR_SW_VALUE_2		: 32;
    } Bits;
    UINT32 Raw;
} REG_MIPI_RX_WRAPPER9C_CSI0A, *PREG_MIPI_RX_WRAPPER9C_CSI0A;

typedef PACKING union
{
    PACKING struct
    {
	FIELD RG_CSI0A_CDPHY_L0_T0_SYNC_INIT_SEL : 1;
	FIELD RG_CSI0A_CDPHY_L0_T0_FORCE_INIT : 1;
	FIELD RG_CSI0A_DPHY_L1_SYNC_INIT_SEL : 1;
	FIELD RG_CSI0A_DPHY_L1_FORCE_INIT : 1;
	FIELD RG_CSI0A_CDPHY_L2_T1_SYNC_INIT_SEL : 1;
	FIELD RG_CSI0A_CDPHY_L2_T1_FORCE_INIT : 1;
	FIELD rsv_6			: 26;
    } Bits;
    UINT32 Raw;
} REG_MIPI_RX_ANAA4_CSI0A, *PREG_MIPI_RX_ANAA4_CSI0A;

typedef PACKING union
{
    PACKING struct
    {
	FIELD RG_CSI0A_CDPHY_L0_T0_BYTECK_INVERT : 1;
	FIELD RG_CSI0A_DPHY_L1_BYTECK_INVERT : 1;
	FIELD RG_CSI0A_CDPHY_L2_T1_BYTECK_INVERT : 1;
	FIELD RG_CSI0A_DPHY_HSDET_LEVEL_MODE_EN : 1;
	FIELD RG_CSI0A_OS_CAL_SEL	: 3;
	FIELD RG_CSI0A_DPHY_HSDET_DIG_BACK_EN : 1;
	FIELD RG_CSI0A_CDPHY_DELAYCAL_CK_SEL : 3;
	FIELD RG_CSI0A_OS_CAL_DIV	: 2;
	FIELD rsv_13			: 19;
    } Bits;
    UINT32 Raw;
} REG_MIPI_RX_ANAA8_CSI0A, *PREG_MIPI_RX_ANAA8_CSI0A;

// ----------------- mipi_rx_ana_cdphy_csi0a_reg Register Definition -------------------
typedef volatile struct /*0x11C8 0000*/
{
    REG_MIPI_RX_ANA00_CSI0A         MIPI_RX_ANA00_CSI0A; // 0000
    REG_MIPI_RX_ANA04_CSI0A         MIPI_RX_ANA04_CSI0A; // 0004
    REG_MIPI_RX_ANA08_CSI0A         MIPI_RX_ANA08_CSI0A; // 0008
    REG_MIPI_RX_ANA0C_CSI0A         MIPI_RX_ANA0C_CSI0A; // 000C
    REG_MIPI_RX_ANA10_CSI0A         MIPI_RX_ANA10_CSI0A; // 0010
    REG_MIPI_RX_ANA14_CSI0A         MIPI_RX_ANA14_CSI0A; // 0014
    REG_MIPI_RX_ANA18_CSI0A         MIPI_RX_ANA18_CSI0A; // 0018
    REG_MIPI_RX_ANA1C_CSI0A         MIPI_RX_ANA1C_CSI0A; // 001C
    REG_MIPI_RX_ANA20_CSI0A         MIPI_RX_ANA20_CSI0A; // 0020
    REG_MIPI_RX_ANA24_CSI0A         MIPI_RX_ANA24_CSI0A; // 0024
    REG_MIPI_RX_ANA28_CSI0A         MIPI_RX_ANA28_CSI0A; // 0028
    REG_MIPI_RX_ANA2C_CSI0A         MIPI_RX_ANA2C_CSI0A; // 002C
    REG_MIPI_RX_ANA30_CSI0A         MIPI_RX_ANA30_CSI0A; // 0030
    REG_MIPI_RX_ANA34_CSI0A         MIPI_RX_ANA34_CSI0A; // 0034
    REG_MIPI_RX_ANA38_CSI0A         MIPI_RX_ANA38_CSI0A; // 0038
    REG_MIPI_RX_ANA3C_CSI0A         MIPI_RX_ANA3C_CSI0A; // 003C
    REG_MIPI_RX_ANA40_CSI0A         MIPI_RX_ANA40_CSI0A; // 0040
    UINT32                          rsv_0044;         // 0044
    REG_MIPI_RX_ANA48_CSI0A         MIPI_RX_ANA48_CSI0A; // 0048
    UINT32                          rsv_004C[13];     // 004C..007C
    REG_MIPI_RX_WRAPPER80_CSI0A     MIPI_RX_WRAPPER80_CSI0A; // 0080
    REG_MIPI_RX_WRAPPER84_CSI0A     MIPI_RX_WRAPPER84_CSI0A; // 0084
    REG_MIPI_RX_WRAPPER88_CSI0A     MIPI_RX_WRAPPER88_CSI0A; // 0088
    REG_MIPI_RX_WRAPPER8C_CSI0A     MIPI_RX_WRAPPER8C_CSI0A; // 008C
    REG_MIPI_RX_WRAPPER90_CSI0A     MIPI_RX_WRAPPER90_CSI0A; // 0090
    REG_MIPI_RX_WRAPPER94_CSI0A     MIPI_RX_WRAPPER94_CSI0A; // 0094
    REG_MIPI_RX_WRAPPER98_CSI0A     MIPI_RX_WRAPPER98_CSI0A; // 0098
    REG_MIPI_RX_WRAPPER9C_CSI0A     MIPI_RX_WRAPPER9C_CSI0A; // 009C
    UINT32                          rsv_00A0;         // 00A0
    REG_MIPI_RX_ANAA4_CSI0A         MIPI_RX_ANAA4_CSI0A; // 00A4
    REG_MIPI_RX_ANAA8_CSI0A         MIPI_RX_ANAA8_CSI0A; // 00A8     
}mipi_rx_ana_cdphy_csi0a_reg_REGS, *Pmipi_rx_ana_cdphy_csi0a_reg_REGS;

#endif // __mipi_rx_ana_cdphy_csi0a_reg_REGS_H__
