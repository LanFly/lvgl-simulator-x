#include "gfx.h"
#include "lvgl.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 240
#define HEIGHT 240

extern void app_start();

void tGFX_565_to_RGB(uint16_t color, uint8_t *r, uint8_t *g, uint8_t *b) {
  *r = (color >> 11) << 3;
  *g = (color >> 5 & 0x3F) << 2;
  *b = (color & 0x1F) << 3;
}

static void lvgl_flush_cb(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_map)
{
  uint8_t r, g, b;
  for (int y = area->y1; y <= area->y2; y++)
  {
    for (int x = area->x1; x <= area->x2; x++)
    {
      tGFX_565_to_RGB(color_map->full, &r, &g, &b);
      gfx_color(r, g, b);
      gfx_point(x, y);
      color_map++;
    }
  }

  lv_disp_flush_ready(drv);
}

static void lvgl_increase_tick()
{
  /* Tell LVGL how many milliseconds has elapsed */
  lv_tick_inc(3);
}

void lvgl_init()
{
  lv_init();
  static lv_disp_draw_buf_t disp_buf;
  static lv_disp_drv_t disp_drv;
  lv_color_t *buf1 = malloc(WIDTH * 24 * sizeof(lv_color_t));
  lv_color_t *buf2 = malloc(WIDTH * 24 * sizeof(lv_color_t));
  lv_disp_draw_buf_init(&disp_buf, buf1, buf2, WIDTH * 24);
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res = WIDTH;
  disp_drv.ver_res = WIDTH;
  disp_drv.flush_cb = lvgl_flush_cb;
  disp_drv.draw_buf = &disp_buf;
  lv_disp_drv_register(&disp_drv);
}

int main()
{
  lvgl_init();
  gfx_open(WIDTH, HEIGHT, "lvgl-sim-MacOS");

  app_start();

  int times = 0;
  while (1)
  {
    int e = gfx_event_waiting();
    if (e)
    {
      char c = gfx_wait();
      if (c == 'q')
      {
        break;
      }
    }
    usleep(3000);
    lvgl_increase_tick();
    times+= 3;
    if (times >= 6) {
      times = 0;
      lv_task_handler();
    }
  }
  return 0;
}