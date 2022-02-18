#include "./include/storable.h"

using namespace std;


Storable::~Storable()
 {
 }


Storable & Storable::operator=(Storable const & other)
 {
   if(this != &other)
       name = other.name;

   return *this;
 }


ostream & operator<<(ostream & stream, Storable const & storable)
 {
   return stream << storable.get_name();
 }

