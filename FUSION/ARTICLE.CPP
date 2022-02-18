#include "./include/article.h"
#include "./include/articlem.h"

using namespace std;


unsigned long int  Article::total_amount = 0;
double	   	   Article::total_price = 0;
unsigned short int Article::total_number = 0;


Article::Article(double const       	  in_price,
                 char const * const 	  in_name,
                 unsigned short int const in_amount)
        :Storable(in_name)
 {
   price = in_price;
   amount = in_amount;

   INCREMENT_TOTAL;
 }


Article::Article(Article const & other)
        :Storable((other.get_name()).c_str())
 {
   price = other.price;
   amount = other.amount;

   INCREMENT_TOTAL;
 }


Article::~Article()
 {
   DECREMENT_TOTAL;
 }


Article & Article::operator=(Article const & other)
 {
   if(this != &other)
     {
       DECREMENT_TOTAL;

       price = other.price;
       amount = other.amount;
       Storable::operator=(other);
//       set_name(other.get_name());

       INCREMENT_TOTAL;
     }

   return (*this);
 }


char Article::save(FILE * pf)
 {
   fprintf(pf, "%hu\t%.2f\t%s\n", amount, price, (get_name()).c_str());

   return (0);
 }


void Article::print(char * pch) const
 {
   sprintf(pch, "%-30s     %5hu %16.2f %16.2f\n\r",
           (get_name()).c_str(), amount, price, (amount * price));
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


bool operator==(Article const & left, Article const & right)
 {
   if(!stricmp((left.get_name()).c_str(), (right.get_name()).c_str()))
       return (left.get_price() == right.get_price());
   else
       return false;
 }


bool operator!=(Article const & left, Article const & right)
 {
   if(!stricmp((left.get_name()).c_str(), (right.get_name()).c_str()))
       return (left.get_price() != right.get_price());
   else
       return true;
 }


bool operator>(Article const & left, Article const & right)
 { int cmp_val;

   cmp_val = stricmp((left.get_name()).c_str(), (right.get_name()).c_str());
   if(cmp_val)
       if(cmp_val > 0)
           return true;
       else
           return false;
   else
       return (left.get_price() > right.get_price());
 }


bool operator<(Article const & left, Article const & right)
 { int cmp_val;

   cmp_val = stricmp((left.get_name()).c_str(), (right.get_name()).c_str());
   if(cmp_val)
       if(cmp_val < 0)
           return true;
       else
           return false;
   else
       return (left.get_price() < right.get_price());
 }


ostream & operator<<(ostream & stream, Article const & article)
 {
   return (stream << article.get_name() << " "
                  << article.get_amount() << " "
                  << article.get_price() << " "
                  << article.get_amount() * article.get_price());
 }

