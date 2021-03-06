#ifndef _FROMALGO_DEBUG_AF_PARAM_H_
#define _FROMALGO_DEBUG_AF_PARAM_H_

// --- AF debug info ---
#define AF_EXIF_VERSION         (8)
#define AF_EXIF_SUBVERSION      (0)
#define AF_DEBUG_TAG_VERSION_DP ((AF_EXIF_SUBVERSION << 16) | AF_EXIF_VERSION)
#define AF_DEBUG_TAG_SIZE       (2048)

#define DBG_AF_PARAM_REVISION   8042003
#define DBG_PD_PARAM_REVISION   7031001

typedef struct
{
    MUINT32 u4FieldID;
    MUINT32 u4FieldValue;
}  EXT_AAA_DEBUG_TAG_T;

typedef struct
{
    EXT_AAA_DEBUG_TAG_T Tag[AF_DEBUG_TAG_SIZE];

} EXT_AF_DEBUG_INFO_T;
#define AF_DEBUG_INFO_T         EXT_AF_DEBUG_INFO_T

typedef enum
{
    //header file version
    // BEGIN_OF_EXIF_TAG
    VER_EXIF,                  // exif version
    VER_CORE,                  // af_algo_core
    VER_IP,                    // af_algo_ip
    VER_PARAM,                 // af_param
    VER_IF,                    // af_algo_if
    VER_EXIF_H,                // this file

    //handle AF count, +1 each time call af algorithm
    HANDLEAF_CNT,
    HANDLEAF_EXIF_TIME,

    //Contrast AF search
    CAF_IDX,                   // search index
    CAF_POS,                   // search vcm pos
    CAF_FV_MSB,                // FV (MSB)
    CAF_FV_LSB,                // FV (LSB)
    CAF_MIN_L_IDX,             // idx for min FV in inf side
    CAF_MAX_IDX,               // idx for max FV
    CAF_MIN_R_IDX,             // idx for min FV in macro side
    CAF_MAIN_THRES,            // current main threshold FV
    CAF_SUB_THRES,             // current sub threshold FV
    CAF_FIN_3P,                // finish: Peak found from 3 points
    CAF_FAIL,                  // can not find peak
    CAF_FIN_BND,               // finish: Full search case or boundry
    CAF_FOCUS_POS,             // focused lens position
    CAF_TYPE,                  // Contrast AF or Hybrid AF
    CAF_MFV_MSB,
    CAF_MFV_LSB,
    CAF_MFV,
    CAF_EXT_TYPE,
    CAF_CFG_NUM,

    FOCUS_POS,                 // focused lens position

    //NVRAM paramter
    NV_TUNING_SN,
    NV_MAIN_THRES,             // main threshold (%)
    NV_SUB_THRES,              // sub threshold (%)
    NV_STEP_L,                 // lnfinity boundary in AF table
    NV_STEP_H,                 // macro boundary in AF table
    NV_OTP_INF,                // OTP vaule of infinity
    NV_OTP_MAC,                // OTP value of macro
    NV_DAMPING_COMP,           // damping compensation enable
    NV_FV_EXTRACT,             // fv extraction enable
    NV_ZE_CALI_RATIO,          // zoom effect cali data
    NV_FDWIN_RATIO,            // face win for af ratio
    NV_PL_RTOP,                // pl tuning point -top ratio
    NV_PL_SA,                  // pl tuning point -sa
    NV_PL_SR,                  // pl tuning point -sr
    NV_PL_BA,                  // pl tuning point -ba
    NV_PL_BR,                  // pl tuning point -br
    NV_PL_CTRLBIT,             // pl control bit
    NV_PL_ABN_GSUM,
    NV_PL_ABN_SCNT,
    NV_HB_PL_GSUM,
    NV_HB_PL_SCNT,
    NV_HB_PL_SCNT_MIN,
    NV_HB_PL_SCNT_TH,
    NV_HB_PL_ABN_GSUM,
    NV_HB_PL_ABN_SCNT,
    NV_TEMP_ERROR,
    //NVRAM at eng/userdebug load
    NV_HYBRID,
    NV_PD,
    NV_LD,
    NV_SD,
    NV_FD,
    NV_PL,
    NV_AFV3,
    NV_ZE,
    NV_MZ,
    NV_SC_ACCE,
    NV_SC_GYRO,
    NV_INF_IDX,
    NV_MAC_IDX,
    NV_FAIL_CNT,
    NV_FAIL_POS,
    NV_FM_WAIT,
    NV_CAF_W,
    NV_CAF_H,
    NV_EN_DAMP,
    NV_EN_STR_BND,
    NV_EN_SEL_DIR,
    NV_EN_FPS_RAM,
    NV_EN_LEFT_SH,

    //HB PL debug
    HB_PL_FV,
    HB_PL_SCNT,
    HB_PL_WAREA,
    HB_PL_WFV,
    HB_PL_GSUM,
    HB_PL_FVMAX,

    //Scene information
    SCN_AFMODE,                // 1: AFS, 2: AFC, 3: Macro, 4: Inf, 5: MF, 6: Cal, 7: Fullscan
    SCN_ZSD,                   // is ZSD mode
    SCN_ISO,                   // ISO value
    SCN_WIN_X,                 // AF window location  - left
    SCN_WIN_Y,                 // AF window location  - top
    SCN_WIN_W,                 // AF window location  - width
    SCN_WIN_H,                 // AF window location  - height
    SCN_STEP,                  // search steps
    SCN_POST_COMP,             // posture compensation offset
    SCN_HW_TH_H0,              // af hardware threshold
    SCN_HW_TH_H1,              // af hardware threshold
    SCN_HW_TH_V,               // af hardware threshold
    SCN_FV_DC,                 // DC focus value
    SCN_MIN_TH,                // minimum threshold
    SCN_ZOOM_W,                // image width after zoom
    SCN_ZOOM_H,                // image higght after zoom
    SCN_ZOOM_X,                // image left,top position after zoom
    SCN_ZOOM_Y,                // image left,top position after zoom

    //Face information
    FD_STATUS,                 // 0: no face, 1: face detected

    //fine peak
    FP_IDX,                    // findpeak idx
    FP_POS,                    // findpeak pos
    FP_VLU,                    // findpeak vlu
    FP_FOCUS_POS,
    FP_EXT_FITCNT,
    FP_EXT_BIN,

    //Damping compensation
    DAMP_DIR,                  // damping comp dir
    DAMP_STEP,                 // damping comp step
    DAMP_COMP_VLU,             // damping comp vlu
    DAMP_PRERUN,               // prerun
    DAMP_FRAME_TIME,           // frametime
    DAMP_SIDX,                 // shutter idx
    DAMP_SRATIO,               // shutter ratio

    //for debug paser UI
    DP_AFMODE,                 // DP check continue AF or full scan
    DP_WIN_X,                  // AF window location  - left
    DP_WIN_Y,                  // AF window location  - top
    DP_WIN_W,                  // AF window location  - width
    DP_WIN_H,                  // AF window location  - height
    DP_ZOOM_X,
    DP_ZOOM_Y,
    DP_ZOOM_W,
    DP_ZOOM_H,
    DP_IDX,                    // search idx
    DP_POS,                    // lens position
    DP_VLU,                    // focus value
    DP_FOCUS_POS,              // focused lens position
    DP_FIN_3P,                 // focus OK, green window
    DP_FAIL,                   // focus Fail, red window
    DP_MZ_WIN_W,
    DP_MZ_WIN_H,
    DP_MZ_WIN_X,
    DP_MZ_WIN_Y,
    DP_MZ_WIN_NUM,
    DP_MZ_WIN_RES,
    DP_SCAN_START,             // full scan start
    DP_SCAN_STEP,              // full scan step


    //PD Algo
    PDAG_ROI_X,
    PDAG_ROI_Y,
    PDAG_ROI_W,
    PDAG_ROI_H,
    PDAG_CUR_POS,
    PDAG_TAR_POS,
    PDAG_PDVAL,
    PDAG_CONF,
    PDAG_CORR,
    PDAG_EVAL1,
    PDAG_EVAL2,
    PDAG_EVAL3,
    PDAG_EVAL4,
    PDAG_CONV,
    PDAG_CALI_STEP1_RATIO,
    PDAG_CALI_STEP2_CONV,
    PDAG_CALI_STEP2_POS,
    PDAG_CALI_STEP3_POS,
    PDAG_WIN_ORIENTATION,
    PDAG_INFO_0,
    PDAG_INFO_1,
    PDAG_INFO_2,
    PDAG_INFO_3,
    PDAG_INFO_4,

    //Hybrid AF Search
    HB_TRACK,
    HB_MOV,                     // hybrid mvoing state and count
    HB_FS,                      // hybrid fine search state and count
    HB_CUR_POS,                 // current pos
    HB_TAR_POS,                 // target pos
    HB_DES_POS,                 // des pos
    HB_FS_FV,                   // FV for fine search
    HB_FS_WFV,                // WFV for fine search
    HB_SC_FV,                   // FV for scene change
    //HB_FS_FV_MAX,
    //HB_FS_GSum,
    //HB_FS_Scnt,
    //HB_FS_Warea,
    HB_PD_VLU,                  // PD(Laser) value
    HB_PD_CONF,                 // PD(Laser) confidence
    HB_STA_CHG,                 // state change, next state
    HB_STA_CHG_WHY,             // why state change
    HB_FIN_3P,                  // finish: Peak found from 3 points
    HB_FAIL,                    // can not find peak
    HB_LASER_DIST,              // Laser distance
    HB_SOURCE,
    HB_SUB_WIN,
    HB_SUB_WIN_X,
    HB_SUB_WIN_Y,
    HB_SUB_WIN_W,
    HB_SUB_WIN_H,

    //full scan mode and damping calibration
    FULL_AFMODE,
    FULL_START,                 // fullscan start position
    FULL_STEP,                  // fullscan step interval
    FULL_NUM,
    FULL_OTP_MAC,
    FULL_OTP_INF,
    FULL_FOCUS_POS,
    FULL_ISO,
    FULL_FRAME_TIME,
    FULL_SHUTTER,
    FULL_POS,
    FULL_IDX,
    FULL_DAMP_VLU,
    FULL_FV_MSB,
    FULL_FV_LSB,
    FULL_DISTANCE,

    //Point Light
    PL_YLU,
    PL_SEL,
    PL_STATE,
    PL_RATE,
    PL_MINAREA,
    PL_FIN_BND,

    //frame information
    FM_STATUS,                  // AF status
    FM_GYRO,                    // Gyro value
    FM_ACCE_XYZ,                // Accelerator value, x/y/z axis
    FM_G_SUM_LV,                // G sum/LV from AE algorithm
    FM_GHIST,                   // G histogram
    FM_TIME_SHUTTER,            // frame time
    FM_FD_XY,                   // Face location
    FM_FD_WH,                   // Face location
    FM_FD_COUNT,                // Face count/none count/status
    FM_SCENE_CHG_STB,           // Scene change/stable
    FM_PD,
    FM_LD,
    FM_SD,
    FM_WAREA,
    FM_FVW,
    FM_FVW_CNT,
    FM_FV_MAX,

    //manual focus
    MF_FOCUS_POS,
    MF_FV_MSB,
    MF_FV_LSB,

    //af_mgr
    MGR_TG_W,
    MGR_TG_H,
    MGR_BIN_W,
    MGR_BIN_H,
    MGR_CROP_WIN_X,
    MGR_CROP_WIN_Y,
    MGR_CROP_WIN_W,
    MGR_CROP_WIN_H,
    MGR_DZ_CFG,
    MGR_DZ_FACTOR,
    MGR_FOCUSING_WIN_X,
    MGR_FOCUSING_WIN_Y,
    MGR_FOCUSING_WIN_W,
    MGR_FOCUSING_WIN_H,
    MGR_OTFD_WIN_X,
    MGR_OTFD_WIN_Y,
    MGR_OTFD_WIN_W,
    MGR_OTFD_WIN_H,
    MGR_CENTER_WIN_X,
    MGR_CENTER_WIN_Y,
    MGR_CENTER_WIN_W,
    MGR_CENTER_WIN_H,
    MGR_CMD_WIN_X,
    MGR_CMD_WIN_Y,
    MGR_CMD_WIN_W,
    MGR_CMD_WIN_H,
    MGR_PD_BUF_TYPE,
    MGR_PD_SEN_TYPE,
    MGR_LASER_VAL,
    MGR_FOCUSING_POS,
    MGR_FOCUSING_DST,
    MGR_CURRENT_POS,
    MGR_TS,
    MGR_GYRO_SENSOR_X,
    MGR_GYRO_SENSOR_Y,
    MGR_GYRO_SENSOR_Z,

    SEEK_RESERVE00,
    SEEK_RESERVE01,
    SEEK_RESERVE02,
    SEEK_RESERVE03,
    SEEK_RESERVE04,
    SEEK_RESERVE05,
    SEEK_PTRSTR, // af_search_EXIFType start
    SEEK_TIMEINFO,
    SEEK_CONFIG,
    SEEK_SEARCH,
    SEEK_INFO,
    SEEK_RESERVE11,
    SEEK_RESERVE12,
    SEEK_RESERVE13,
    SEEK_RESERVE14,
    SEEK_RESERVE15,
    SEEK_RESERVE16,
    SEEK_RESERVE17,
    SEEK_RESERVE18,
    SEEK_RESERVE19,
    SEEK_INPUTFLAGS,
    SEEK_DACSEQ,

    CALI_TEMP_START,
    CALI_TEMP_END,
    CALI_TEMP_FOCUS,
    CALI_FOCUS_POS,
    CALI_AFTIME,

    ADP_EXP_BEFORE,
    ADP_EXP_MING,
    ADP_EXP_AFTER,
    ADP_EQ_POS,

    //Dual Cam
    DUAL_SYNC_MODE,
    DUAL_SYNC_STATUS,
    DUAL_SYNC_M_OTP_INF,
    DUAL_SYNC_M_OTP_MID,
    DUAL_SYNC_M_OTP_MAC,
    DUAL_SYNC_S_OTP_INF,
    DUAL_SYNC_S_OTP_MAC,
    DUAL_SYNC_M_POS,
    DUAL_SYNC_S_POS,
    DUAL_SYNC_ISSAFRUN,
    DUAL_SYNC_ISSCAFTRG,
    DUAL_SYNC_M_FAREA_X,
    DUAL_SYNC_M_FAREA_Y,
    DUAL_SYNC_SAFRUNPOS,
    DUAL_SYNC_M_AFCSTATUS,
    DUAL_SYNC_S_AFCSTATUS,
    DUAL_SYNC_AE_STABLE,
    DUAL_SYNC_FV_STABLE,

    //SCD6.0 20181005
    FM_SCD_CHGSTB,
    FM_HSC_STATUS,
    FM_SCD_STATUS,
    FM_SCD_TRIGGER,
    FM_SCD_RSVD_0,
    FM_SCD_RSVD_1,
    FM_SCD_RSVD_2,
    FM_SCD_RSVD_3,
    FM_SCD_RSVD_4,
    FM_SCD_RSVD_5,
    FM_SCD_RSVD_6,
    FM_SCD_RSVD_7,

    //FDAF
    FDAF_TRIG_INFO,
    FDAF_FDLM_INFO,
    FDAF_ROI_INFO,
    FDAF_ROI_TYPE,
    FDAF_ROI_XY,
    FDAF_ROI_WH,
    FDAF_ROI_FV,
    FDAF_ROI_RSV,

    // END_OF_EXIF_TAG
} AF_DEBUG_TAG_T;

#endif
