#include "./include/gui_skl.h"


int uvid()
 {
   popup_dialog(dialog_uvid, -1);
   return D_O_K;
 }


int pohrana()
 {
   exit(2);
   return D_O_K;
 }


char * listbox_getter(int   index,
                      int * list_size)
 { static char * strings[] =
    {
      "123456789012345678901234567890     12345 1234567890123456 1234567890123456",
      "Zero",  "One",   "Two",   "Three", "Four",  "Five",
      "Six",   "Seven", "Eight", "Nine",  "Ten",
      "Lola", "Ribizla", "Sir pikantni", "Sunset fighter",
      "Morning fighter", "Dobri ljudi", "Losi ljudi", "Zli ljudi",
      "Testis unus", "Testis nulus", "Bonus", "Bobis", "Ora pronobis"
    };

   if(index < 0)
     {
       *list_size = 25;
       return NULL;
     }
   else
      return strings[index]; 
 }

