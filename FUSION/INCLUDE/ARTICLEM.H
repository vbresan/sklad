#ifndef MARTICLE_H
#define MARTICLE_H


/*
*/


#define INCREMENT_TOTAL 						\
	do    								\
          {								\
            total_amount += amount;					\
            total_price += price * amount;   				\
   	    ++total_number;                   				\
          }                           					\
        while(false)


#define DECREMENT_TOTAL							\
	do								\
          {								\
            total_amount -= amount;					\
   	    total_price -= price * amount;				\
   	    --total_number;						\
          }								\
        while(false)


/*
*/

#endif
