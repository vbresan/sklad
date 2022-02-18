#ifdef __STRICT_ANSI__
#undef __STRICT_ANSI__
#endif


#include "./include/startup.h"
#include "./include/err.h"
#include "./include/txt_strt.h"
#include <unistd.h>
#include <climits>

using namespace std;


void StartUp::save_startDir()
 { char * tmp;

   tmp = new char [PATH_MAX + 1];
   if(!tmp)
     {
       cerr << TXT_ERR_NOMEM << endl;
       exit(ERR_NOMEM);
     }

   if(getcwd(tmp, PATH_MAX))
       startDir = tmp;

   delete [] tmp;
 }


void StartUp::save_workDir(char const * const path)
 {
   workDir = path;
   workDir = workDir.substr(0, workDir.rfind('/'));
 }


StartUp::StartUp(char const * const path)
 {

   startDir = "";
   workDir = "";

   save_startDir();
   save_workDir(path);

   /* udji u work dir
   */
   if(chdir(workDir.c_str()))
     {
       perror(TXT_PERR_WORKDIR);
       exit(ERR_WORKDIR);
     }
 }



StartUp::~StartUp()
 {
   /* premjesti se u start dir
   */
   if(startDir.length())
       if(chdir(startDir.c_str()))
      	   perror(TXT_PERR_STARTDIR);
 }

