#ifndef GUI_SKL_H
#define GUI_SKL_H

/*
*/


#include <allegro.h>


/****************************************************************************/
/* deklaracija funkcija potrebnih i drugim modulima
*/


int uvid();
int pohrana();


/****************************************************************************/
/* deklaracije funkcija potrebni hsamo ovom modulu
*/


static char * listbox_getter(int index, int * list_size);


/****************************************************************************/
/* deklaracija i inicijalizacija globalni varijabli potrebnih i drugim
   modulima
*/


MENU menu_skl[] =
 {
//   (char * text)			(int (*proc)())		(struct MENU * child)	(int flags)	(void *dp)
   { "&Uvid u stanje \t(F1)", 		uvid, 			NULL, 			0, 		NULL },
   { "&Pohrana promjene stanja \t(F2)",	pohrana, 		NULL, 			0, 		NULL },
   { NULL, 				NULL, 			NULL, 			0, 		NULL }
 };


/****************************************************************************/
/* deklaracija i incijalizacija globalnih varijabli potrebih samo u ovom
   modulu
*/


static DIALOG dialog_uvid[] =
 {
   /* (dialog proc)     (x)   (y)   (w)   (h)   (fg)  (bg)  (key) (flags)  (d1)         (d2)  (dp)           (dp2) (dp3) */
   { d_shadow_box_proc,	5,    50,   630,  285,  191,  254,  0,    0,       0,           0,    NULL,     		NULL, NULL  },

   { d_box_proc,	10,   55,   620,  30,   255,  191,  0,    0,       0,           0,    NULL,     		NULL, NULL  },
   { d_text_proc,	20,   70,   0,    0,    255,  191,  0,    0,       0,           0,    (void *) "Naziv artikla                       Kol.           Cijena            Iznos",     	NULL, NULL  },

   { d_box_proc,	10,   265,  620,  30,   255,  191,  0,    0,       0,           0,    NULL,     		NULL, NULL  },
   { d_text_proc,	20,   280,  0,    0,    255,  191,  0,    0,       0,           0,    (void *) "12345                         1234567890                  1234567890123456",     	NULL, NULL  },

   { d_button_proc,	10,   300,  110,  30,   255,  191,  'u',  D_EXIT,  0,           0,    (void *) "&U redu!",	NULL, NULL  },
   { d_button_proc,	125,  300,  110,  30,   255,  191,  'p',  0,  	   0,           0,    (void *) "&Printaj!",	NULL, NULL  },

   { d_list_proc,	10,   85,   620,  180,  255,  191,  0,    0,       0,           0,    listbox_getter,	NULL, NULL  },

   { NULL,              0,    0,    0,    0,    0,    0,    0,    0,       0,           0,    NULL,          	NULL, NULL  }
 };


/*
*/

#endif

