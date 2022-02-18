#ifndef STORABLE_H
#define STORABLE_H

/*
*/


#include <iostream>
#include <string>
#include <cstring>	// stricmp


#define DEFAULT_STORABLE_NAME	"bez imena"


class Storable
 { private:
   	string name;

   public:
   	Storable(char const * const in_name = DEFAULT_STORABLE_NAME)
                                                       { name = in_name;    }
        Storable(Storable const & other)               { name = other.name; }
        virtual ~Storable();

	virtual Storable & operator=(Storable const & other);

        string const & get_name() const			{ return name;      }
        void set_name(char const * const in_name = DEFAULT_STORABLE_NAME)
                                                        { name = in_name;   }
 };


ostream & operator<<(ostream & stream, Storable const & storable);


/*
*/

#endif

