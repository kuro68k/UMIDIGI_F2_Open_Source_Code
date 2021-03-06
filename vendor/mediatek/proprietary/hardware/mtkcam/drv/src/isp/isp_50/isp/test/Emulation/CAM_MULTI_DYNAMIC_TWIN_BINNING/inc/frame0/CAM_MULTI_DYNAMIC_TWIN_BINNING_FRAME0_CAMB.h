//ptr->writeReg(0x1004, 0x4304c078, CAM_B);           //CAM.CAM_B.DMA.CQ0I_BASE_ADDR
//ptr->writeReg(0x1020, 0x528bca00, CAM_B);           //CAM.CAM_B.DMA.IMGO_BASE_ADDR
//ptr->writeReg(0x1050, 0x56645c00, CAM_B);           //CAM.CAM_B.DMA.RRZO_BASE_ADDR
//ptr->writeReg(0x1080, 0x552c1000, CAM_B);           //CAM.CAM_B.DMA.AAO_BASE_ADDR
//ptr->writeReg(0x10b0, 0x563e3000, CAM_B);           //CAM.CAM_B.DMA.AFO_BASE_ADDR
//ptr->writeReg(0x10e0, 0x54943800, CAM_B);           //CAM.CAM_B.DMA.LCSO_BASE_ADDR
//ptr->writeReg(0x1110, 0x57cf9e00, CAM_B);           //CAM.CAM_B.DMA.UFEO_BASE_ADDR
//ptr->writeReg(0x1140, 0x5622fc00, CAM_B);           //CAM.CAM_B.DMA.PDO_BASE_ADDR
//ptr->writeReg(0x1170, 0x52a58200, CAM_B);           //CAM.CAM_B.DMA.BPCI_BASE_ADDR
//ptr->writeReg(0x11a0, 0xd7bdb2ea, CAM_B);           //CAM.CAM_B.DMA.CACI_BASE_ADDR
//ptr->writeReg(0x11d0, 0x56a8f800, CAM_B);           //CAM.CAM_B.DMA.LSCI_BASE_ADDR
//ptr->writeReg(0x1200, 0x621809b, CAM_B);            //CAM.CAM_B.DMA.LSC3I_BASE_ADDR
//ptr->writeReg(0x1230, 0x5704ba00, CAM_B);           //CAM.CAM_B.DMA.PDI_BASE_ADDR
//ptr->writeReg(0x1260, 0x53605200, CAM_B);           //CAM.CAM_B.DMA.PSO_BASE_ADDR
//ptr->writeReg(0x1290, 0x53e2ce00, CAM_B);           //CAM.CAM_B.DMA.LMVO_BASE_ADDR
//ptr->writeReg(0x12c0, 0x5142fc00, CAM_B);           //CAM.CAM_B.DMA.FLKO_BASE_ADDR
//ptr->writeReg(0x12f0, 0x5688ec00, CAM_B);           //CAM.CAM_B.DMA.RSSO_A_BASE_ADDR
//ptr->writeReg(0x1320, 0x57039c00, CAM_B);           //CAM.CAM_B.DMA.UFGO_BASE_ADDR
//ptr->writeReg(0x1404, 0x57098000, CAM_B);           //CAM.CAM_B.DMA.IMGO_FH_BASE_ADDR
//ptr->writeReg(0x1408, 0x51441e00, CAM_B);           //CAM.CAM_B.DMA.RRZO_FH_BASE_ADDR
//ptr->writeReg(0x140c, 0x5233b000, CAM_B);           //CAM.CAM_B.DMA.AAO_FH_BASE_ADDR
//ptr->writeReg(0x1410, 0x53f0f000, CAM_B);           //CAM.CAM_B.DMA.AFO_FH_BASE_ADDR
//ptr->writeReg(0x1414, 0x54709a00, CAM_B);           //CAM.CAM_B.DMA.LCSO_FH_BASE_ADDR
//ptr->writeReg(0x1418, 0x5790be00, CAM_B);           //CAM.CAM_B.DMA.UFEO_FH_BASE_ADDR
//ptr->writeReg(0x141c, 0x51a61200, CAM_B);           //CAM.CAM_B.DMA.PDO_FH_BASE_ADDR
//ptr->writeReg(0x1420, 0x56889600, CAM_B);           //CAM.CAM_B.DMA.PSO_FH_BASE_ADDR
//ptr->writeReg(0x1424, 0x509b3200, CAM_B);           //CAM.CAM_B.DMA.LMVO_FH_BASE_ADDR
//ptr->writeReg(0x1428, 0x556c9400, CAM_B);           //CAM.CAM_B.DMA.FLKO_FH_BASE_ADDR
//ptr->writeReg(0x142c, 0x506c4600, CAM_B);           //CAM.CAM_B.DMA.RSSO_A_FH_BASE_ADDR
//ptr->writeReg(0x1430, 0x56779800, CAM_B);           //CAM.CAM_B.DMA.UFGO_FH_BASE_ADDR
ptr->writeReg(0x0198, 0x566564f8, CAM_B);           //CAM.CAM_B.CQ.THR0_BASEADDR
ptr->writeReg(0x019c, 0x448, CAM_B);                //CAM.CAM_B.CQ.THR0_DESC_SIZE
ptr->writeReg(0x0194, 0x11, CAM_B);                 //CAM.CAM_B.CQ.THR0_CTL
ptr->writeReg(0x118c, 0x80000020, CAM_B);           //CAM.CAM_B.DMA.BPCI_CON
ptr->writeReg(0x11ec, 0x80000020, CAM_B);           //CAM.CAM_B.DMA.LSCI_CON
ptr->writeReg(0x0190, 0x111, CAM_B);                //CAM.CAM_B.CQ.EN
ptr->writeReg(0x1018, 0xe9000000, CAM_B);           //CAM.CAM_B.DMA.SPECIAL_FUN_EN
ptr->writeReg(0x0234, 0x1002, CAM_B);               //CAM.CAM_B.TG.VF_CON (add from camsys_star_0.c)