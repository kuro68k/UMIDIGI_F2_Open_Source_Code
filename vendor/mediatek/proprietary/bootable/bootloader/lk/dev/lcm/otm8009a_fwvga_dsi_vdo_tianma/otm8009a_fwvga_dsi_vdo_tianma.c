/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2015. All rights reserved.
*
* BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
* THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
* RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
* AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
* NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
* SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
* SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
* THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
* THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
* CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
* SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
* STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
* CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
* AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
* OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
* MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
* The following software/firmware and/or related documentation ("MediaTek Software")
* have been modified by MediaTek Inc. All revisions are subject to any receiver\'s
* applicable license agreements with MediaTek Inc.
*/
#ifndef BUILD_LK
#include <linux/string.h>
#endif

#include "lcm_drv.h"

#ifdef BUILD_LK
	#include <platform/mt_gpio.h>
	#include <string.h>
#elif defined(BUILD_UBOOT)
	#include <asm/arch/mt_gpio.h>
#else
	#include <mach/mt_gpio.h>
#endif



// ---------------------------------------------------------------------------
// Local Constants
// ---------------------------------------------------------------------------

#define FRAME_WIDTH (480)
#define FRAME_HEIGHT (854)

#define REGFLAG_DELAY 0XFD
#define REGFLAG_END_OF_TABLE 0xFE // END OF REGISTERS MARKER

#define LCM_DSI_CMD_MODE 0   
#define LCM_ID 0x8009


#define LCD_MODUL_ID (0x02)

#if 0
#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

static unsigned int lcm_esd_test = FALSE; ///only for ESD test

#endif

// ---------------------------------------------------------------------------
// Local Variables
// ---------------------------------------------------------------------------

static LCM_UTIL_FUNCS lcm_util;

#define SET_RESET_PIN(v) (lcm_util.set_reset_pin((v)))

#define UDELAY(n) (lcm_util.udelay(n))
#define MDELAY(n) (lcm_util.mdelay(n))


// ---------------------------------------------------------------------------
// Local Functions
// ---------------------------------------------------------------------------

#define dsi_set_cmdq_V2(cmd, count, ppara, force_update) lcm_util.dsi_set_cmdq_V2(cmd, count, ppara, force_update)
#define dsi_set_cmdq(pdata, queue_size, force_update) lcm_util.dsi_set_cmdq(pdata, queue_size, force_update)
#define wrtie_cmd(cmd) lcm_util.dsi_write_cmd(cmd)
#define write_regs(addr, pdata, byte_nums) lcm_util.dsi_write_regs(addr, pdata, byte_nums)
#define read_reg(cmd) lcm_util.dsi_dcs_read_lcm_reg(cmd)
#define read_reg_v2(cmd, buffer, buffer_size) lcm_util.dsi_dcs_read_lcm_reg_v2(cmd, buffer, buffer_size) 

static struct LCM_setting_table {
unsigned char cmd;
unsigned char count;
unsigned char para_list[64];
}lcm_initialization_setting[],lcm_deep_sleep_mode_in_setting[];

static struct LCM_setting_table lcm_initialization_setting[] = {
	
	/*
	Note :

	Data ID will depends on the following rule.
	
		count of parameters > 1	=> Data ID = 0x39
		count of parameters = 1	=> Data ID = 0x15
		count of parameters = 0	=> Data ID = 0x05

	Structure Format :

	{DCS command, count of parameters, {parameter list}}
	{REGFLAG_DELAY, milliseconds of time, {}},

	...

	Setting ending by predefined flag
	
	{REGFLAG_END_OF_TABLE, 0x00, {}}
	*/

//TM FFS 495 FWVGA__Video
{0x00,1,{0x00}},
{0xFF,3,{0x80,0x09,0x01}},
 
{0x00,1,{0x80}},
{0xFF,2,{0x80,0x09}},

{0x00,1,{0x03}},
{0xff,1,{0x01}},

{0x00,1,{0xb4}}, 
{0xc0,1,{0x50}},

{0x00,1,{0x89}},
{0xc4,1,{0x08}},

{0x00,1,{0x82}},
{0xc5,1,{0x83}},

{0x00,1,{0x90}},
{0xC5,2,{0x96,0x76}},

{0x00,1,{0x00}}, 
{0xD8,2,{0x6F,0x6F}},

{0x00,1,{0x00}}, 
{0xD9,1,{0x3d}},

{0x00,1,{0x81}},
{0xc1,1,{0x66}},

{0x00,1,{0x81}},
{0xc4,1,{0x83}},

{0x00,1,{0x92}}, 
{0xc5,1,{0x01}},

{0x00,1,{0xB1}},
{0xC5,1,{0xA9}},

{0x00,1,{0x90}},
{0xb3,1,{0x02}},

{0x00,1,{0x92}},
{0xb3,1,{0x45}},

{0x00,1,{0x80}},
{0xc0,9,{0x00,0x58,0x00,0x15,0x15,0x00,0x58,0x15,0x15}},

{0x00,1,{0x90}},
{0xc0,6,{0x00,0x44,0x00,0x00,0x00,0x03}},
 
{0x00,1,{0xa6}},
{0xc1,3,{0x00,0x00,0x00}},

{0x00,1,{0x80}},
{0xce,12,{0x8a,0x03,0x00,0x89,0x03,0x00,0x88,0x03,0x00,0x87,0x03,0x00}},
 
{0x00,1,{0x90}},
{0xce,14,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},
 
{0x00,1,{0xa0}},
{0xce,14,{0x38,0x06,0x03,0x55,0x00,0x00,0x00,0x38,0x05,0x03,0x56,0x00,0x00,0x00}},
 
{0x00,1,{0xb0}},
{0xce,14,{0x38,0x04,0x03,0x57,0x00,0x00,0x00,0x38,0x03,0x03,0x58,0x00,0x00,0x00}},
 
{0x00,1,{0xc0}},
{0xce,14,{0x38,0x02,0x03,0x59,0x00,0x00,0x00,0x38,0x01,0x03,0x5a,0x00,0x00,0x00}},
 
{0x00,1,{0xd0}},
{0xce,14,{0x38,0x00,0x03,0x53,0x00,0x00,0x00,0x30,0x00,0x03,0x54,0x00,0x00,0x00}},
 
{0x00,1,{0x80}},
{0xcf,14,{0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x00,0x00,0x00,0x00,0x00,0x00}},
 
{0x00,1,{0x90}},
{0xcf,14,{0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x00,0x00,0x00,0x00,0x00,0x00}},
 
{0x00,1,{0xa0}},
{0xcf,14,{0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x00,0x00,0x00,0x00,0x00,0x00}},
 
{0x00,1,{0xb0}},
{0xcf,14,{0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x00,0x00,0x00,0x00,0x00,0x00}},
 
{0x00,1,{0xc0}},
{0xcf,10,{0x02,0x02,0x20,0x20,0x00,0x00,0x01,0x00,0x10,0x00}},

{0x00,1,{0x80}},
{0xcb,10,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},
 
{0x00,1,{0x90}},
{0xcb,15,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},
 
{0x00,1,{0xa0}},
{0xcb,15,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},
 
{0x00,1,{0xb0}},
{0xcb,10,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},

{0x00,1,{0xc0}},
{0xcb,15,{0x04,0x04,0x00,0x00,0x04,0x04,0x04,0x04,0x04,0x04,0x00,0x00,0x00,0x00,0x00}},

{0x00,1,{0xd0}},
{0xcb,15,{0x00,0x00,0x00,0x00,0x00,0x04,0x04,0x00,0x00,0x04,0x04,0x04,0x04,0x04,0x04}},

{0x00,1,{0xe0}}, 
{0xcb,10,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},

{0x00,1,{0xf0}},
{0xcb,10,{0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff}},
 
{0x00,1,{0x80}},
{0xcc,10,{0x26,0x25,0x00,0x00,0x0c,0x0a,0x10,0x0e,0x02,0x04}},
 
{0x00,1,{0x90}},
{0xcc,15,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x26,0x25,0x00,0x00,0x0b}},
 
{0x00,1,{0xa0}},
{0xcc,15,{0x09,0x0f,0x0d,0x01,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},
 
{0x00,1,{0xb0}},
{0xcc,10,{0x25,0x26,0x00,0x00,0x0b,0x0d,0x0f,0x09,0x01,0x03}},
 
{0x00,1,{0xc0}},
{0xcc,15,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x25,0x26,0x00,0x00,0x0c}},
 
{0x00,1,{0xd0}},
{0xcc,15,{0x0e,0x10,0x0a,0x02,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},
 

{0x00,1,{0x00}}, 
{0xE1,16,{0x00,0x1c,0x20,0x0e,0x05,0x11,0x0B,0x0A,0x03,0x07,0x0A,0x07,0x0E,0x10,0x09,0x00}},

{0x00,1,{0x00}}, 
{0xE2,16,{0x00,0x1c,0x20,0x0e,0x05,0x11,0x0B,0x0A,0x03,0x07,0x0A,0x07,0x0E,0x10,0x09,0x00}},

//3gamma-----------------------------

{0x00,1,{0x00}}, 
{0xEC,33,{0x40,0x44,0x44,0x44,0x43,0x43,0x44,0x44,0x43,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x04}},

{0x00,1,{0x00}}, 
{0xED,33,{0x40,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x04}},

{0x00,1,{0x00}}, 
{0xEE,33,{0x40,0x44,0x44,0x44,0x44,0x45,0x45,0x44,0x44,0x44,0x45,0x44,0x44,0x44,0x44,0x44,0x45,0x44,0x44,0x44,0x45,0x44,0x45,0x45,0x45,0x44,0x44,0x44,0x44,0x43,0x43,0x44,0x04}},


//--------------------------------------

{0x00,1,{0x00}},//Address shift
	{0x11,1,{0x00}},
	   
   //printf(" Sleep out \n");
{REGFLAG_DELAY, 120, {}},
   
   
   {0x00,1,{0x00}},//Address shift
	{0x29,1,{0x00}},
	{REGFLAG_DELAY, 50, {}},
	{REGFLAG_END_OF_TABLE, 0x00, {}}
};


#if 0
static struct LCM_setting_table lcm_sleep_out_setting[] = {
    // Sleep Out
    {0x11, 1, {0x00}},
    {REGFLAG_DELAY, 120, {}},

    // Display ON
    {0x29, 1, {0x00}},
    {REGFLAG_DELAY, 20, {}},
    {REGFLAG_END_OF_TABLE, 0x00, {}}
};
#endif

static struct LCM_setting_table lcm_deep_sleep_mode_in_setting[] = {
     // Display off sequence
     {0x28, 1, {0x00}},
     {REGFLAG_DELAY, 20, {}},
     // Sleep Mode Ondiv1_real*div2_real
     {0x10, 1, {0x00}},
     {REGFLAG_DELAY, 120, {}},
     {REGFLAG_END_OF_TABLE, 0x00, {}}
};

#if 0
static struct LCM_setting_table lcm_backlight_level_setting[] = {
    {0x51, 1, {0xFF}},
    {0x53, 1, {0x24}},//close dimming
    {0x55, 1, {0x00}},//close cabc
    {REGFLAG_END_OF_TABLE, 0x00, {}}
};
#endif

static void push_table(struct LCM_setting_table *table, unsigned int count, unsigned char force_update)
{
    unsigned int i;

    for(i = 0; i < count; i++) {

        unsigned cmd;
        cmd = table[i].cmd;

        switch (cmd) {
        case REGFLAG_DELAY :
            MDELAY(table[i].count);
            break;
        case REGFLAG_END_OF_TABLE :
            break;
        default:
            dsi_set_cmdq_V2(cmd, table[i].count, table[i].para_list, force_update);
        }
    }
}


// ---------------------------------------------------------------------------
// LCM Driver Implementations
// ---------------------------------------------------------------------------

static void lcm_set_util_funcs(const LCM_UTIL_FUNCS *util)
{
    memcpy(&lcm_util, util, sizeof(LCM_UTIL_FUNCS));
}


static void lcm_get_params(LCM_PARAMS *params)
{
		memset(params, 0, sizeof(LCM_PARAMS));
	
		params->type   = LCM_TYPE_DSI;

		params->width  = FRAME_WIDTH;
		params->height = FRAME_HEIGHT;

		// enable tearing-free
		params->dbi.te_mode 				= LCM_DBI_TE_MODE_VSYNC_ONLY;
		params->dbi.te_edge_polarity		= LCM_POLARITY_RISING;

#if (LCM_DSI_CMD_MODE)
		params->dsi.mode   = CMD_MODE;
#else
		params->dsi.mode   = SYNC_PULSE_VDO_MODE;
#endif
	
		// DSI
		/* Command mode setting */
		params->dsi.LANE_NUM				= LCM_TWO_LANE;
		//The following defined the fomat for data coming from LCD engine.
		params->dsi.data_format.color_order = LCM_COLOR_ORDER_RGB;
		params->dsi.data_format.trans_seq   = LCM_DSI_TRANS_SEQ_MSB_FIRST;
		params->dsi.data_format.padding     = LCM_DSI_PADDING_ON_LSB;
		params->dsi.data_format.format      = LCM_DSI_FORMAT_RGB888;

		// Highly depends on LCD driver capability.
		// Not support in MT6573
		params->dsi.packet_size=256;

		// Video mode setting		
		params->dsi.intermediat_buffer_num = 2;

		params->dsi.PS=LCM_PACKED_PS_24BIT_RGB888;

		params->dsi.vertical_sync_active				= 4;
		params->dsi.vertical_backporch					= 8;
		params->dsi.vertical_frontporch					= 8;
		params->dsi.vertical_active_line				= FRAME_HEIGHT; 

		params->dsi.horizontal_sync_active				= 6;
		params->dsi.horizontal_backporch				= 37;
		params->dsi.horizontal_frontporch				= 37;
		params->dsi.horizontal_active_pixel				= FRAME_WIDTH;

		params->dsi.PLL_CLOCK=208;
		//params->dsi.pll_div1=0;		// div1=0,1,2,3;div1_real=1,2,4,4 ----0: 546Mbps  1:273Mbps
		//params->dsi.pll_div2=0;		// div2=0,1,2,3;div1_real=1,2,4,4
		//params->dsi.fbk_div =8;
}





static void lcm_init(void)
{
    SET_RESET_PIN(1);
    MDELAY(5);
    SET_RESET_PIN(0);
    MDELAY(30);
    SET_RESET_PIN(1);
    MDELAY(30);

    //lcm_init_registers();
    push_table(lcm_initialization_setting, sizeof(lcm_initialization_setting) / sizeof(struct LCM_setting_table), 1);
}


static void lcm_suspend(void)
{

    push_table(lcm_deep_sleep_mode_in_setting, sizeof(lcm_deep_sleep_mode_in_setting) / sizeof(struct LCM_setting_table), 1);

}

static void lcm_resume(void)
{
    lcm_init();

    //push_table(lcm_sleep_out_setting, sizeof(lcm_sleep_out_setting) / sizeof(struct LCM_setting_table), 1);
}


#if (LCM_DSI_CMD_MODE)
static void lcm_update(unsigned int x, unsigned int y,
unsigned int width, unsigned int height)
{
    unsigned int x0 = x;
    unsigned int y0 = y;
    unsigned int x1 = x0 + width - 1;
    unsigned int y1 = y0 + height - 1;

    unsigned char x0_MSB = ((x0>>8)&0xFF);
    unsigned char x0_LSB = (x0&0xFF);
    unsigned char x1_MSB = ((x1>>8)&0xFF);
    unsigned char x1_LSB = (x1&0xFF);
    unsigned char y0_MSB = ((y0>>8)&0xFF);
    unsigned char y0_LSB = (y0&0xFF);
    unsigned char y1_MSB = ((y1>>8)&0xFF);
    unsigned char y1_LSB = (y1&0xFF);

    unsigned int data_array[16];

	data_array[0]= 0x00053902;
	data_array[1]= (x1_MSB<<24)|(x0_LSB<<16)|(x0_MSB<<8)|0x2a;
	data_array[2]= (x1_LSB);
	dsi_set_cmdq(data_array, 3, 1);

	data_array[0]= 0x00053902;
	data_array[1]= (y1_MSB<<24)|(y0_LSB<<16)|(y0_MSB<<8)|0x2b;
	data_array[2]= (y1_LSB);
	dsi_set_cmdq(data_array, 3, 1);

	data_array[0]= 0x002c3909;
	dsi_set_cmdq(data_array, 1, 0);
}
#endif

#if 0
static void lcm_setbacklight(unsigned int level)
{

    unsigned int mapped_level = 0;

    //for LGE backlight IC mapping table
    if(level > 255)
    level = 255;

    mapped_level = level * 7 / 10;//to reduce power
   

    // Refresh value of backlight level.
    lcm_backlight_level_setting[0].para_list[0] = mapped_level;

#ifdef BUILD_LK
    printf("uboot:otm8009a_lcm_setbacklight mapped_level = %d,level=%d\n",mapped_level,level);
#else
    printk("kernel:otm8009a_lcm_setbacklight mapped_level = %d,level=%d\n",mapped_level,level);
#endif

    push_table(lcm_backlight_level_setting, sizeof(lcm_backlight_level_setting) / sizeof(struct LCM_setting_table), 1);

}

static unsigned int lcm_esd_check(void)
{
    #ifndef BUILD_LK
    if(lcm_esd_test)
    {
        lcm_esd_test = FALSE;
        return TRUE;
    }

    if(read_reg(0x0A) == 0x9C)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
    #endif
}

static unsigned int lcm_esd_recover(void)
{
    unsigned char para = 0;

    SET_RESET_PIN(1);
    SET_RESET_PIN(0);
    MDELAY(1);
    SET_RESET_PIN(1);
    MDELAY(120);

    push_table(lcm_initialization_setting, sizeof(lcm_initialization_setting) / sizeof(struct LCM_setting_table), 1);
    MDELAY(10);

    push_table(lcm_sleep_out_setting, sizeof(lcm_sleep_out_setting) / sizeof(struct LCM_setting_table), 1);
    MDELAY(10);

    dsi_set_cmdq_V2(0x35, 1, &para, 1); ///enable TE
    MDELAY(10);

    return TRUE;
}
#endif


LCM_DRIVER otm8009a_fwvga_dsi_vdo_tianma_lcm_drv = 
{
    .name			= "otm8009a_fwvga_dsi_vdo_tianma",
    .set_util_funcs = lcm_set_util_funcs,
    //.compare_id = lcm_compare_id,
    .get_params = lcm_get_params,
    .init = lcm_init,
    .suspend = lcm_suspend,
    .resume = lcm_resume,
    #if (LCM_DSI_CMD_MODE)
    //.set_backlight = lcm_setbacklight,
    //.esd_check = lcm_esd_check,
    //.esd_recover = lcm_esd_recover,
    .update = lcm_update,
    #endif
};

