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
 { char ** strings = ppch;

//   pCurr_Storage->print(strings);

   if(index < 0)
     {
       *list_size = Article::get_total_number();
       return NULL;
     }
   else
      return strings[index]; 
 }

