#include "./include/startup.h"
#include "./include/storage.h"


extern void allegro_startup();

void initialize_table();


Storage * pCurr_Storage;
char    ** ppch;


void * operator new(size_t size)
 { void * pv = malloc(size);

   return (pv);
 }


void initialize_table()
 { unsigned short int i;

   i = 0;

   ppch = new (char *) [Article::get_total_number()];

   for(i = 0; i < Article::get_total_number(); ++i)
       ppch[i] = new char [75];

   pCurr_Storage->print(ppch);
 }



int main(int, char *argv[])
 { StartUp startup(argv[0]);
   Storage storage;

   pCurr_Storage = &storage;

   initialize_table();

   allegro_startup();

   return (0);
 }

