#ifndef MAIN_H_
#define MAIN_H_

/* Includes */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Prototypes */

void display(void);
void print_sign(const char *message);
void execute_command(const char *line);
void read_command(char *line, size_t len);



#endif /* MAIN_H */
