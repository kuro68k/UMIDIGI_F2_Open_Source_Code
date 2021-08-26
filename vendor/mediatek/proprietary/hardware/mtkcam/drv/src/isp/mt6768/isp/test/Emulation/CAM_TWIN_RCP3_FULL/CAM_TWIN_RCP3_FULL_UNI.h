UNI_WRITE_REG(ptr,CAM_UNI_DMA_SOFT_RSTSTAT,0x1000f);
UNI_WRITE_REG(ptr,CAM_UNI_VERTICAL_FLIP_EN,0x8);
UNI_WRITE_REG(ptr,CAM_UNI_DMA_SOFT_RESET,0x8);
UNI_WRITE_REG(ptr,CAM_UNI_LAST_ULTRA_EN,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_SPECIAL_FUN_EN,0x1800000);
UNI_WRITE_REG(ptr,CAM_UNI_SPECIAL_FUN2_EN,0x8726);
UNI_WRITE_REG(ptr,CAM_UNI_EISO_BASE_ADDR,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_EISO_OFST_ADDR,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_EISO_DRS,0x1c0011);
UNI_WRITE_REG(ptr,CAM_UNI_EISO_XSIZE,0xff);
UNI_WRITE_REG(ptr,CAM_UNI_EISO_YSIZE,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_EISO_STRIDE,0x107e918);
UNI_WRITE_REG(ptr,CAM_UNI_EISO_CON,0x40000020);
UNI_WRITE_REG(ptr,CAM_UNI_EISO_CON2,0x20000d);
UNI_WRITE_REG(ptr,CAM_UNI_EISO_CON3,0x1c000e);
UNI_WRITE_REG(ptr,CAM_UNI_EISO_CON4,0x801f0017);
UNI_WRITE_REG(ptr,CAM_UNI_FLKO_BASE_ADDR,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_FLKO_OFST_ADDR,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_FLKO_DRS,0x800e0005);
UNI_WRITE_REG(ptr,CAM_UNI_FLKO_XSIZE,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_FLKO_YSIZE,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_FLKO_STRIDE,0x1019b41);
UNI_WRITE_REG(ptr,CAM_UNI_FLKO_CON,0x20000017);
UNI_WRITE_REG(ptr,CAM_UNI_FLKO_CON2,0x160000);
UNI_WRITE_REG(ptr,CAM_UNI_FLKO_CON3,0x160011);
UNI_WRITE_REG(ptr,CAM_UNI_FLKO_CON4,0x80060005);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_A_BASE_ADDR,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_A_OFST_ADDR,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_A_DRS,0x80370021);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_A_XSIZE,0x1abf);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_A_YSIZE,0xef1);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_A_STRIDE,0x1ac2);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_A_CON,0x2000003a);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_A_CON2,0x370015);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_A_CON3,0x340012);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_A_CON4,0x39000e);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_B_BASE_ADDR,0xd6fb4554);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_B_OFST_ADDR,0x357e54b7);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_B_DRS,0x82470bba);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_B_XSIZE,0xa9b4);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_B_YSIZE,0x9e2d);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_B_STRIDE,0x8d77);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_B_CON,0x90000e1e);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_B_CON2,0x9f50662);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_B_CON3,0x6a6039e);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_B_CON4,0x8b170d20);
UNI_WRITE_REG(ptr,CAM_UNI_RAWI_BASE_ADDR,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_RAWI_OFST_ADDR,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_RAWI_DRS,0x440041);
UNI_WRITE_REG(ptr,CAM_UNI_RAWI_XSIZE,0x281f);
UNI_WRITE_REG(ptr,CAM_UNI_RAWI_YSIZE,0xeef);
UNI_WRITE_REG(ptr,CAM_UNI_RAWI_STRIDE,0x80812823);
UNI_WRITE_REG(ptr,CAM_UNI_RAWI_CON,0x200000e2);
UNI_WRITE_REG(ptr,CAM_UNI_RAWI_CON2,0xc9002d);
UNI_WRITE_REG(ptr,CAM_UNI_RAWI_CON3,0x730059);
UNI_WRITE_REG(ptr,CAM_UNI_RAWI_CON4,0x3c0039);
UNI_WRITE_REG(ptr,CAM_UNI_DMA_ERR_CTRL,0x80000000);
UNI_WRITE_REG(ptr,CAM_UNI_EISO_ERR_STAT,0xffff0000);
UNI_WRITE_REG(ptr,CAM_UNI_FLKO_ERR_STAT,0xffff0000);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_A_ERR_STAT,0xd2fb0000);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_B_ERR_STAT,0x216e0000);
UNI_WRITE_REG(ptr,CAM_UNI_RAWI_ERR_STAT,0xffff0000);
UNI_WRITE_REG(ptr,CAM_UNI_DMA_DEBUG_ADDR,0x805e6bdd);
UNI_WRITE_REG(ptr,CAM_UNI_DMA_RSV1,0x7bcca204);
UNI_WRITE_REG(ptr,CAM_UNI_DMA_RSV2,0x6ea50118);
UNI_WRITE_REG(ptr,CAM_UNI_DMA_RSV3,0x165f2137);
UNI_WRITE_REG(ptr,CAM_UNI_DMA_RSV4,0xe1b55a9d);
UNI_WRITE_REG(ptr,CAM_UNI_DMA_RSV5,0xe5474aec);
UNI_WRITE_REG(ptr,CAM_UNI_DMA_RSV6,0xffffffff);
UNI_WRITE_REG(ptr,CAM_UNI_DMA_DEBUG_SEL,0xd2386a);
UNI_WRITE_REG(ptr,CAM_UNI_DMA_BW_SELF_TEST,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_DMA_FRAME_HEADER_EN,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_EISO_FH_BASE_ADDR,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_FLKO_FH_BASE_ADDR,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_A_FH_BASE_ADDR,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_B_FH_BASE_ADDR,0x8b07d988);
UNI_WRITE_REG(ptr,CAM_UNI_EISO_FH_SPARE_2,0x6a354f08);
UNI_WRITE_REG(ptr,CAM_UNI_EISO_FH_SPARE_3,0x8529d179);
UNI_WRITE_REG(ptr,CAM_UNI_EISO_FH_SPARE_4,0x8b82f1a9);
UNI_WRITE_REG(ptr,CAM_UNI_EISO_FH_SPARE_5,0xb4044f79);
UNI_WRITE_REG(ptr,CAM_UNI_EISO_FH_SPARE_6,0x4f3b1bf2);
UNI_WRITE_REG(ptr,CAM_UNI_EISO_FH_SPARE_7,0x229f2d54);
UNI_WRITE_REG(ptr,CAM_UNI_EISO_FH_SPARE_8,0xf38e24a7);
UNI_WRITE_REG(ptr,CAM_UNI_EISO_FH_SPARE_9,0x7abd491b);
UNI_WRITE_REG(ptr,CAM_UNI_EISO_FH_SPARE_10,0x64e7b416);
UNI_WRITE_REG(ptr,CAM_UNI_EISO_FH_SPARE_11,0x34b798c3);
UNI_WRITE_REG(ptr,CAM_UNI_EISO_FH_SPARE_12,0x7806c2f5);
UNI_WRITE_REG(ptr,CAM_UNI_EISO_FH_SPARE_13,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_EISO_FH_SPARE_14,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_EISO_FH_SPARE_15,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_EISO_FH_SPARE_16,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_FLKO_FH_SPARE_2,0x910a046a);
UNI_WRITE_REG(ptr,CAM_UNI_FLKO_FH_SPARE_3,0xa5865ca2);
UNI_WRITE_REG(ptr,CAM_UNI_FLKO_FH_SPARE_4,0x561c67e0);
UNI_WRITE_REG(ptr,CAM_UNI_FLKO_FH_SPARE_5,0x6fc8a666);
UNI_WRITE_REG(ptr,CAM_UNI_FLKO_FH_SPARE_6,0x1121d9c3);
UNI_WRITE_REG(ptr,CAM_UNI_FLKO_FH_SPARE_7,0x8f2da0f5);
UNI_WRITE_REG(ptr,CAM_UNI_FLKO_FH_SPARE_8,0x86affa2a);
UNI_WRITE_REG(ptr,CAM_UNI_FLKO_FH_SPARE_9,0x4db6829f);
UNI_WRITE_REG(ptr,CAM_UNI_FLKO_FH_SPARE_10,0x32bd5eb8);
UNI_WRITE_REG(ptr,CAM_UNI_FLKO_FH_SPARE_11,0x8530f172);
UNI_WRITE_REG(ptr,CAM_UNI_FLKO_FH_SPARE_12,0xf467400d);
UNI_WRITE_REG(ptr,CAM_UNI_FLKO_FH_SPARE_13,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_FLKO_FH_SPARE_14,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_FLKO_FH_SPARE_15,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_FLKO_FH_SPARE_16,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_A_FH_SPARE_2,0xbf011987);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_A_FH_SPARE_3,0x88904f14);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_A_FH_SPARE_4,0x2adea5ed);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_A_FH_SPARE_5,0xac833ab6);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_A_FH_SPARE_6,0xfcfcc06f);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_A_FH_SPARE_7,0xc7d9a355);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_A_FH_SPARE_8,0x48dff837);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_A_FH_SPARE_9,0x8ee2ad13);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_A_FH_SPARE_10,0x58040256);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_A_FH_SPARE_11,0x134ff4c3);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_A_FH_SPARE_12,0x4d54642);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_A_FH_SPARE_13,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_A_FH_SPARE_14,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_A_FH_SPARE_15,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_A_FH_SPARE_16,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_B_FH_SPARE_2,0x15ffff1);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_B_FH_SPARE_3,0x1ab628c2);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_B_FH_SPARE_4,0x7873bb42);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_B_FH_SPARE_5,0x4216547c);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_B_FH_SPARE_6,0xb7513153);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_B_FH_SPARE_7,0x7091b390);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_B_FH_SPARE_8,0x6eceeed4);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_B_FH_SPARE_9,0xcbd82353);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_B_FH_SPARE_10,0x1301c48e);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_B_FH_SPARE_11,0xd3ccd38b);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_B_FH_SPARE_12,0x184d7009);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_B_FH_SPARE_13,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_B_FH_SPARE_14,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_B_FH_SPARE_15,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_RSSO_B_FH_SPARE_16,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_EIS_A_PREP_ME_CTRL1,0xdab7270d);
UNI_WRITE_REG(ptr,CAM_UNI_EIS_A_PREP_ME_CTRL2,0xb270906c);
UNI_WRITE_REG(ptr,CAM_UNI_EIS_A_LMV_TH,0x7120712);
UNI_WRITE_REG(ptr,CAM_UNI_EIS_A_FL_OFFSET,0xc7e0486);
UNI_WRITE_REG(ptr,CAM_UNI_EIS_A_MB_OFFSET,0x46104c4);
UNI_WRITE_REG(ptr,CAM_UNI_EIS_A_MB_INTERVAL,0x9a60ec7);
UNI_WRITE_REG(ptr,CAM_UNI_EIS_A_GMV,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_EIS_A_ERR_CTRL,0x70010);
UNI_WRITE_REG(ptr,CAM_UNI_EIS_A_IMAGE_CTRL,0x8f693174);
UNI_WRITE_REG(ptr,CAM_UNI_EIS_B_PREP_ME_CTRL1,0x9a700120);
UNI_WRITE_REG(ptr,CAM_UNI_EIS_B_PREP_ME_CTRL2,0x7190e06d);
UNI_WRITE_REG(ptr,CAM_UNI_EIS_B_LMV_TH,0x7120712);
UNI_WRITE_REG(ptr,CAM_UNI_EIS_B_FL_OFFSET,0x4770678);
UNI_WRITE_REG(ptr,CAM_UNI_EIS_B_MB_OFFSET,0xa200b87);
UNI_WRITE_REG(ptr,CAM_UNI_EIS_B_MB_INTERVAL,0xf670be5);
UNI_WRITE_REG(ptr,CAM_UNI_EIS_B_GMV,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_EIS_B_ERR_CTRL,0x70010);
UNI_WRITE_REG(ptr,CAM_UNI_EIS_B_IMAGE_CTRL,0x3f721553);
UNI_WRITE_REG(ptr,CAM_UNI_FBC_FLKO_A_CTL1,0x93120022);
UNI_WRITE_REG(ptr,CAM_UNI_FBC_FLKO_A_CTL2,0x2c0e24);
UNI_WRITE_REG(ptr,CAM_UNI_FBC_EISO_A_CTL1,0x83100135);
UNI_WRITE_REG(ptr,CAM_UNI_FBC_EISO_A_CTL2,0x2f3869);
UNI_WRITE_REG(ptr,CAM_UNI_FBC_RSSO_A_CTL1,0x2b000126);
UNI_WRITE_REG(ptr,CAM_UNI_FBC_RSSO_A_CTL2,0x30316);
UNI_WRITE_REG(ptr,CAM_UNI_FBC_FLKO_B_CTL1,0xa513012c);
UNI_WRITE_REG(ptr,CAM_UNI_FBC_FLKO_B_CTL2,0x60f2c);
UNI_WRITE_REG(ptr,CAM_UNI_FBC_EISO_B_CTL1,0xde130036);
UNI_WRITE_REG(ptr,CAM_UNI_FBC_EISO_B_CTL2,0x22091b);
UNI_WRITE_REG(ptr,CAM_UNI_FBC_RSSO_B_CTL1,0x53020039);
UNI_WRITE_REG(ptr,CAM_UNI_FBC_RSSO_B_CTL2,0x1e0251);
UNI_WRITE_REG(ptr,CAM_UNI_FLK_A_CON,0x1);
UNI_WRITE_REG(ptr,CAM_UNI_FLK_A_OFST,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_FLK_A_SIZE,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_FLK_A_NUM,0x66);
UNI_WRITE_REG(ptr,CAM_UNI_FLK_B_CON,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_FLK_B_OFST,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_FLK_B_SIZE,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_FLK_B_NUM,0x66);
UNI_WRITE_REG(ptr,CAM_UNI_HDS_A_MODE,0x3);
UNI_WRITE_REG(ptr,CAM_UNI_HDS_B_MODE,0x3);
UNI_WRITE_REG(ptr,CAM_UNI_QBN3_A_MODE,0x12);
UNI_WRITE_REG(ptr,CAM_UNI_QBN3_B_MODE,0x1);
UNI_WRITE_REG(ptr,CAM_UNI_RSS_A_CONTROL,0x1ef0000);
UNI_WRITE_REG(ptr,CAM_UNI_RSS_A_IN_IMG,0xef01ac0);
UNI_WRITE_REG(ptr,CAM_UNI_RSS_A_OUT_IMG,0xef11ac0);
UNI_WRITE_REG(ptr,CAM_UNI_RSS_A_HORI_STEP,0x8000);
UNI_WRITE_REG(ptr,CAM_UNI_RSS_A_VERT_STEP,0x8000);
UNI_WRITE_REG(ptr,CAM_UNI_RSS_A_HORI_INT_OFST,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_RSS_A_HORI_SUB_OFST,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_RSS_A_VERT_INT_OFST,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_RSS_A_VERT_SUB_OFST,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_RSS_B_CONTROL,0x1ef0004);
UNI_WRITE_REG(ptr,CAM_UNI_RSS_B_IN_IMG,0xef01ac0);
UNI_WRITE_REG(ptr,CAM_UNI_RSS_B_OUT_IMG,0xef11ac0);
UNI_WRITE_REG(ptr,CAM_UNI_RSS_B_HORI_STEP,0x8000);
UNI_WRITE_REG(ptr,CAM_UNI_RSS_B_VERT_STEP,0x8000);
UNI_WRITE_REG(ptr,CAM_UNI_RSS_B_HORI_INT_OFST,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_RSS_B_HORI_SUB_OFST,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_RSS_B_VERT_INT_OFST,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_RSS_B_VERT_SUB_OFST,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_SGG3_A_PGN,0x10);
UNI_WRITE_REG(ptr,CAM_UNI_SGG3_A_GMRC_1,0x10080402);
UNI_WRITE_REG(ptr,CAM_UNI_SGG3_A_GMRC_2,0x804020);
UNI_WRITE_REG(ptr,CAM_UNI_SGG3_B_PGN,0x10);
UNI_WRITE_REG(ptr,CAM_UNI_SGG3_B_GMRC_1,0x10080402);
UNI_WRITE_REG(ptr,CAM_UNI_SGG3_B_GMRC_2,0x804020);
UNI_WRITE_REG(ptr,CAM_UNI_TOP_CTL,0x1);
UNI_WRITE_REG(ptr,CAM_UNI_TOP_MISC,0x10);
UNI_WRITE_REG(ptr,CAM_UNI_TOP_SW_CTL,0x222);
UNI_WRITE_REG(ptr,CAM_UNI_TOP_RAWI_TRIG,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_TOP_MOD_EN,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_TOP_DMA_EN,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_TOP_PATH_SEL,0x1100);
UNI_WRITE_REG(ptr,CAM_UNI_TOP_FMT_SEL,0x8000000a);
UNI_WRITE_REG(ptr,CAM_UNI_TOP_DMA_INT_EN,0x8000000e);
UNI_WRITE_REG(ptr,CAM_UNI_TOP_DMA_INT_STATUS,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_TOP_DMA_INT_STATUSX,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_TOP_DBG_SET,0x11a6);
UNI_WRITE_REG(ptr,CAM_UNI_TOP_DBG_PORT,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_TOP_DMA_CCU_INT_EN,0x8000000c);
UNI_WRITE_REG(ptr,CAM_UNI_TOP_DMA_CCU_INT_STATUS,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_TOP_MOD_DCM_DIS,0x100000cb);
UNI_WRITE_REG(ptr,CAM_UNI_TOP_DMA_DCM_DIS,0xf);
UNI_WRITE_REG(ptr,CAM_UNI_TOP_MOD_DCM_STATUS,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_TOP_DMA_DCM_STATUS,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_TOP_MOD_REQ_STATUS,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_TOP_DMA_REQ_STATUS,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_TOP_MOD_RDY_STATUS,0x300000dd);
UNI_WRITE_REG(ptr,CAM_UNI_TOP_DMA_RDY_STATUS,0xf);
UNI_WRITE_REG(ptr,CAM_UNI_UNP2_A_OFST,0x0);
UNI_WRITE_REG(ptr,CAM_UNI_UNP2_B_OFST,0x0);