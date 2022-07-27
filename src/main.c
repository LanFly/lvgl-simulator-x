#include "lvgl.h"

void app_start()
{
  lv_obj_t *label = lv_label_create(lv_scr_act());
  lv_label_set_text(label, "hello lvgl-sim-MacOS");
  lv_obj_center(label);
}
