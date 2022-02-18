#include "./include/gui_art.h"


int d_my_list_proc(int      msg,
                   DIALOG * d,
                   int      c)
 { int ret_val,
       selected;

   selected = dialog_unos[DU_LIST].d1;
   ret_val = d_list_proc(msg, d, c);

   if(selected != dialog_unos[DU_LIST].d1)
       d_edit_proc(MSG_DRAW, &dialog_unos[DU_EDIT1], 0);

   return ret_val;
 }


int unos()
 {
   dialog_unos[DU_LIST].d1 = 0;
   dialog_unos[DU_TEXT2].flags = 0;
   dialog_unos[DU_TEXT3].flags = 0;
   dialog_unos[DU_EDIT2].flags = 0;
   dialog_unos[DU_EDIT3].flags = 0;

   dialog_unos[DU_BUTTON1].key = 'u';
   dialog_unos[DU_BUTTON1].dp = (void *) "&Unesi!";

   popup_dialog(dialog_unos, -1);

   return D_O_K;
 }


int izdavanje()
 {
   dialog_unos[DU_LIST].d1 = 0;
   dialog_unos[DU_TEXT2].flags = 0;
   dialog_unos[DU_TEXT3].flags = D_DISABLED;
   dialog_unos[DU_EDIT2].flags = 0;
   dialog_unos[DU_EDIT3].flags = D_DISABLED;

   dialog_unos[DU_BUTTON1].key = 'd';
   dialog_unos[DU_BUTTON1].dp = (void *) "Iz&daj!";

   popup_dialog(dialog_unos, -1);

   return D_O_K;
 }


int promjena()
 {
   dialog_unos[DU_LIST].d1 = 0;
   dialog_unos[DU_TEXT2].flags = D_DISABLED;
   dialog_unos[DU_TEXT3].flags = 0;
   dialog_unos[DU_EDIT2].flags = D_DISABLED;
   dialog_unos[DU_EDIT3].flags = 0;

   dialog_unos[DU_BUTTON1].key = 'p';
   dialog_unos[DU_BUTTON1].dp = (void *) "&Promijeni!";

   popup_dialog(dialog_unos, -1);

   return D_O_K;
 }


char * listbox_getter(int   index,
                      int * list_size)
 { char ** strings;
   int     curr_list_size;

   if(dialog_unos[DU_BUTTON1].key == 'u')
     {
       strings = names;
       curr_list_size = 26;
     }
   else
     {
       strings = &names[1];
       curr_list_size = 25;
     }

   strcpy(edit_string1, strings[dialog_unos[DU_LIST].d1]);

   if(index < 0)
     {
       *list_size = curr_list_size;
       return NULL;
     }
   else
       return strings[index];
 }

