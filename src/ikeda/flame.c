#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>

#include "flame.h"
  
//
int flame_flush_display(flame_obj_t *fo)
{
  if (fo && fo->display)
    return XFlush(fo->display), 1;
  else
    return 0;
}

//
int flame_close(flame_obj_t *fo)
{
  if (fo)
  { 
    XFreeGC(fo->display, fo->gc);
    XCloseDisplay(fo->display);

    free(fo);

    return 1;
  }
  else
    return 0;
}

//
flame_obj_t *flame_open(char *title, int width, int height)
{
  XEvent e;
  int vb = 0;
  Visual *visual;
  int blackColor, whiteColor;
  XSetWindowAttributes attrib;
  flame_obj_t *fo = malloc(sizeof(flame_obj_t));
  
  fo->display = XOpenDisplay(0);
  
  if (!fo->display)
    {
      fprintf(stderr,"flame_open: unable to open the graphics window.\n");
      exit(1);
    }

  visual = DefaultVisual(fo->display, 0);
  
  fo->fast_color_mode = (visual && visual->class == TrueColor);
  
  blackColor = BlackPixel(fo->display, DefaultScreen(fo->display));
  whiteColor = WhitePixel(fo->display, DefaultScreen(fo->display));
  
  //fo->window = XCreateSimpleWindow(fo->display, DefaultRootWindow(fo->display), 0, 0, width, height, 0, blackColor, blackColor);
  fo->window = XCreateSimpleWindow(fo->display, DefaultRootWindow(fo->display), 0, 0, width, height, 0, blackColor, blackColor);
  
  attrib.backing_store = Always;
  
  XChangeWindowAttributes(fo->display, fo->window, CWBackingStore, &attrib);
  
  XStoreName(fo->display, fo->window,title);
  
  XSelectInput(fo->display, fo->window, StructureNotifyMask | ExposureMask | KeyPressMask | ButtonPressMask | ButtonReleaseMask | PointerMotionMask);

  XMapWindow(fo->display, fo->window);
  
  fo->gc = XCreateGC(fo->display, fo->window, 0, 0);
  
  fo->colormap = DefaultColormap(fo->display, 0);
  
  XSetForeground(fo->display, fo->gc, whiteColor);
  
  while(!vb)
    {
      XNextEvent(fo->display, &e);
      
      vb = (e.type == MapNotify);
    }

  return fo;
}

//
void flame_draw_point(flame_obj_t *fo, int x, int y)
{ XDrawPoint(fo->display, fo->window, fo->gc, x, y); }

//
void flame_draw_line(flame_obj_t *fo, int x1, int y1, int x2, int y2)
{ XDrawLine(fo->display,fo->window,fo->gc, x1, y1, x2, y2); }

//
void flame_set_color(flame_obj_t *fo, int r, int g, int b)
{
  XColor color;
  
  if (fo->fast_color_mode)
    color.pixel = ((b & 0xff) | ((g & 0xff) << 8) | ((r & 0xff) << 16));
  else
    {
      color.pixel = 0;
      color.red   = r << 8;
      color.green = g << 8;
      color.blue  = b << 8;
      XAllocColor(fo->display, fo->colormap, &color);
    }

  XSetForeground(fo->display, fo->gc, color.pixel);
}


//
void flame_clear_display(flame_obj_t *fo)
{ XClearWindow(fo->display, fo->window); }

//
void flame_clear_color(flame_obj_t *fo, int r, int g, int b )
{
  XColor color;
  XSetWindowAttributes attrib;

  color.pixel = 0;
  color.red   = r << 8;
  color.green = g << 8;
  color.blue  = b << 8;
  XAllocColor(fo->display, fo->colormap, &color);
  
  attrib.background_pixel = color.pixel;
  XChangeWindowAttributes(fo->display, fo->window, CWBackPixel,&attrib);
}

//
int flame_event_waiting(flame_obj_t *fo)
{
  XEvent event;
  
  flame_flush_display(fo);
  
  while (1)
    {
      if (XCheckMaskEvent(fo->display, -1, &event))
	{
	  if (event.type == KeyPress)
	    {
	      XPutBackEvent(fo->display, &event);
	      
	      return 1;
	    }
	  else
	    if (event.type == ButtonPress)
	      {
		XPutBackEvent(fo->display, &event);
		
		return 1;
	      }
	    else
	      return 0;
	}
      else
	return 0;
    }
}

//
char flame_wait(flame_obj_t *fo, int *click_x, int *click_y)
{
  XEvent event;
  
  flame_flush_display(fo);
  
  while (1)
    {
      if (XPending(fo->display) > 0)
	{
	  XNextEvent(fo->display, &event);
	  
	  if (event.type == KeyPress)
	    {
	      /* printf("%c\n", XLookupKeysym(&event.xkey, 0)); */
	      return XLookupKeysym(&event.xkey, 0);
	    }
	  else
	    if (event.type == ButtonPress)
	      {
		*click_x = event.xkey.x;
		*click_y = event.xkey.y;
		
		//Left click == 1, Right click == 3
		return event.xbutton.button;
	      }
	}
      else
	{
	  ;
	}
    }
}

