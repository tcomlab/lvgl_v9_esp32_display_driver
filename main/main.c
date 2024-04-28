/*
    Esample for use driver

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/spi_master.h"
#include "driver/gpio.h"


#include "lvgl.h"

#include "lvgl_helpers.h"


#define LV_TICK_PERIOD_MS 10
#define MY_DISP_HOR_RES 320
#define MY_DISP_VER_RES 240



LV_IMAGE_DECLARE(animimg001);
LV_IMAGE_DECLARE(animimg002);
LV_IMAGE_DECLARE(animimg003);

static const lv_image_dsc_t * anim_imgs[3] = {
    &animimg001,
    & animimg002,
    & animimg003,
};

void build_gui(void)
{
    lv_obj_t * animimg0 = lv_animimg_create(lv_screen_active());
    lv_obj_center(animimg0);
    lv_animimg_set_src(animimg0, (const void **) anim_imgs, 3);
    lv_animimg_set_duration(animimg0, 1000);
    lv_animimg_set_repeat_count(animimg0, LV_ANIM_REPEAT_INFINITE);
    lv_animimg_start(animimg0);
}


void app_main(void)
{
    gpio_reset_pin(GPIO_NUM_22);
    gpio_set_direction(GPIO_NUM_22, GPIO_MODE_OUTPUT);

    lvgl_driver_init();

    lv_init();

    lv_display_t *display = lv_display_create(MY_DISP_HOR_RES, MY_DISP_VER_RES);
    lv_display_set_rotation(display, LV_DISPLAY_ROTATION_0);

    /* Allocate draw buffers on the heap. In this example we use two partial buffers of 1/10th size of the screen */
    lv_color_t * buf1 = NULL;
    lv_color_t * buf2 = NULL;

    uint32_t buf_size = MY_DISP_HOR_RES * MY_DISP_VER_RES / 10 * lv_color_format_get_size(lv_display_get_color_format(display));

    buf1 = lv_malloc(buf_size);
    if(buf1 == NULL) {
            LV_LOG_ERROR("display draw buffer malloc failed");
            return;
    }

    buf2 = lv_malloc(buf_size);
    if(buf2 == NULL) {
            LV_LOG_ERROR("display buffer malloc failed");
            lv_free(buf1);
            return;
    }
    lv_display_set_buffers(display, buf1, buf2, buf_size, LV_DISPLAY_RENDER_MODE_PARTIAL);

    lv_display_set_flush_cb(display, disp_driver_flush);

    build_gui();

    while(1){
        lv_tick_inc(LV_TICK_PERIOD_MS);
        lv_task_handler();
    }

}
