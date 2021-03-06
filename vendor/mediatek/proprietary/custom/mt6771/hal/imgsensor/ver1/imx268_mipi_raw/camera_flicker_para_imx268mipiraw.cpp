//[Sensor]
//name = imx268mipiraw
//
//[Preview]
//read_freq = 531000000
//pixel_line = 6024
//column_length = 1983
//
//[Video]
//read_freq = 600000000
//pixel_line = 6024
//column_length = 2983
//
//[Capture]
//read_freq = 600000000
//pixel_line = 6024
//column_length = 3991
//
//[Video1]
//read_freq = 600000000
//pixel_line = 6024
//column_length = 711
//
//[Video2]
//read_freq = 531000000
//pixel_line = 6024
//column_length = 711
#include <utils/Log.h>
#include <fcntl.h>
#include <math.h>

#include "camera_custom_nvram.h"
#include "camera_custom_sensor.h"
#include "image_sensor.h"
#include "kd_imgsensor_define.h"
#include "camera_AE_PLineTable_imx268mipiraw.h"
#include "camera_info_imx268mipiraw.h"
#include <custom/aaa/AEPlinetable.h>
//#include "camera_custom_flicker_table.h"
#include "camera_custom_flicker_para.h"
#include <cutils/log.h>
#include <string.h>

extern "C" fptrFlicker getFlickerParaFunc(MUINT32 sensorType)
{
    if(sensorType==0)
        return NSFeature::RAWSensorInfo<SENSOR_ID, MODULE_INDEX>::getFlickerPara;
    else
        return NSFeature::YUVSensorInfo<SENSOR_ID, MODULE_INDEX>::getNullFlickerPara;
}

static void get_flicker_para_by_Preview(FLICKER_CUST_PARA* para)
{
  int i;
  int freq[9] = { 70, 80, 100, 120, 130, 160, 170, 210, 230};
  FLICKER_CUST_STATISTICS EV50_L50 = {-194, 4721, 381, -766};
  FLICKER_CUST_STATISTICS EV50_L60 = {996, 466, 871, -423};
  FLICKER_CUST_STATISTICS EV60_L50 = {1188, 491, 1297, -497};
  FLICKER_CUST_STATISTICS EV60_L60 = {-162, 2898, 247, -642};
  for(i=0;i<9;i++)
  {
    para->flickerFreq[i]=freq[i];
  }
  para->flickerGradThreshold=24;
  para->flickerSearchRange=32;
  para->minPastFrames=3;
  para->maxPastFrames=14;
  para->EV50_L50=EV50_L50;
  para->EV50_L60=EV50_L60;
  para->EV60_L50=EV60_L50;
  para->EV60_L60=EV60_L60;
  para->EV50_thresholds[0]=-30;
  para->EV50_thresholds[1]=12;
  para->EV60_thresholds[0]=-30;
  para->EV60_thresholds[1]=12;
  para->freq_feature_index[0]=3;
  para->freq_feature_index[1]=2;
}

static void get_flicker_para_by_Video(FLICKER_CUST_PARA* para)
{
  int i;
  int freq[9] =  { 80, 90, 100, 120, 130, 140, 170, 210, 230};
  FLICKER_CUST_STATISTICS EV50_L50 = {-194, 4721, 381, -766};
  FLICKER_CUST_STATISTICS EV50_L60 = {1023, 454, 849, -416};
  FLICKER_CUST_STATISTICS EV60_L50 = {1220, 478, 1264, -491};
  FLICKER_CUST_STATISTICS EV60_L60 = {-162, 2898, 247, -642};

  for(i=0;i<9;i++)
  {
    para->flickerFreq[i]=freq[i];
  }
  para->flickerGradThreshold=24;
  para->flickerSearchRange=48;
  para->minPastFrames=3;
  para->maxPastFrames=14;
  para->EV50_L50=EV50_L50;
  para->EV50_L60=EV50_L60;
  para->EV60_L50=EV60_L50;
  para->EV60_L60=EV60_L60;
  para->EV50_thresholds[0]=-30;
  para->EV50_thresholds[1]=12;
  para->EV60_thresholds[0]=-30;
  para->EV60_thresholds[1]=12;
  para->freq_feature_index[0]=3;
  para->freq_feature_index[1]=2;
}

static void get_flicker_para_by_Capture(FLICKER_CUST_PARA* para)
{
  int i;
  int freq[9] =  { 80, 90, 100, 110, 120, 130, 140, 160, 190};
  FLICKER_CUST_STATISTICS EV50_L50 = {-194, 4721, 381, -766};
  FLICKER_CUST_STATISTICS EV50_L60 = {1067, 435, 813, -405};
  FLICKER_CUST_STATISTICS EV60_L50 = {1273, 458, 1211, -480};
  FLICKER_CUST_STATISTICS EV60_L60 = {-162, 2898, 247, -642};

  for(i=0;i<9;i++)
  {
    para->flickerFreq[i]=freq[i];
  }
  para->flickerGradThreshold=23;
  para->flickerSearchRange=68;
  para->minPastFrames=3;
  para->maxPastFrames=14;
  para->EV50_L50=EV50_L50;
  para->EV50_L60=EV50_L60;
  para->EV60_L50=EV60_L50;
  para->EV60_L60=EV60_L60;
  para->EV50_thresholds[0]=-30;
  para->EV50_thresholds[1]=12;
  para->EV60_thresholds[0]=-30;
  para->EV60_thresholds[1]=12;
  para->freq_feature_index[0]=4;
  para->freq_feature_index[1]=2;
}

static void get_flicker_para_by_Video1(FLICKER_CUST_PARA* para)
{
  int i;
  int freq[9] =  { 70, 100, 120, 140, 160, 170, 190, 210, 230};
  FLICKER_CUST_STATISTICS EV50_L50 = {-194, 4721, 381, -766};
  FLICKER_CUST_STATISTICS EV50_L60 = {228, 2032, 3796, -800};
  FLICKER_CUST_STATISTICS EV60_L50 = {272, 2140, 5650, -874};
  FLICKER_CUST_STATISTICS EV60_L60 = {-162, 2898, 247, -642};

  for(i=0;i<9;i++)
  {
    para->flickerFreq[i]=freq[i];
  }
  para->flickerGradThreshold=25;
  para->flickerSearchRange=12;
  para->minPastFrames=3;
  para->maxPastFrames=14;
  para->EV50_L50=EV50_L50;
  para->EV50_L60=EV50_L60;
  para->EV60_L50=EV60_L50;
  para->EV60_L60=EV60_L60;
  para->EV50_thresholds[0]=-30;
  para->EV50_thresholds[1]=12;
  para->EV60_thresholds[0]=-30;
  para->EV60_thresholds[1]=12;
  para->freq_feature_index[0]=2;
  para->freq_feature_index[1]=1;
}

static void get_flicker_para_by_Video2(FLICKER_CUST_PARA* para)
{
  int i;
  int freq[9] =  { 70, 100, 120, 140, 160, 170, 190, 210, 230};
  FLICKER_CUST_STATISTICS EV50_L50 = {-194, 4721, 381, -766};
  FLICKER_CUST_STATISTICS EV50_L60 = {340, 1365, 2550, -698};
  FLICKER_CUST_STATISTICS EV60_L50 = {406, 1438, 3796, -772};
  FLICKER_CUST_STATISTICS EV60_L60 = {-162, 2898, 247, -642};

  for(i=0;i<9;i++)
  {
    para->flickerFreq[i]=freq[i];
  }
  para->flickerGradThreshold=25;
  para->flickerSearchRange=12;
  para->minPastFrames=3;
  para->maxPastFrames=14;
  para->EV50_L50=EV50_L50;
  para->EV50_L60=EV50_L60;
  para->EV60_L50=EV60_L50;
  para->EV60_L60=EV60_L60;
  para->EV50_thresholds[0]=-30;
  para->EV50_thresholds[1]=12;
  para->EV60_thresholds[0]=-30;
  para->EV60_thresholds[1]=12;
  para->freq_feature_index[0]=2;
  para->freq_feature_index[1]=1;
}


typedef NSFeature::RAWSensorInfo<SENSOR_ID, MODULE_INDEX> SensorInfoSingleton_T;
namespace NSFeature {
template <>
UINT32
SensorInfoSingleton_T::
impGetFlickerPara(MINT32 sensorMode, MINT32 binRatio, MVOID*const pDataBuf) const
{
	ALOGD("impGetFlickerPara+ mode=%d", sensorMode);
	ALOGD("prv=%d, vdo=%d, cap=%d, zsd=%d",
	    (int)e_sensorModePreview, (int)e_sensorModeVideoPreview, (int)e_sensorModeCapture, (int)e_sensorModeZsd );
	FLICKER_CUST_PARA* para;
	para =  (FLICKER_CUST_PARA*)pDataBuf;
	if(sensorMode == e_sensorModePreview)
		get_flicker_para_by_Preview(para);

	else if(sensorMode == e_sensorModeVideo)
	{
		get_flicker_para_by_Video(para);
	}
	else if(sensorMode == e_sensorModeCapture)
	{
		get_flicker_para_by_Capture(para);
	}
	else if(sensorMode == e_sensorModeVideo1)
	{
		get_flicker_para_by_Video1(para);
	}
	else if(sensorMode == e_sensorModeVideo2)
	{
		get_flicker_para_by_Video2(para);
	}
	else
	{
		ALOGD("impGetFlickerPara ERROR ln=%d", __LINE__);
		return -1;
	}
	ALOGD("impGetFlickerPara-");
	return 0;
}
}

