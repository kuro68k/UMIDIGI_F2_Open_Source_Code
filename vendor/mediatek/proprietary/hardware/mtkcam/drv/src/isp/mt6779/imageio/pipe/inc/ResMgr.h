#ifndef _RESMGR_H_
#define _RESMGR_H_

#include "isp_function_cam.h"
#include "ispio_stddef.h"
#include <mtkcam/drv/def/ICam_type.h>
#include <IPipe.h>
#include <ICamIOPipe.h>
#include <vector>



#define BIN_THRU_PUT        (2)
#define CLK_MARGIN_N        95
#define CLK_MARGIN_M        100
#define RESMGR_TWIN_NUM     (CAM_C-CAM_A)
#define DEFAULT_MIPI_PIXRATE    1000000

#define MAX_DCIF_RESOLUTION                 (5504*3096)
#define IS_THROUGHPUT_OVER(_thru, _clk)     ((MUINT64)_thru > ((MUINT64)_clk*CLK_MARGIN_N/CLK_MARGIN_M))


typedef enum{
    user_unknown,
    user_camio,
    user_sttio,
    user_camsvio,
    user_normalsvio,
}E_USER;


class ResMgr;

struct Res_Meter_IN
{
public:
    // tg
    MBOOL               bypass_tg;
    E_CamPixelMode      pix_mode_tg;
    MUINT32             img_crop_w;
    MUINT32             img_crop_h;
    MUINT32             raw_fps;     // fps. unit:fps x 10, 10 for 1fps,  1 for 0.1fps.
                                    // if bypass_tg=1, this represents rawi fps
    E_CAM_CTL_TG_FMT    SrcImgFmt;

    // rrz
    MBOOL               bypass_rrzo;
    MUINT32             rrz_out_w;

    MBOOL               offBin;     // 1: force to off bin
    MBOOL               offTwin;    // 1: force to off twin
    E_CamPattern        pattern;    //input data pattern
    //
    vector<MUINT32>     vClk;       //avail clk rate
    //
    MUINT32             MIPI_pixrate;   //unit: mhz.

    //
    NSImageio::NSIspio::E_CAMIO_SEN         SenNum;     //sensor number , this is for 3twin <-> 2twin
    //
    Res_Meter_IN()
    : bypass_tg(MTRUE)
    , pix_mode_tg(ePixMode_1)
    , img_crop_w(0)
    , img_crop_h(0)
    , raw_fps(10)
    , SrcImgFmt(TG_FMT_JPG)
    , bypass_rrzo(MTRUE)
    , rrz_out_w(0)
    , offBin(MFALSE)
    , offTwin(MFALSE)
    , pattern(eCAM_NORMAL)
    , MIPI_pixrate(DEFAULT_MIPI_PIXRATE)
    , SenNum(NSImageio::NSIspio::ECamio_1_SEN)
    {
        vClk.clear();
    }
};

struct Res_Meter_OUT
{
    // pixel mode of mux
    T_DLP                   dlp;

    // frontal binning
    MBOOL                   bin_en;

    // twin
    MBOOL                   isTwin;

    //
    MUINT32                 clk_level;      //clk level needed after twin's thru-put calculaton

    vector<ISP_HW_MODULE>   slave_module;

    //
    Res_Meter_OUT() : dlp()
    {
        bin_en = MFALSE;
        isTwin = MFALSE;
        clk_level = MFALSE;
        slave_module.clear();
    }
};

struct Res_Arbitor_In {
    MUINT32         mipi_rate;
    MUINT32         img_crop_w;
    MUINT32         img_crop_h;
    MUINT32         tg_fps;
    MUINT32         raw_fps;
    MUINT32         raw_out_w;
    MBOOL           off_bin;
    MBOOL           off_twin;
    E_CamPattern    pattern;

    vector<MUINT32>     vRawClks;

    Res_Arbitor_In()
    : mipi_rate(DEFAULT_MIPI_PIXRATE)
    , img_crop_w(0)
    , img_crop_h(0)
    , tg_fps(10)
    , raw_fps(10)
    , raw_out_w(0)
    , off_bin(MFALSE)
    , off_twin(MFALSE)
    , pattern(eCAM_NORMAL)
    {
        vRawClks.clear();
    }
};

struct Res_Arbitor_Out {
    MBOOL           needFullFpsSVRawDump;
    MBOOL           isOffTwin;
    MUINT32         clk_level;
    ResMgr          *resmgr_cam;
    ResMgr          *resmgr_sv;
};



class ResMgr{
public:
    ResMgr(){m_hwModule = CAM_MAX;}
    virtual ~ResMgr(){}

    //booking master cam resource & get working obj (avtive)
    static ResMgr*          Res_Attach(E_USER user,ISP_HW_MODULE master,char Name[32]);
    //booking cam resource & get working obj, which isn't needed to be specified by user. user can get module by ResMgr::Res_GetModule() (passive)
    static ResMgr*          Res_Attach(E_USER user,char Name[32],MUINT32 input);

    static ResMgr*          Res_Attach(E_USER user,MUINT32 mMipiPixrate,char Name[32],vector<E_INPUT>& InOutPut);

    static MBOOL            Res_AattachArbitor(Res_Arbitor_In& inParams, Res_Arbitor_Out &outParam, char Name[32]);

    //release master cam's resource, including resources which r occupied by master cam
    virtual MBOOL           Res_Detach(void) = 0;
    //based on current throughput from input source , output pipeline's throuput configuration, like twin/bin/isp_clk ...etc
    virtual MBOOL           Res_Meter(const Res_Meter_IN& cfgInParam, Res_Meter_OUT &cfgOutParam) = 0;
    //get current asigned module
            ISP_HW_MODULE   Res_GetModule(void);
    virtual MINT32          Res_Recursive(V_CAM_THRU_PUT* pcfgIn) = 0;       //for ispclk level , re-calculation for twin's overhead
protected:
    ISP_HW_MODULE   m_hwModule;

};



#endif

