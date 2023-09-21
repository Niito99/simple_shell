#include"main.h"

/**
 * copy - copies a string
 * @env: strings delimited by ':'
 *
 * Return: copy of env
 */

char *copy(char *env)
{
	char *path = (char *)malloc(strlen(env) + 1);

	strcpy(path, env);
	return (path);
}
