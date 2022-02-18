#ifndef STORAGE_H
#define STORAGE_H

/*
*/

#include "storable.h"
#include "article.h"
#include <string>
#include <iostream>


#define DEFAULT_STORAGE_NAME	"skldiste.dat"
#define CAPACITY_STEP	        2//128


class Storage : public Storable
 { friend ostream & operator<<(ostream & out, Storage const & storage);

   private:
   	unsigned short int total,
        		   capacity;
        Article 	** storage;

        unsigned short int approx_place(Article * const pArt);

        void remove_article(unsigned short int const place);
        char add_2(Article * const to_add, unsigned short int const place);
        char insert_after(Article * const to_add,
                          unsigned short int const place);
        char insert_before(Article * const to_add,
                           unsigned short int const place);

   public:
   	Storage(char const * const in_name = DEFAULT_STORAGE_NAME);
        Storage(Storage const & other);
        ~Storage();

        Storage const & operator=(Storage const & other);

        char add(Article * const to_add);
        char get(Article * const to_get);
        char substitute(Article * const new_art,
                        unsigned short int const position);

        void format_string(char ** ppch) const;
 };


/*
*/

#endif

