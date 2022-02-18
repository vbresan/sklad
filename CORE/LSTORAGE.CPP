#include "./include/lstorage.h"
#include "./include/txt_strg.h"
#include "./include/err.h"
#include "./include/plsterrf.h"
#include "./include/strgerrf.h"
#include "./include/trim.h"

using namespace std;


void LoadableStorage::load_from_file(ifstream & in_file)
 { string             line;
   unsigned short int line_num;
   bool               cont;

   line_num = 1;
   cont = true;
   while(getline(in_file, line) && cont)
     { char ch;

       ch = process_line(line);
       if(ch)
           cont = process_load_error(ch, line_num);

       line_num++;
     }
 }


char LoadableStorage::process_line(string & in_line)
 { unsigned short int amount;
   double             price;
   string             name,
                      str_tmp;
   int                i_tmp;
   unsigned short int atous(char const * const pch);
   double             atod(char const * const pch);
   Article            * pArt;

   in_line = trim(in_line);
   i_tmp = in_line.find_first_of(" \t");
   str_tmp = in_line.substr(0, i_tmp);
   amount = atous(str_tmp.c_str());
   if(!amount)
       return F_ERR_AMOUNT;

   in_line = in_line.substr(in_line.find_first_not_of(" \t", i_tmp + 1));
   i_tmp = in_line.find_first_of(" \t");
   str_tmp = in_line.substr(0, i_tmp);
   price = atod(str_tmp.c_str());
   if(!price)
       return F_ERR_PRICE;

   name = in_line.substr(in_line.find_first_not_of(" \t", i_tmp + 1));
   if(!name.length())
       return F_ERR_NAME;

   pArt = new Article(price, name.c_str(), amount);
   if(pArt)
       return Storage::add(pArt);              //O
   else
       return F_ERR_CR_ART;
 }


LoadableStorage::LoadableStorage(char const * const in_name)
                :Storage(in_name),
                 changed(false), MsgD(10)
 { ifstream file_in((get_name()).c_str());

   if(file_in)
       load_from_file(file_in);
   else
     { ofstream file_out((get_name()).c_str());

       if(file_out)
           MsgD.receive_message(TXT_F_CREATE);
       else
         {
           perror(TXT_PERR_F_CREATE);
       	   exit(ERR_F_CR);
         }
     }
 }


void LoadableStorage::back_up()
 { ofstream file_bkp(DEFAULT_BKP_NAME);
   ifstream file_in((get_name()).c_str());
   string   line;

   if(file_bkp && file_in)
       while(getline(file_in, line))
         {
           line += "\n";
           file_bkp << line;
         }
   else
       MsgD.receive_message(TXT_ERR_BKP);
 }


LoadableStorage::~LoadableStorage()
 {
   MsgD.reset();

   if(changed)
     {
       back_up();

       ofstream file_in((get_name()).c_str());
       if(file_in)
         {
           file_in << *this;
           MsgD.receive_message(TXT_F_SAVE);
         }
       else
           MsgD.receive_message(TXT_ERR_F_SAVE);
     }

   cout << MsgD << endl;
 }


char LoadableStorage::add(Article * const to_add)
 { char ret_val;

   ret_val = Storage::add(to_add);
   switch(ret_val)
     {
       case F_NO_ERR:
            changed = true;
            MsgD.receive_message(TXT_PUT_ART);
            break;
       case F_2ADDED_SUCCESS:
            changed = true;
            MsgD.receive_message(TXT_2ADDED);
            break;
       case F_2ADDED_FAILURE:
            MsgD.receive_message(TXT_ERR_2ADDED);
            break;
       case F_ERR_NO_MEM:
            MsgD.receive_message(TXT_ERR_NO_MEM);
            break;
       case F_ERR_MAX_AMOUNT:
            MsgD.receive_message(TXT_ERR_AMOUNT);
            break;
       default:
            break;
     }

   return ret_val;
 }


char LoadableStorage::get(Article * const to_get)
 { char ret_val;

   ret_val = Storage::get(to_get);
   switch(ret_val)
     {
       case F_NO_ERR:
            changed = true;
            MsgD.receive_message(TXT_PUT_ART);
            break;
       case F_ERR_NO_ARTICLE:
            MsgD.receive_message(TXT_ERR_NO_ARTICLE);
            break;
       case F_ERR_NEGATIVE_AMOUNT:
            MsgD.receive_message(TXT_ERR_NEGATIVE_AMOUNT);
            break;
       default:
            break;
     }

   return ret_val;
 }


char LoadableStorage::substitute(Article          * const new_art,
                                 unsigned short int const position)
 { char ret_val;

   ret_val = Storage::substitute(new_art, position);
   switch(ret_val)
     {
       case F_NO_ERR:
            changed = true;
            MsgD.receive_message(TXT_SUBSTITUTE_ART);
            break;
       case F_2ADDED_SUCCESS:
            changed = true;
            MsgD.receive_message(TXT_SUBSTITUTE_ART TXT_2ADDED);
            break;
       case F_2ADDED_FAILURE:
            MsgD.receive_message(TXT_ERR_2ADDED);
            break;
       case F_ERR_NO_MEM:
            MsgD.receive_message(TXT_ERR_NO_MEM);
            break;
       case F_ERR_MAX_AMOUNT:
            MsgD.receive_message(TXT_ERR_AMOUNT);
            break;
       default:
            break;
     }

   return ret_val;
 }


