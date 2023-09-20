#ifndef _MAIN_H_
#define _MAIN_H_

#define MAX_PATH_SIZE 1024

/* HEADERS */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>


/* PROTOTYPES */
void exec(const char *command);
void prompt(void);


#endif

