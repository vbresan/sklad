#ifndef GUI_MAIN_H
#define GUI_MAIN_H

/*
*/


#include <allegro.h>


/****************************************************************************/
/* funkcije definirane u ovom modulu za koje moraju znati ostali moduli
*/


void allegro_startup();


/****************************************************************************/
/* funkcije definirane u modulu gui_main.cpp
   za njih ne moraju znati ostali moduli
*/


static void ini_pallete(struct RGB pallete[]);
static int  o_programu();
static int  kraj();


/****************************************************************************/
/* funkcije definirane u ostalim modulima, potrebne i u ovom
   deklarirane su kao extern premda je ta rijec u ovom slucaju suvisna
*/


extern int uvid();
extern int pohrana();

extern int unos();
extern int izdavanje();
extern int promjena();


/****************************************************************************/
/* deklaracije globalnih varijabli definiranih u drugim modulima
*/


extern MENU menu_skl[];
extern MENU menu_art[];


/****************************************************************************/
/* deklaracije i inicijalizacije varijabli potrebnih samo ovom modulu
*/


static MENU menu_main[] =
 {
//   (char * text)	(int (*proc)())		(struct MENU * child)	(int flags)	(void *dp)
   { "&Skladiste", 	NULL, 			menu_skl, 		0, 		NULL },
   { "&Artikli", 	NULL, 			menu_art, 		0, 		NULL },
   { "                                       ",
    			NULL, 			NULL, 			0, 		NULL },
   { "&O programu", 	o_programu, 		NULL, 			0, 		NULL },
   { "&Kraj", 		kraj, 			NULL, 			0,		NULL },
   { NULL, 		NULL, 			NULL, 			0, 		NULL }
 };


static DIALOG dialog_main[] =
 {
   /* (dialog proc)     (x)   (y)   (w)   (h)   (fg)  (bg)  (key) (flags)  (d1)         (d2)  (dp)              (dp2) (dp3) */
   { d_clear_proc,      0,    0,    0,    0,    255,  0,    0,    0,       0,           0,    NULL,             NULL, NULL  },

   { d_keyboard_proc,   0,    0,    0,    0,    0,    0,    0,    0,       KEY_F1,      0,    uvid,             NULL, NULL  },
   { d_keyboard_proc,   0,    0,    0,    0,    0,    0,    0,    0,       KEY_F2,      0,    pohrana,          NULL, NULL  },
   { d_keyboard_proc,   0,    0,    0,    0,    0,    0,    0,    0,       KEY_F3,      0,    unos,             NULL, NULL  },
   { d_keyboard_proc,   0,    0,    0,    0,    0,    0,    0,    0,       KEY_F4,      0,    izdavanje,        NULL, NULL  },
   { d_keyboard_proc,   0,    0,    0,    0,    0,    0,    0,    0,       KEY_F5,      0,    promjena,         NULL, NULL  },
    
   { d_keyboard_proc,   0,    0,    0,    0,    0,    0,    0,    0,       KEY_ESC,     0,    kraj,             NULL, NULL  },

   { d_menu_proc,       5,    5,    0,    0,    0,    0,    0,    0,       0,           0,    menu_main,        NULL, NULL  },

   { NULL,              0,    0,    0,    0,    0,    0,    0,    0,       0,           0,    NULL,             NULL, NULL  }
 };


/*
*/

#endif

