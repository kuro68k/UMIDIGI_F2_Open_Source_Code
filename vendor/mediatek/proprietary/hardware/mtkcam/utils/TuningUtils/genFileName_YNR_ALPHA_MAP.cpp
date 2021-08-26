#include <mtkcam/utils/TuningUtils/FileDumpNamingRule.h>
#include <mtkcam/utils/TuningUtils/CommonRule.h>

namespace NSCam {
namespace TuningUtils {

void genFileName_YNR_ALPHA_MAP(
    char *pFilename,
    int nFilename,
    const FILE_DUMP_NAMING_HINT *pHint,
    const char *pUserString)
{
    const char *strIspProfileName = NULL;
    if (pUserString == NULL) pUserString = "";
    int t;
    char *ptr = pFilename;
    if (property_get_int32("vendor.debug.enable.normalAEB", 0))
        t = MakePrefix(ptr, nFilename, pHint->UniqueKey, pHint->FrameNo, pHint->RequestNo, pHint->EvValue);
    else
    t = MakePrefix(ptr, nFilename, pHint->UniqueKey, pHint->FrameNo, pHint->RequestNo);
    ptr += t;
    nFilename -= t;

    t = snprintf(ptr, nFilename, "-%s", SENSOR_DEV_TO_STRING(pHint->SensorDev));
    ptr += t;
    nFilename -= t;
    
    if (*(pHint->additStr) != '\0') {
        t = snprintf(ptr, nFilename, "-%s", pHint->additStr);
        ptr += t;
        nFilename -= t;
    }

    if (*pUserString != '\0') {
        t = snprintf(ptr, nFilename, "-%s", pUserString);
        ptr += t;
        nFilename -= t;
    }

    strIspProfileName = getIspProfileName((NSIspTuning::EIspProfile_T)pHint->IspProfile);
    if (strIspProfileName)
    {
        t = snprintf(ptr, nFilename, "-%s", strIspProfileName);
    } else {
        t = snprintf(ptr, nFilename, "-profile");
    }
    ptr += t;
    nFilename -= t;

    t = snprintf(ptr, nFilename, ".dmgi");
    ptr += t;
    nFilename -= t;
}

} //namespace FileDump
} //namespace NSCam
