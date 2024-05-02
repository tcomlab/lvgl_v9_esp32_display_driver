/**
 * @file lv_templ.h
 *
 */

#ifndef SH1107_H
#define SH1107_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include <stdbool.h>

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif
#include "../lvgl_helpers.h"

/*********************
 *      DEFINES
 *********************/
#define SH1107_DC   CONFIG_LV_DISP_PIN_DC
#define SH1107_RST  CONFIG_LV_DISP_PIN_RST

/**********************
 *      TYPEDEFS
 **********************/
typedef union
{
    struct
    {
#if LV_COLOR_16_SWAP == 0
        uint16_t blue : 5;
        uint16_t green : 6;
        uint16_t red : 5;
#else
        uint16_t green_h : 3;
        uint16_t red : 5;
        uint16_t blue : 5;
        uint16_t green_l : 3;
#endif
    } ch;
    uint16_t full;
} lv_color16_2_t;
// TODO: Move to menuconfig
#define LV_VER_RES_MAX 280

/**********************
 * GLOBAL PROTOTYPES
 **********************/

void sh1107_init(void);
void sh1107_flush(lv_display_t  * drv, const lv_area_t * area, uint8_t * color_map);
void sh1107_rounder( lv_display_t  * disp_drv, lv_area_t *area);
void sh1107_set_px_cb( lv_display_t  * disp_drv, uint8_t * buf, lv_coord_t buf_w, lv_coord_t x, lv_coord_t y,
    lv_color_t color, lv_opa_t opa);
void sh1107_sleep_in(void);
void sh1107_sleep_out(void);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*SH1107_H*/
