#ifndef FLAME_H
#define FLAME_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>

//
typedef struct flame_obj_s {
  
  GC        gc;
  Window    window;
  Display  *display;
  Colormap  colormap;
  int       fast_color_mode;
  
} flame_obj_t;

int  flame_close(flame_obj_t *fo);
int  flame_event_waiting(flame_obj_t *fo);
void flame_flush(flame_obj_t *fo);
void flame_clear_display(flame_obj_t *fo);
void flame_draw_point(flame_obj_t *fo, int x, int y);
flame_obj_t *flame_open(char *title, int width, int height);
char flame_wait(flame_obj_t *fo, int *click_x, int *click_y);
void flame_set_color(flame_obj_t *fo, int red, int green, int blue );
void flame_draw_line(flame_obj_t *fo, int x1, int y1, int x2, int y2);
void flame_clear_color(flame_obj_t *fo,  int red, int green, int blue );

#endif
