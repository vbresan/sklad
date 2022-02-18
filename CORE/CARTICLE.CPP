#ifdef __STRICT_ANSI__
#undef __STRICT_ANSI__
#endif

#include "./include/article.h"
#include <cstdio>
#include <cstring>

using namespace std;


void Article::format_string(char * pch) const
 {
   sprintf(pch, "%-30s     %5hu %16.2f %16.2f", (get_name()).c_str(),
           					 amount, price,
                                                 (amount * price));
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


