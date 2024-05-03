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
#include "rtc_wdt.h"

#include "lvgl.h"

#include "lvgl_helpers.h"

#include "../ui_export/ui.h"
#include "../ui_export/ui_helpers.h"

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

static void btn_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED) {
        static uint8_t cnt = 0;
        cnt++;

        /*Get the first child of the button which is the label and change its text*/
        lv_obj_t * label = lv_obj_get_child(btn, 0);
        lv_label_set_text_fmt(label, "Button: %d", cnt);
    }
}

/**
 * Create a button with a label and react on click event.
 */
void lv_example_get_started_2(void)
{
    lv_obj_t * btn = lv_button_create(lv_screen_active());     /*Add a button the current screen*/
    lv_obj_set_pos(btn, 10, 10);                            /*Set its position*/
    lv_obj_set_size(btn, 120, 50);                          /*Set its size*/
    lv_obj_add_event_cb(btn, btn_event_cb, LV_EVENT_ALL, NULL);           /*Assign a callback to the button*/

    lv_obj_t * label = lv_label_create(btn);          /*Add a label to the button*/
    lv_label_set_text(label, "Button");                     /*Set the labels text*/
    lv_obj_center(label);
}

void app_main(void)
{
    gpio_reset_pin(GPIO_NUM_22);
    gpio_set_direction(GPIO_NUM_22, GPIO_MODE_OUTPUT);

    rtc_wdt_protect_off();    // Turns off the automatic wdt service


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


    lv_indev_t * indev = lv_indev_create();
    lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);   /*See below.*/
    lv_indev_set_read_cb(indev, touch_driver_read);  /*See below.*/


    //build_gui();
    //lv_example_get_started_2();
    ui_init();

    while(1){
        lv_tick_inc(LV_TICK_PERIOD_MS);
        lv_task_handler();
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }

}
