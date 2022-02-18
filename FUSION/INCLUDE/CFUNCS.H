#ifndef CFUNCS_H
#define CFUNCS_H

/*
*/

#include <limits.h>	// USHRT_MAX
#include <stdio.h>	// NULL
#include <stdlib.h>	// atof
#include <ctype.h>	// isspace
#include <string.h>	// strpbrk, strncpy, strchr

#include "article.h"
#include "ferrcfun.h"


#define STR_BRK_SET		"\t "
#define MAX_NAME_LENGHT		30


char               CHprocess_line(char * line, Article ** ppArt_new);
char             * PCHcut_leading_whitespace(char * pchStr);
unsigned short int US_from_str(char * pchStr);
Article          * PARTcreate_new_art(unsigned short amount,
                                      double price, char * name);



/*
*/

#endif

