#ifndef _MAIN_H_
#define _MAIN_H_

/*LIBRARIES*/
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>

/*PROTOTYPES*/
char *concat_path(char *tempToken, char *bufferIn);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(char *c);
int _strcmp(char *s1, char *s2);
char *_getenv(char *name, char **env);
int get_line(char *buffer, char *bufCopy, char **env);
char **_args(int dpCount, char *bufCopy, char *buffer, int bufSize,
char tempToken[100][500]);
void frees(char *bufCopy, char **args, char *path, char *buffer);
void *_calloc(unsigned int nmemb, unsigned int size);
#endif
