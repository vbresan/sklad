#ifndef ARTICLE_H
#define ARTICLE_H

/*
*/


#include "storable.h"
#include <cstring>              // stricmp


#define DEFAULT_ARTICLE_AMOUNT	1


class Article : public Storable
 { friend void operator+=(Article & left, Article const & right);
   friend void operator+=(Article & left, unsigned short int const right);
   friend void operator-=(Article & left, Article const & right);
   friend void operator-=(Article & left, unsigned short int const right);

   private:
        double             price;
        unsigned short int amount;

        static unsigned long int  total_amount;
        static double		  total_price;
        static unsigned short int total_number;

   public:
   	Article(double const       	 in_price,
                char const * const 	 in_name = DEFAULT_STORABLE_NAME,
                unsigned short int const in_amount = DEFAULT_ARTICLE_AMOUNT);
        Article(Article const & other);
        ~Article();

        Article & operator=(Article const & other);

        static unsigned long int  get_total_amount() { return total_amount; }
        static double 		  get_total_price()  { return total_price;  }
        static unsigned short int get_total_number() { return total_number; }

        double             get_price() const  { return price;  }
        unsigned short int get_amount() const { return amount; }

        void set_price(double const new_price) 	       { price = new_price; }
        void set_amount(unsigned short int new_amount) { amount = new_amount; }

        void print(char * pch) const;
        char save(FILE * pf);
 };


bool operator==(Article const & left, Article const & right);
bool operator!=(Article const & left, Article const & right);
bool operator>(Article const & left, Article const & right);
bool operator<(Article const & left, Article const & right);
ostream & operator<<(ostream & stream, Article const & article);


/*
*/

#endif

