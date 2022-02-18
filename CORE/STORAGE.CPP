#include "./include/storage.h"
#include "./include/strgerrf.h"
#include <climits>              // USHRT_MAX

using namespace std;


unsigned short int Storage::approx_place(Article * const pArt)
 { unsigned short int bond_up,
   		      bond_down,
                      tmp_val;

   bond_up = total - 1;
   bond_down = 0;
   while(bond_up > bond_down)
     {
       tmp_val = (bond_up + bond_down) / 2;

       if((*pArt) == (*storage[tmp_val]))
           bond_up = bond_down = tmp_val;
       else
           if((*pArt) > (*storage[tmp_val]))
               bond_down = tmp_val + 1;
           else
               bond_up = tmp_val - 1;
     }

   return bond_up;
 }


void Storage::remove_article(unsigned short int const place)
 {
   delete storage[place];

   for(unsigned short int i = place; i < (total - 1) ; ++i)
       storage[i] = storage[i+1];

   --total;
 }


char Storage::add_2(Article          * const to_add,
                    unsigned short int const place)
 { unsigned long int total_amount;

   total_amount = storage[place]->get_amount() + to_add->get_amount();
   if(total_amount <= USHRT_MAX)
     {
       (*storage[place]) += (*to_add);

       return F_2ADDED_SUCCESS;
     }
   else
       return F_2ADDED_FAILURE;
 }


char Storage::insert_after(Article          * const to_add,
                           unsigned short int const place)
 { char ret_val;

   if((place == (total - 1)) && (total < capacity))
     {
       storage[total++] = to_add;
       ret_val = F_NO_ERR;
     }
   else
     { Article ** ppArt_tmp;

       if(total == capacity)
           capacity += CAPACITY_STEP;

       ppArt_tmp = new Article* [capacity];
       if(ppArt_tmp)
         {
           for(unsigned short int i = 0; i <= place; ++i)
                ppArt_tmp[i] = storage[i];

           ppArt_tmp[place + 1] = to_add;

           for(unsigned short int i = place + 1; i < total; ++i)
                ppArt_tmp[i + 1] = storage[i];

           delete [] storage;
           storage = ppArt_tmp;
           ++total;

           ret_val = F_NO_ERR;
         }
       else
         {
           if(total == (capacity - CAPACITY_STEP))
               capacity -= CAPACITY_STEP;

           ret_val = F_ERR_NO_MEM;
         }
     }

   return ret_val;
 }


char Storage::insert_before(Article          * const to_add,
                            unsigned short int const place)
 { char ret_val;
   Article ** ppArt_tmp;

   if(total == capacity)
       capacity += CAPACITY_STEP;

   ppArt_tmp = new Article* [capacity];
   if(ppArt_tmp)
     {
       for(unsigned short int i = 0; i < place; ++i)
            ppArt_tmp[i] = storage[i];

       ppArt_tmp[place] = to_add;

       for(unsigned short int i = place; i < total; ++i)
            ppArt_tmp[i + 1] = storage[i];

       delete [] storage;
       storage = ppArt_tmp;
       ++total;

       ret_val = F_NO_ERR;
     }
   else
     {
       if(total == (capacity - CAPACITY_STEP))
           capacity -= CAPACITY_STEP;

       ret_val = F_ERR_NO_MEM;
     }

   return ret_val;
 }


Storage::Storage(char const * const in_name)
	:Storable(in_name)
 {
   total = 0;
   capacity = CAPACITY_STEP;

   storage = new Article * [capacity];
 }


Storage::Storage(Storage const & other)
	:Storable((other.get_name()).c_str())
 {
   total = other.total;
   capacity = other.capacity;

   storage = new Article * [capacity];

   for(unsigned short int i = 0; i < total; ++i)
       storage[i] = other.storage[i];
 }


Storage::~Storage()
 {
   for(unsigned short int i = 0; i < total; ++i)
       delete storage[i];

   delete [] storage;
 }


Storage const & Storage::operator=(Storage const & other)
 {
   if(this != &other)
     {
       for(unsigned short int i = 0; i < total; ++i)
           delete storage[i];

       delete [] storage;

       total = other.total;
       capacity = other.capacity;
       Storable::operator=(other);

       storage = new Article * [capacity];

       for(unsigned short int i = 0; i < total; ++i)
           storage[i] = other.storage[i];
     }

   return *this;
 }


char Storage::add(Article * const to_add)
 { char ret_val;

   if(total)
     { unsigned short int place;

       place = approx_place(to_add);
       if((*storage[place]) == (*to_add))
           ret_val = add_2(to_add, place);
       else
           if(total < USHRT_MAX)
               if((*to_add) > (*storage[place]))
                   ret_val = insert_after(to_add, place);
               else
                   ret_val = insert_before(to_add, place);
           else
               ret_val = F_ERR_MAX_AMOUNT;
     }
   else
     {
       storage[total++] = to_add;
       ret_val = F_NO_ERR;
     }

   return ret_val;
 }


ostream & operator<<(ostream       & out,
                     Storage const & storage)
 {
   out.setf(ios::fixed, ios::floatfield);
   out.precision(2);

   for(unsigned short int i = 0; i < storage.total; ++i)
       out << *storage.storage[i];

   return out;
 }


char Storage::get(Article * const to_get)
 { char               ret_val;
   unsigned short int place;

   place = approx_place(to_get);
   if((*storage[place]) == (*to_get))
       if(storage[place]->get_amount() < to_get->get_amount())
           ret_val = F_ERR_NEGATIVE_AMOUNT;
       else
         {
           if(storage[place]->get_amount() != to_get->get_amount())
               (*storage[place]) -= (*to_get);
           else
               remove_article(place);

           ret_val = F_NO_ERR;
         }
   else
       ret_val = F_ERR_NO_ARTICLE;

   return ret_val;
 }


char Storage::substitute(Article          * const new_art,
                         unsigned short int const position)
 {
   new_art->set_amount(storage[position]->get_amount());
   remove_article(position);

   return add(new_art);
 }


void Storage::format_string(char ** ppch) const
 {
   for(unsigned short int i = 0; i < total; )
       storage[i]->format_string(ppch[i]);
 }

