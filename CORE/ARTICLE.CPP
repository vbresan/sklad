#include "./include/article.h"

using namespace std;


unsigned long int  Article::total_amount = 0;
double	   	   Article::total_price = 0;
unsigned short int Article::total_number = 0;


inline void Article::increment_total()
 {
   total_amount += amount;
   total_price += price * amount;
   ++total_number;
 }


inline void Article::decrement_total()
 {
   total_amount -= amount;
   total_price -= price * amount;
   --total_number;
 }


Article::Article(double const       	  in_price,
                 char const * const 	  in_name,
                 unsigned short int const in_amount)
        :Storable(in_name)
 {
   price = in_price;
   amount = in_amount;

   increment_total();
 }


Article::Article(Article const & other)
        :Storable((other.get_name()).c_str())
 {
   price = other.price;
   amount = other.amount;

   increment_total();
 }


Article::~Article()
 {
   decrement_total();
 }


Article & Article::operator=(Article const & other)
 {
   if(this != &other)
     {
       decrement_total();

       price = other.price;
       amount = other.amount;
       Storable::operator=(other);

       increment_total();
     }

   return *this;
 }


void operator+=(Article & left, Article const & right)
 {
   if(left == right)
     {
       left.amount += right.amount;
       Article::total_amount += right.amount;
       Article::total_price += right.amount * right.price;
     }
 }


void operator+=(Article & left, unsigned short int const right)
 {
   left.amount += right;
   Article::total_amount += right;
   Article::total_price += right * left.price;
 }


void operator-=(Article & left, Article const & right)
 {
   left.amount -= right.amount;
   Article::total_amount -= right.amount;
   Article::total_price -= right.amount * right.price;
 }


void operator-=(Article & left, unsigned short int const right)
 {
   left.amount -= right;
   Article::total_amount -= right;
   Article::total_price -= right * left.price;
 }


ostream & operator<<(ostream & stream, Article const & article)
 {
   return (stream << article.get_amount() << "\t"
                  << article.get_price() << "\t"
                  << article.get_name() << "\n");
 }

