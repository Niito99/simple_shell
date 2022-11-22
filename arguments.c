#include "main.h"
/**
 * _args - this function takes the command and its arguments
 * and concatenates with the respective path and executes
 * @bufCopy: buffer copy to tokenize
 * @buffer: buffer obtain by getline
 * @bufSize: buffer size
 * @dpCount: count of all posible paths where exec files exist
 * @tempToken: array of strings that contain every path
 * Return: an array of strings that contain every argument
 */
char **_args(int dpCount, char *bufCopy, char *buffer, int bufSize,
char tempToken[100][500])
{
	struct stat statBuf;
	int x = 0, i = 0, status = 0;
	char *concatBuf, *out = NULL;
	char **args = NULL;

	args = _calloc(bufSize + 1, sizeof(char *));
	if (args == NULL)
		return (NULL);
	_strcpy(bufCopy, buffer);
	out = strtok(bufCopy, " \t\r\n\f");
	while (out != NULL)
	{
		args[i] = out;
		out = strtok(NULL, " \t\r\n\f");
		i++;
	}
	if (stat(args[0], &statBuf) == 0)
	{
		if (fork() == 0)
			execve(args[0], args, NULL);
		wait(&status);
		return (args);
	}
	while (x < dpCount)
	{
		concatBuf = concat_path(tempToken[x], args[0]);
		if (stat(concatBuf, &statBuf) == 0)
		{
			if (fork() == 0)
				execve(concatBuf, args, NULL);
			wait(&status);
			free(concatBuf);
			break;
		}
		x++;
		free(concatBuf);
	}
	if (x == dpCount)
		perror("Error");
	return (args);
}
