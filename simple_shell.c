#include "main.h"
/**
 * main - this is a simple shell
 * @argc: number of arguments(unused)
 * @argv: name of every argument(unused)
 * @env: enviroment variables
 * Return: 0 on success
 */
int main(__attribute__((unused))int argc,
__attribute__((unused))char *argv[], char **env)
{
	size_t bufSize = 10000, pathSize = 0;

	int i = 0, j = 0, k = 0, dpCount = 0, getRet = 0;
	char *buffer = NULL, *path = _getenv("PATH", env), *bufCopy = NULL;
	char tempToken[100][500] = {{0}};
	char **args = NULL;

	signal(SIGINT, SIG_IGN);
	while (1)
	{
		i = 0, k = 0, j = 0, dpCount = 0, pathSize = 10000;
		bufCopy = _calloc(pathSize + 1, sizeof(char));
		if (bufCopy == NULL)
			return (1);
		buffer = _calloc(bufSize + 1, sizeof(char));
		if (buffer == NULL)
		{
			free(bufCopy);
			return (1);
		}
		getRet = get_line(buffer, bufCopy, env);
		if (getRet == 1)
			break;
		if (getRet == -1)
			continue;
		while (path[i])
		{
			while (path[i] != ':' && path[i] != '\0')
			{
				tempToken[k][j] = path[i];
				j++, i++;
			}
			dpCount++, i++, k++, j = 0;
		}
		args = _args(dpCount, bufCopy, buffer, bufSize, tempToken);
		frees(bufCopy, args, NULL, buffer);
	}
	frees(bufCopy, NULL, path, buffer);
	exit(EXIT_SUCCESS);
}
