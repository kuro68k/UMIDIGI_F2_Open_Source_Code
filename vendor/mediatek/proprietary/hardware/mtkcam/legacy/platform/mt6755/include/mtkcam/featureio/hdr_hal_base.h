/********************************************************************************************
 *     LEGAL DISCLAIMER
 *
 *     (Header of MediaTek Software/Firmware Release or Documentation)
 *
 *     BY OPENING OR USING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 *     THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE") RECEIVED
 *     FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON AN "AS-IS" BASIS
 *     ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, EXPRESS OR IMPLIED,
 *     INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR
 *     A PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY
 *     WHATSOEVER WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 *     INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK
 *     ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
 *     NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S SPECIFICATION
 *     OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
 *
 *     BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE LIABILITY WITH
 *     RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION,
 *     TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.
 ************************************************************************************************/
#ifndef _HDR_HAL_BASE_H_
#define _HDR_HAL_BASE_H_

#include <mtkcam/common.h>
#include <mtkcam/algorithm/libhdr/MTKHdr.h>

/**************************************************************************
 *                      D E F I N E S / M A C R O S                       *
 **************************************************************************/
#define NUM_MAX_INPUT_FRAME   3

/**************************************************************************
 *     E N U M / S T R U C T / T Y P E D E F    D E C L A R A T I O N     *
 **************************************************************************/
typedef struct
{
	// For HDR Drv Init.
    MUINT32 u4OutputFrameNum;	// image_num;
    MUINT32 u4FinalGainDiff0;	// ev_gain1;
    MUINT32 u4FinalGainDiff1;	// ev_gain3;
    MUINT32 u4ImgW;				// image_width;
    MUINT32 u4ImgH;				// image_height;
    MUINT32 u4TargetTone;		// target_tone;

    MUINT8* pSourceImgBufAddr[NUM_MAX_INPUT_FRAME];	// image_addr[3]; // input image address

    // For Sensor Infor
    MUINT32 u4SensorType;

    // For HW isp gamma
    MINT32* pIsp_gamma;

} HDR_PIPE_INIT_INFO, *P_HDR_PIPE_INIT_INFO;


typedef struct
{
    MUINT32 eHdrRound;  //kidd modify to enum
    MUINT32 u4SourceImgWidth;
    MUINT32 u4SourceImgHeight;
    MUINT8* pSourceImgBufAddr[NUM_MAX_INPUT_FRAME];	// source_image_addr[3]; // source image address
    MUINT8* pSmallImgBufAddr[NUM_MAX_INPUT_FRAME];	// small_image_addr[3]; // small image address
    MUINT32 manual_PreProcType;
} HDR_PIPE_CONFIG_PARAM, *P_HDR_PIPE_CONFIG_PARAM;

typedef struct
{
    MUINT16 u2SEImgWidth;		// se_image_width;
    MUINT16 u2SEImgHeight;		// se_image_height;
    MUINT8* pSEImgBufAddr[NUM_MAX_INPUT_FRAME];	// se_image_addr;
} HDR_PIPE_SE_INPUT_INFO, *P_HDR_PIPE_SE_INPUT_INFO;

typedef struct
{
    MUINT16	u2SmallImgW;			// Width;	// input image width
    MUINT16	u2SmallImgH;			// Height;	// input image height
    MUINT8* pSmallImgBufAddr[NUM_MAX_INPUT_FRAME];	// ImgAddr;
    MUINT8* pWorkingBuffer;

} HDR_PIPE_FEATURE_EXTRACT_INPUT_INFO, *P_HDR_PIPE_FEATURE_EXTRACT_INPUT_INFO;

typedef HDR_BMAP_BUFFER HDR_PIPE_BMAP_BUFFER;

typedef WEIGHT_TBL_INFO HDR_PIPE_WEIGHT_TBL_INFO;

typedef HDR_RESULT_STRUCT HDR_PIPE_HDR_RESULT_STRUCT;

/**************************************************************************
 *                 E X T E R N A L    R E F E R E N C E S                 *
 **************************************************************************/

/**************************************************************************
 *        P U B L I C    F U N C T I O N    D E C L A R A T I O N         *
 **************************************************************************/

/**************************************************************************
 *                   C L A S S    D E C L A R A T I O N                   *
 **************************************************************************/
class HdrHalBase {
public:
    static HdrHalBase* createInstance();
    virtual MBOOL init(void *pInitInData) = 0;
    virtual MBOOL uninit() = 0;
    virtual ~HdrHalBase() {};

public:
    virtual MBOOL Do_Normalization(void) = 0;
    virtual MBOOL Do_SE(HDR_PIPE_SE_INPUT_INFO& rHdrPipeSEInputInfo) = 0;
    virtual MBOOL Do_FeatureExtraction(HDR_PIPE_FEATURE_EXTRACT_INPUT_INFO& rHdrPipeFeatureExtractInputInfo) = 0;
    virtual MBOOL Do_Alignment(void) = 0;
    virtual MBOOL Do_Fusion(HDR_PIPE_WEIGHT_TBL_INFO** pprBlurredWeightMapInfo) = 0;
    virtual MBOOL WeightingMapInfoGet(HDR_PIPE_WEIGHT_TBL_INFO** pprWeightMapInfo) = 0;
    virtual MBOOL WeightingMapInfoSet(HDR_PIPE_BMAP_BUFFER* pBmapInfo) = 0;
    virtual MBOOL ResultBufferSet(MUINT8* bufferAddr, MUINT32 bufferSize) = 0;
    virtual MBOOL HdrCroppedResultGet(HDR_PIPE_HDR_RESULT_STRUCT& rHdrCroppedResult) = 0;
	virtual MBOOL HdrSmallImgBufSet(HDR_PIPE_CONFIG_PARAM& rHdrPipeConfigParam) = 0;
    virtual MBOOL HdrWorkingBufSet(MUINT8* u4BufAddr, MUINT32 u4BufSize) = 0;
    virtual MUINT32 HdrWorkingBuffSizeGet(void) = 0;
	virtual void QuerySmallImgResolution(MUINT32& ru4Width, MUINT32& ru4Height) = 0;
    virtual void QuerySEImgResolution(MUINT32& ru4Width, MUINT32& ru4Height) = 0;
    virtual MUINT32 SEImgBuffSizeGet(void) = 0;
    virtual void SaveHdrLog(MUINTPTR u4RunningNumber) = 0;
};

#endif	// _HDR_HAL_BASE_H_

