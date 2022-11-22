#include "main.h"
/**
 * _getenv - this function get the value of a enviroment variable
 * @name: name of the variable
 * @env: a pointer to env argument of main function
 * Return: buffer if success, NULL otherwise
 */
char *_getenv(char *name, char **env)
{
	char *buffer = NULL;
	char nameBuf[200] = {0};
	int i = 0, k = 0, x = 0, j = 0;

	while (env[i] != NULL)
	{
		while (env[i][k] != '=')
		{
			nameBuf[x] = env[i][k];
			x++;
			k++;
		}
		nameBuf[x] = '\0';
		if (_strcmp(nameBuf, name) == 0)
		{
			k++;
			buffer = _calloc(_strlen(env[i]), sizeof(char));
			if (buffer == NULL)
				return (NULL);

			while (env[i][k] != '\0')
			{
				buffer[j] = env[i][k];
				k++;
				j++;
			}
			return (buffer);
		}
		i++;
		k = 0;
		x = 0;
	}
	return (NULL);
}
