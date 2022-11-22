#include "main.h"
/**
 * frees - frees every argument pass
 * @bufCopy: buffer copy, we free it to tokenize again
 * @args: array of arguments pass
 * @path: the entire value of enviroment variable PATH
 * @buffer: input by user(getline)
 */
void frees(char *bufCopy, char **args, char *path, char *buffer)
{
	if (bufCopy != NULL)
	{
		free(bufCopy);
		bufCopy = NULL;
	}
	if (args != NULL)
	{
		free(args);
		args = NULL;
	}
	if (path != NULL)
	{
		free(path);
		path = NULL;
	}
	if (buffer != NULL)
	{
		free(buffer);
		buffer = NULL;
	}
}
