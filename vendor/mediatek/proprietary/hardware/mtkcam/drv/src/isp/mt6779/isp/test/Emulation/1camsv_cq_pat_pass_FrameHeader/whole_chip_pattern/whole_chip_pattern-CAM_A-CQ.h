ptr->writeReg(0x0208, 0x58af6800, CAM_A);       //TOP.CAM_CAM_1.CAM_A.CAMCQ_R1.CAMCQ_CQ_THR0_BASEADDR
ptr->writeReg(0x020c, 0x600, CAM_A);            //TOP.CAM_CAM_1.CAM_A.CAMCQ_R1.CAMCQ_CQ_THR0_DESC_SIZE
ptr->writeReg(0x0204, 0x11, CAM_A);             //TOP.CAM_CAM_1.CAM_A.CAMCQ_R1.CAMCQ_CQ_THR0_CTL
ptr->writeReg(0x41e8, 0x20000040, CAM_A);       //TOP.CAM_CAM_1.CAM_A.BPCI_R1.BPCI_CON
ptr->writeReg(0x42a8, 0x10000040, CAM_A);       //TOP.CAM_CAM_1.CAM_A.LSCI_R1.LSCI_CON
ptr->writeReg(0x0200, 0x13, CAM_A);             //TOP.CAM_CAM_1.CAM_A.CAMCQ_R1.CAMCQ_CQ_EN
ptr->writeReg(0x4018, 0xc0000000, CAM_A);       //TOP.CAM_CAM_1.CAM_A.CAMDMATOP1_R1.CAMDMATOP1_SPECIAL_FUN_EN1
