#include "./include/storage.h"

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

   return (bond_up);
 }


char Storage::add_2(Article const    * to_add,
                    unsigned short int const place)
 { unsigned long int total_amount;

   total_amount = storage[place]->get_amount() + to_add->get_amount();
   if(total_amount <= USHRT_MAX)
     {
       (*storage[place]) += (*to_add);
       changed = true;

       return (F_2ADDED_SUCCESS);
     }
   else
       return (F_2ADDED_FAILURE);
 }


void Storage::insert_after(Article         ** const ppArt_tmp,
                           Article          * const to_add,
                           unsigned short int const place)
 {
   for(unsigned short int i = 0; i <= place; ++i)
       ppArt_tmp[i] = storage[i];

   ppArt_tmp[place + 1] = to_add;

   for(unsigned short int i = place + 1; i < total; ++i)
       ppArt_tmp[i + 1] = storage[i];
 }


void Storage::insert_before(Article         ** const ppArt_tmp,
                            Article          * const to_add,
                            unsigned short int const place)
 {
   for(unsigned short int i = 0; i < place; ++i)
       ppArt_tmp[i] = storage[i];

   ppArt_tmp[place] = to_add;

   for(unsigned short int i = place; i < total; ++i)
       ppArt_tmp[i + 1] = storage[i];
 }


void Storage::load()
 { FILE * pF;

   pF = fopen((get_name()).c_str(), "rt");
   if(pF)
     {
       load_from_file(pF);
       fclose(pF);
     }
   else
     {
       pF = fopen((get_name()).c_str(), "wt");
       if(pF)
         {
           fprintf(stdout,TXT_F_CREATE);
           fclose(pF);
         }
       else
         {
           perror(TXT_PERR_F_CREATE);
       	   exit(ERR_F_CR);
         }
     }
 }


void Storage::load_from_file(FILE * pF)
 { char  	      buffer[MAX_LINE_LENGHT + 1],
      		      ch_val;
   unsigned short int line_num;
   Article          * pArt_new;
   char CHprocess_line(char *, Article **);

   line_num = 1;
   pArt_new = NULL;
   while(fgets(buffer, MAX_LINE_LENGHT + 1, pF))
      {
        ch_val = CHprocess_line(buffer,&pArt_new);
        if(ch_val)
            switch(ch_val)
              {
                case F_ERR_AMOUNT:
                     cerr << "\nPogreska u bazi podataka (kolicina), "
                     	     "linija br. " << line_num;
                     break;
                case F_ERR_PRICE:
                     cerr << "\nPogreska u bazi podataka (cijena), "
                             "linija br. " << line_num;
                     break;
                case F_ERR_NAME:
                     cerr << "\nPogreska u bazi podataka (naziv), "
                             "linija br. " << line_num;
                     break;
                case F_ERR_CR_ART:
                     cerr << TXT_ERR_ART_NO_MEM;
                     break;
                default:
                     cerr << "\nPogreska u bazi podataka (?), "
                             "linija br. " << line_num;
              }
        else
            switch(add(pArt_new, true))
              {
                case F_NO_ERR:
                     break;
                case F_2ADDED_SUCCESS:
                     cout << TXT_2ADDED;
                     delete pArt_new;
                     break;

                case F_ERR_MAX_AMOUNT:
                     cerr << TXT_ERR_PUT_ART "dostignuta max kolicina!";
                     delete pArt_new;
                     break;
               	case F_ERR_NO_MEM:
                     cerr << TXT_ERR_PUT_ART TXT_ERR_ART_NO_MEM;
                     delete pArt_new;
                     break;
                case F_2ADDED_FAILURE:
                     cerr << TXT_ERR_PUT_ART TXT_ERR_2ADDED;
                     delete pArt_new;
                     break;
                default:
                     cerr << TXT_ERR_PUT_ART << "?";
                     delete pArt_new;
              }

        line_num++;
      }
 }


Storage::Storage(char const * const in_name)
	:Storable(in_name)
 {
   changed = false;
   total = 0;
   capacity = CAPACITY_STEP;

   storage = new Article * [capacity];

   load();
 }


Storage::Storage(Storage const & other)
	:Storable((other.get_name()).c_str())
 {
   changed = other.changed;
   total = other.total;
   capacity = other.capacity;

   storage = new Article * [capacity];

   for(unsigned short int i = 0; i < total; ++i)
       storage[i] = other.storage[i];
 }


Storage::~Storage()
 { bool tmp;

   tmp = changed;
   if(!save())
       perror(TXT_PERR_F_SAVE);
   else
       if(tmp)
           cout << TXT_F_SAVE;

   for(unsigned short int i = 0; i < total; ++i)
       delete storage[i];

   delete [] storage;
 }


Storage const & Storage::operator=(Storage const & other)
 {
   if(this != &other)
     {
       delete [] storage;

       changed = other.changed;
       total = other.total;
       capacity = other.capacity;

       storage = new Article * [capacity];

       for(unsigned short int i = 0; i < total; ++i)
           storage[i] = other.storage[i];
     }

   return (*this);
 }


char Storage::add(Article * const to_add, bool loading)
 {
   if(total)
     { unsigned short int place;

       place = approx_place(to_add);
       if((*storage[place]) == (*to_add))
           return (add_2(to_add, place));
       else
           if(total < USHRT_MAX)
             {
               if((*to_add) > (*storage[total - 1]))
                   if(total < capacity)
                     {
                       storage[total++] = to_add;
                       if(!loading)
                           changed = true;

                       return (F_NO_ERR);
                     }
                   else
                       place = total - 1;

               Article ** ppArt_tmp;

               if(total == capacity)
                   capacity += CAPACITY_STEP;

               ppArt_tmp = new Article * [capacity];
               if(ppArt_tmp)
                 {
                   if((*storage[place]) < (*to_add))
                     {
                       insert_after(ppArt_tmp, to_add, place);

                       if(loading && (place == (total - 1)))
                           changed = false;
                       else
                           changed = true;
                     }
                   else
                     {
                       insert_before(ppArt_tmp, to_add, place);
                       changed = true;
                     }

                   delete [] storage;
                   storage = ppArt_tmp;
                   ++total;

                   return (F_NO_ERR);
                 }
               else
                 {
                   if(total == (capacity - CAPACITY_STEP))
                       capacity -= CAPACITY_STEP;

                   return (F_ERR_NO_MEM);
                 }
             }
           else
               return (F_ERR_MAX_AMOUNT);
     }
   else
     {
       storage[total++] = to_add;
       if(!loading)
           changed = true;

       return (F_NO_ERR);
     }
 }


char Storage::get(Article * const to_get)
 { unsigned short int place;

   place = approx_place(to_get);
   if((*storage[place]) == (*to_get))
     {
       if(storage[place]->get_amount() < to_get->get_amount())
           return (F_ERR_NEGATIVE_AMOUNT);
       else
           if(storage[place]->get_amount() == to_get->get_amount())
             { Article ** ppArt_tmp;

               ppArt_tmp = new Article * [total - 1];
               if(ppArt_tmp)
                 {
                   for(unsigned short int i = 0; i < place; ++i)
                       ppArt_tmp[i] = storage[i];

                   delete storage[place];

                   for(unsigned short int i = place + 1; i < total; ++i)
                       ppArt_tmp[i - 1] = storage[i];

                   delete [] storage;
                   storage = ppArt_tmp;
                   --total;
                   changed = true;

                   return (F_NO_ERR);
                 }
               else
                   return (F_ERR_NO_MEM);
             }
           else
             {
               (*storage[place]) -= (*to_get);
               changed = true;

               return (F_NO_ERR);
             }
     }
   else
       return (F_ERR_NO_ARTICLE);
 }


char Storage::substitute(Article * const new_art,
                         Article * const old_art)
 { unsigned short int position;

   new_art->set_amount(old_art->get_amount());
   position = approx_place(old_art);

   for(unsigned short int i = position; i < (total - 1); ++i)
       storage[i] = storage[i + 1];

   delete old_art;
   --total;

   return (add(new_art));
 }


bool Storage::save()
 { bool ret_val;

   ret_val = true;
   if(changed)
     {
       if(!rename((get_name()).c_str(), BKP_FILE_NAME))
         { FILE * pF;

           pF = fopen((get_name()).c_str(), "wt");
       	   if(pF)
             {
               for(unsigned short int i = 0; i < total; ++i)
                   storage[i]->save(pF);

               fclose(pF);

               changed = false;
               ret_val = true;
             }
           else
               ret_val = false;
         }
       else
           ret_val = false;
     }

   return (ret_val);
 }


void Storage::print(char * apch[]) const        //!!!
 {
  unsigned short int j;

/* j = 0;
   if(apch)
       while(apch[j] != 0 && j <= USHRT_MAX)
           delete apch[j++];*/

   for(j = 0; j < total; ++j)
     {
       apch[j] = new char [80];
       storage[j]->print(apch[j]);
     }

// apch[j] = new char (0);
 }

