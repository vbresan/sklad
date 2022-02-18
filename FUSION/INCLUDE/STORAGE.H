#ifndef STORAGE_H
#define STORAGE_H

/*
*/

#include "storable.h"
#include "article.h"

#include "ferrstg.h"
#include "ferrcfun.h"
#include "txt_strg.h"
#include "err.h"

#include <climits>		// USHRT_MAX


#define DEFAULT_STORAGE_NAME	"skldiste.dat"
#define BKP_FILE_NAME		"skldiste.bkp"

#define CAPACITY_STEP	2//128
#define MAX_LINE_LENGHT	80


class Storage : public Storable
 { private:
   	unsigned short int total,
        		   capacity;
        Article 	** storage;
        bool 		   changed;

        unsigned short int approx_place(Article * const pArt);

        char add_2(Article const * to_add, unsigned short int const place);
        void insert_after(Article ** const ppArt_tmp, Article * const to_add,
                          unsigned short int const place);
        void insert_before(Article ** const ppArt_tmp, Article * const to_add,
                           unsigned short int const place);

        void load();
        void load_from_file(FILE * pF);

   public:
   	Storage(char const * const in_name = DEFAULT_STORAGE_NAME);
        Storage(Storage const & other);
        ~Storage();

        Storage const & operator=(Storage const & other);

        char add(Article * const to_add, bool loading = false);
        char get(Article * const to_get);
        char substitute(Article * const new_art, Article * const old_art);

        bool save();
        void print(char * apch[]) const;
 };


/*
*/

#endif

