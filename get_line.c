#include "main.h"
/**
 * _spaces - verify if buffer is only spaces
 * @buffer: buffer input
 *
 * Return: 0 if are only spaces, -1 otherwise
 */
int _spaces(char *buffer)
{
	int i = 0;

	while (buffer[i] != '\0')
	{
		if (buffer[i] != ' ' && buffer[i] != '\t')
			return (-1);
		i++;
	}
	return (0);
}
/**
 * get_line - get the input from user
 * @buffer: where the output will get store
 * @bufCopy: a copy of the entire buffer
 * @env: a pointer to enviroment variables
 * Return: 1 or 0
 */
int get_line(char *buffer, char *bufCopy, char **env)
{
	size_t bufSize = 280;
	int getRet = 0, i = 0;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
		getRet = getline(&buffer, &bufSize, stdin);
		strtok(buffer, "\n");
		if (getRet == EOF)
		{
			write(STDOUT_FILENO, "\n", 1);
			return (1);
		}
	}
	else
	{
		getRet = getline(&buffer, &bufSize, stdin);
		strtok(buffer, "\n");
	}
	if (_strcmp(buffer, "exit") == 0 || getRet == EOF)
		return (1);
	if (_strcmp(buffer, "\n") == 0 || _spaces(buffer) == 0)
	{
		free(bufCopy);
		free(buffer);
		return (-1);
	}
	if (_strcmp(buffer, "env") == 0)
	{
		while (env[i] != NULL)
		{
			write(STDOUT_FILENO, env[i], _strlen(env[i]));
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
	}
	return (0);
}
