#ifndef STARTUP_H
#define STARTUP_H

/*
*/

#include "txt_strt.h"
#include "err.h"

#include <cstdio>	// stderr, stdout, fprintf, NULL, perror
#include <unistd.h>	// getcwd(NA), chdir(NA)
#include <cstring>	// strrchr
#include <climits>	// PATH_MAX


class StartUp
 { private:
   	char * startDir;
        char * workDir;

        void save_startDir();
        void save_workDir(char * work_dir);

   public:
   	StartUp(char * path);
        ~StartUp();
 };

/*
*/

#endif
