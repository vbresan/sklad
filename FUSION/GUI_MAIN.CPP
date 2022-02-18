#include "./include/gui_main.h"


void allegro_startup()
 { PALLETE pallete;

   allegro_init();
   install_keyboard();
   install_mouse();
   install_timer();
   set_gfx_mode(GFX_AUTODETECT, 640, 480, 0, 0);

   ini_pallete(pallete);
   set_palette(pallete);

   gui_fg_color = 255;
   gui_bg_color = 191;
   gui_mg_color = 254;

   do_dialog(dialog_main, -1);
 }


void ini_pallete(struct RGB pallete[])
 { int c;

   for(c = 0; c < 64; c++)
      {
        pallete[c].r = c;
        pallete[c].g = 0;
        pallete[c].b = 0;
      }
   for(c = 64; c < 128; c++)
      {
        pallete[c].r = 127-c;
      	pallete[c].g = c-64;
      	pallete[c].b = 0;
      }
   for(c = 128; c < 192; c++)
      {
        pallete[c].r = 0;
        pallete[c].g = 191-c;
      	pallete[c].b = c-128;
      }
   for(c = 192; c < 256; c++)
      {
        pallete[c].r = 0;
        pallete[c].g = 0;
        pallete[c].b = 255-c;
      }

   pallete[254].r = 32;
   pallete[254].g = 32;
   pallete[254].b = 32;

   pallete[255].r = 63;
   pallete[255].g = 63;
   pallete[255].b = 63;
 }


int kraj()
 { int alert_ret_val;

   alert_ret_val = alert("Zaista zelite izlazak iz programa?", NULL, NULL,
                         "&Da", "&Ne!", 'd', 'n');
   if(alert_ret_val == 1)
       return D_CLOSE;
   else
       return D_O_K;
 }


int o_programu()
 {
   alert("Skladiste 1.0", NULL, "                          ",
         "&U redu!", NULL, 'u', 'u');

   return D_O_K;
 }

