#include "./include/lstorage.h"
#include "./include/plsterrf.h"
#include "./include/txt_strg.h"
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <string>


#define USI_STR_LENGHT  6

using namespace std;


void LoadableStorage::perror(char const * string)
 {
   perror(string);
 }


unsigned short int atous(char const * const pch)
 { unsigned short int ret_val;
   double	      tmp;

   tmp = atof(pch);
   if(tmp > USHRT_MAX)
       ret_val = 0;
   else
       ret_val = (unsigned short int) tmp;

   return ret_val;
 }


double atod(char const * const pch)
 {
   return atof(pch);
 }


bool LoadableStorage::process_load_error(char               error,
                                         unsigned short int line_num)
 { bool   ret_val;
   string str("Pogreska u bazi podataka ");
   char   ach[USI_STR_LENGHT];

   sprintf(ach, "%hu", line_num);
   ret_val = true;

   switch(error)
     {
       case F_ERR_AMOUNT:
            str += "(kolicina), linija br. ";
            break;
       case F_ERR_PRICE:
            str += "(cijena), linija br. ";
            break;
       case F_ERR_NAME:
            str += "(naziv), linija br. ";
            break;
       case F_ERR_CR_ART:
            str = TXT_ERR_ART_NO_MEM;
            ret_val = false;
            break;
       default:
            str += "(?), linija br. ";
     }

   if(error != F_ERR_CR_ART)
       str += ach;

   MsgD.receive_message(str.c_str());

   return ret_val;
 }
