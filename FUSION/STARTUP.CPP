#include "./include/startup.h"

/*
*/


void StartUp::save_startDir()
 { char * tmp;

   tmp = new char [PATH_MAX + 1];
   if(!tmp)
     {
       fprintf(stderr, TXT_ERR_NOMEM);
       exit(ERR_NOMEM);
     }

   if(getcwd(tmp, PATH_MAX))
     {
       startDir = new char [strlen(tmp) + 1];
       if(!startDir)
         {
           fprintf(stderr, TXT_ERR_NOMEM);
           exit(ERR_NOMEM);
         }

       strcpy(startDir, tmp);
     }
   else
     {
       fprintf(stdout,TXT_ERR_STARTDIR);
       startDir = NULL;
     }

   delete [] tmp;
 }


void StartUp::save_workDir(char * path)
 {
   *(strrchr(path, '/')) = '\0';
   workDir = new char [strlen(path) + 1];
   if(!workDir)
     {
       fprintf(stderr, TXT_ERR_NOMEM);
       exit(ERR_NOMEM);
     }

   strcpy(workDir, path);
 }


StartUp::StartUp(char * path)
 {
   save_startDir();
   save_workDir(path);

   /* udji u work dir
   */
   if(chdir(workDir))
     {
       perror(TXT_PERR_WORKDIR);
       exit(ERR_WORKDIR);
     }
 }


StartUp::~StartUp()
 {
   delete [] workDir;

   /* premjesti se u start dir
   */
   if(startDir)
     {
       if(chdir(startDir))
      	   perror(TXT_PERR_STARTDIR);

       delete [] startDir;
     }
 }

