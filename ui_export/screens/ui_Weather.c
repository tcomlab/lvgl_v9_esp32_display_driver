// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.6
// Project name: Smart_Gadget

#include "../ui.h"

void ui_Weather_screen_init(void)
{
    ui_Weather = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Weather, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Weather, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Weather, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Weather, &ui_img_pattern_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_tiled(ui_Weather, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Pary_Cloud = ui_Small_Label_create(ui_Weather);
    lv_obj_set_x(ui_Pary_Cloud, 0);
    lv_obj_set_y(ui_Pary_Cloud, -67);
    lv_obj_set_align(ui_Pary_Cloud, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Pary_Cloud, "Party cloud");
    lv_obj_set_style_text_color(ui_Pary_Cloud, lv_color_hex(0x000746), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Pary_Cloud, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_New_York = ui_Small_Label_create(ui_Weather);
    lv_obj_set_x(ui_New_York, 0);
    lv_obj_set_y(ui_New_York, 37);
    lv_obj_set_align(ui_New_York, LV_ALIGN_CENTER);
    lv_label_set_text(ui_New_York, "New York");
    lv_obj_set_style_text_color(ui_New_York, lv_color_hex(0x9C9CD9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_New_York, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Cloud = lv_img_create(ui_Weather);
    lv_img_set_src(ui_Cloud, &ui_img_cloud_png);
    lv_obj_set_width(ui_Cloud, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Cloud, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Cloud, -2);
    lv_obj_set_y(ui_Cloud, 19);
    lv_obj_set_align(ui_Cloud, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_Cloud, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Cloud, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_Cloud, lv_color_hex(0x293062), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_Cloud, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Celsius = lv_label_create(ui_Weather);
    lv_obj_set_width(ui_Celsius, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Celsius, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Celsius, 0);
    lv_obj_set_y(ui_Celsius, 125);
    lv_obj_set_align(ui_Celsius, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_Celsius, "26°");
    lv_obj_set_style_text_color(ui_Celsius, lv_color_hex(0x293062), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Celsius, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Celsius, &ui_font_Number, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Weather_Icons = lv_obj_create(ui_Weather);
    lv_obj_set_height(ui_Weather_Icons, 56);
    lv_obj_set_width(ui_Weather_Icons, lv_pct(100));
    lv_obj_set_x(ui_Weather_Icons, 0);
    lv_obj_set_y(ui_Weather_Icons, -33);
    lv_obj_set_align(ui_Weather_Icons, LV_ALIGN_BOTTOM_MID);
    lv_obj_clear_flag(ui_Weather_Icons, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Weather_Icons, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Weather_Icons, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_w1 = lv_img_create(ui_Weather_Icons);
    lv_img_set_src(ui_w1, &ui_img_weather_1_png);
    lv_obj_set_width(ui_w1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_w1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_w1, 40);
    lv_obj_set_y(ui_w1, 0);
    lv_obj_add_flag(ui_w1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_w1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_w1, lv_color_hex(0x293062), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_w1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_w2 = lv_img_create(ui_Weather_Icons);
    lv_img_set_src(ui_w2, &ui_img_weather_2_png);
    lv_obj_set_width(ui_w2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_w2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_w2, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_w2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_w2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_w2, lv_color_hex(0x293062), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_w2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_w3 = lv_img_create(ui_Weather_Icons);
    lv_img_set_src(ui_w3, &ui_img_weather_3_png);
    lv_obj_set_width(ui_w3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_w3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_w3, -40);
    lv_obj_set_y(ui_w3, 0);
    lv_obj_set_align(ui_w3, LV_ALIGN_TOP_RIGHT);
    lv_obj_add_flag(ui_w3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_w3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_w3, lv_color_hex(0x293062), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_w3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_W1_Num = ui_Small_Label_create(ui_Weather_Icons);
    lv_obj_set_x(ui_W1_Num, 35);
    lv_obj_set_y(ui_W1_Num, 25);
    lv_obj_set_align(ui_W1_Num, LV_ALIGN_TOP_LEFT);
    lv_label_set_text(ui_W1_Num, "65°");

    ui_W2_Num = ui_Small_Label_create(ui_Weather_Icons);
    lv_obj_set_x(ui_W2_Num, 0);
    lv_obj_set_y(ui_W2_Num, 25);
    lv_obj_set_align(ui_W2_Num, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_W2_Num, "24km/h");

    ui_W3_Num = ui_Small_Label_create(ui_Weather_Icons);
    lv_obj_set_x(ui_W3_Num, -30);
    lv_obj_set_y(ui_W3_Num, 25);
    lv_obj_set_align(ui_W3_Num, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_W3_Num, "18%");

    ui_Scrolldots4 = ui_Scrolldots_create(ui_Weather);
    lv_obj_set_x(ui_Scrolldots4, 0);
    lv_obj_set_y(ui_Scrolldots4, -8);

    lv_obj_set_width(ui_comp_get_child(ui_Scrolldots4, UI_COMP_SCROLLDOTS_D1), 4);
    lv_obj_set_height(ui_comp_get_child(ui_Scrolldots4, UI_COMP_SCROLLDOTS_D1), 4);

    lv_obj_set_x(ui_comp_get_child(ui_Scrolldots4, UI_COMP_SCROLLDOTS_D2), 10);
    lv_obj_set_y(ui_comp_get_child(ui_Scrolldots4, UI_COMP_SCROLLDOTS_D2), 0);

    lv_obj_set_x(ui_comp_get_child(ui_Scrolldots4, UI_COMP_SCROLLDOTS_D3), 20);
    lv_obj_set_y(ui_comp_get_child(ui_Scrolldots4, UI_COMP_SCROLLDOTS_D3), 0);

    lv_obj_set_x(ui_comp_get_child(ui_Scrolldots4, UI_COMP_SCROLLDOTS_D4), 30);
    lv_obj_set_y(ui_comp_get_child(ui_Scrolldots4, UI_COMP_SCROLLDOTS_D4), 0);

    lv_obj_set_width(ui_comp_get_child(ui_Scrolldots4, UI_COMP_SCROLLDOTS_D5), 8);
    lv_obj_set_height(ui_comp_get_child(ui_Scrolldots4, UI_COMP_SCROLLDOTS_D5), 8);
    lv_obj_set_x(ui_comp_get_child(ui_Scrolldots4, UI_COMP_SCROLLDOTS_D5), 41);
    lv_obj_set_y(ui_comp_get_child(ui_Scrolldots4, UI_COMP_SCROLLDOTS_D5), 0);
    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Scrolldots4, UI_COMP_SCROLLDOTS_D5), lv_color_hex(0x101C52),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Scrolldots4, UI_COMP_SCROLLDOTS_D5), 255, LV_PART_MAIN | LV_STATE_DEFAULT);



    lv_obj_add_event_cb(ui_Weather, ui_event_Weather, LV_EVENT_ALL, NULL);

}
