#ifndef STORABLE_H
#define STORABLE_H

/*
*/


#include <cstdio>	// FILE, fprintf
#include <iostream>
#include <string>
#include <cstring>	// stricmp


#define DEFAULT_STORABLE_NAME	"bez imena"


class Storable
 { private:
   	string name;

   public:
   	Storable(char const * const in_name = DEFAULT_STORABLE_NAME);
        Storable(Storable const & other);
        virtual ~Storable();

	virtual Storable & operator=(Storable const & other);

        string const & get_name() const			{ return name;    }
        void set_name(char const * const in_name = DEFAULT_STORABLE_NAME)
        						{ name = in_name; }
        virtual char save(FILE * pF);
 };


bool operator==(Storable const & left, Storable const & right);
bool operator!=(Storable const & left, Storable const & right);
bool operator>(Storable const & left, Storable const & right);
bool operator<(Storable const & left, Storable const & right);
ostream & operator<<(ostream & stream, Storable const & storable);


/*
*/

#endif

