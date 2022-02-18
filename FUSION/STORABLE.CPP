#include "./include/storable.h"

using namespace std;


Storable::Storable(char const * const in_name)
 {
   name = in_name;
 }


Storable::Storable(Storable const & other)
 {
   name = other.name;
 }


Storable::~Storable()
 {
 }


Storable & Storable::operator=(Storable const & other)
 {
   if(this != &other)
       name = other.name;

   return (*this);
 }


char Storable::save(FILE * pf)
 {
   fprintf(pf, "%s\n", name.c_str());

   return (0);
 }


bool operator==(Storable const & left, Storable const & right)
 {
   return (!stricmp((left.get_name()).c_str(), (right.get_name()).c_str()));
 }


bool operator!=(Storable const & left, Storable const & right)
 {
   return (stricmp((left.get_name()).c_str(), (right.get_name()).c_str()));
 }


bool operator>(Storable const & left, Storable const & right)
 {
   return (left.get_name() > right.get_name());
 }


bool operator<(Storable const & left, Storable const & right)
 {
   return (left.get_name() < right.get_name());
 }


ostream & operator<<(ostream & stream, Storable const & storable)
 {
   return stream << storable.get_name();
 }

