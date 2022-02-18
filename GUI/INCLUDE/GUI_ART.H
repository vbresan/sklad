#ifndef GUI_ART_H
#define GUI_ART_H

/*
*/


#include <allegro.h>


#define DU_TEXT1        2
#define DU_TEXT2        DU_TEXT1 + 1
#define DU_TEXT3        DU_TEXT2 + 1
#define DU_BUTTON1      5
#define DU_BUTTON2      DU_BUTTON1 + 1
#define DU_BUTTON3      DU_BUTTON2 + 1
#define DU_LIST         8
#define DU_EDIT1        DU_LIST + 1
#define DU_EDIT2        DU_EDIT1 + 1
#define DU_EDIT3        DU_EDIT2 + 1


/****************************************************************************/
/* deklaracije funkcija potrebnih i drugim modulima (gui_main.cpp)
*/


int unos();
int izdavanje();
int promjena();


/****************************************************************************/
/* deklaracije funkcija potrebnih samo ovom modulu
*/


static int    d_my_list_proc(int msg, DIALOG *d, int c);
static char * listbox_getter(int index, int * list_size);


/****************************************************************************/
/* deklaracija i inicijalizacija globalnih varijabli potrebnih i drugim
   modulima
*/


MENU menu_art[] =
 {
//   (char * text)			(int (*proc)())		(struct MENU * child)	(int flags)	(void *dp)
   { "&Unos \t(F3)", 			unos, 			NULL, 			0, 		NULL },
   { "&Izdavanje \t(F4)",      		izdavanje, 		NULL, 			0, 		NULL },
   { "",      				NULL, 			NULL, 			0, 		NULL },
   { "&Promjena podataka \t(F5)",       promjena,		NULL, 			0, 		NULL },
   { NULL, 				NULL, 			NULL, 			0, 		NULL }
 };


/****************************************************************************/
/* deklaracija i inicijalizacija globalnih varijabli potrebnih samo ovom
   modulu
*/


static char edit_string1[32],
            edit_string2[32],
            edit_string3[32];


static char * names[] =
    {
      "",
      "Zero",  "One",   "Two",   "Three", "Four",  "Five",
      "Six",   "Seven", "Eight", "Nine",  "Ten",
      "Lola", "Ribizla", "Sir pikantni", "Sunset fighter",
      "Morning fighter", "Dobri ljudi", "Losi ljudi", "Zli ljudi",
      "Testis unus", "Testis nulus", "Bonus", "Bobis", "Ora pronobis",
      "123456789012345678901234567890"
    };


static DIALOG dialog_unos[] =
 {
   /* (dialog proc)     (x)   (y)   (w)   (h)   (fg)  (bg)  (key) (flags)  (d1)                    (d2)  (dp)           (dp2) (dp3) */
   { d_shadow_box_proc,	5,    50,   630,  90,   191,  254,  0,    0,       0,                      0,    NULL,     		NULL, NULL  },

   { d_box_proc,	285,  55,   345,  45,   255,  191,  0,    0,       0,                      0,    NULL,     		NULL, NULL  },

   { d_text_proc,	290,  60,   0,    0,    255,  191,  0,    0,       0,                      0,    (void *) "&Ime     : ",     	NULL, NULL  },
   { d_text_proc,	290,  74,   0,    0,    255,  191,  0,    0,       0,                      0,    (void *) "&Kolicina: ",     	NULL, NULL  },
   { d_text_proc,	290,  88,   0,    0,    255,  191,  0,    0,       0,                      0,    (void *) "&Cijena  : ",	NULL, NULL  },

   { d_button_proc,	285,  105,  108,  30,   255,  191,  0,    0,       0,                      0,    NULL,  		NULL, NULL  },
   { d_button_proc,	401,  105,  108,  30,   255,  191,  's',  0,       0,                      0,    (void *) "&Sljedeci",	NULL, NULL  },
   { d_button_proc,	517,  105,  112,  30,   255,  191,  'o',  D_EXIT,  0,                      0,    (void *) "&Odustani",	NULL, NULL  },

   { d_my_list_proc,	10,   55,   270,  80,   255,  191,  0,    0,       0,                      0,    listbox_getter,	NULL, NULL  },

   { d_edit_proc,	370,  60,   245,  14,   255,  191,  'i',  0,       30,                     0,    edit_string1,  NULL, NULL  },
   { d_edit_proc,	370,  74,   245,  14,   255,  191,  'k',  0,       5,                      0,    edit_string2,  NULL, NULL  },
   { d_edit_proc,	370,  88,   245,  14,   255,  191,  'c',  0,       16,                     0,    edit_string3,	NULL, NULL  },

   { NULL,              0,    0,    0,    0,    0,    0,    0,    0,       0,                      0,    NULL,          		NULL, NULL  }
 };


/*
*/

#endif

