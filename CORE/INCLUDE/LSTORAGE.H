#ifndef LSTORAGE_H
#define LSTORAGE_H

/*
*/

#include "storage.h"
#include "msg_dspc.h"
#include <fstream>

#define DEFAULT_BKP_NAME	"skldiste.bkp"


class LoadableStorage : public Storage
 {
   private:
           bool changed;

           void perror(char const * string);
           void load_from_file(ifstream & file_in);
           char process_line(string & line);
           bool process_load_error(char error, unsigned short int line_num);

           void back_up();

   public:
           MsgDispatch  MsgD;
           LoadableStorage(char const * const in_name = DEFAULT_STORAGE_NAME);
           ~LoadableStorage();

           char add(Article * const to_add);
           char get(Article * const to_get);
           char substitute(Article * const new_art,
                           unsigned short int const position);
 };


/*
*/

#endif

