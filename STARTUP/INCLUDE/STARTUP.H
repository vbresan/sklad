#ifndef STARTUP_H
#define STARTUP_H

/*
*/

#include <string>


class StartUp
 {
   private:
   	string startDir;
        string workDir;

        void save_startDir();
        void save_workDir(char const * const work_dir);

        void perror(char const * str);

   public:
   	StartUp(char const * const path);
        ~StartUp();
 };


/*
*/

#endif

