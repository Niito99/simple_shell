#include "main.h"
/**
 * one - handles command with slash
 * @command: string entered in the command line
 *
 * Return: void
 */

void one(const char *command)
{
	if (strchr(command, '/') != NULL)
	{
		char *args[64];
		char *token = strtok((char *)command, " ");
		int i = 0;

		while (token != NULL && i < 63)
		{
			args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		args[i] = NULL;

		if (access(args[0], X_OK) == 0)
		{
			pid_t pid = fork();

			if (pid < 0)
				exit(EXIT_FAILURE);
			else if (pid == 0)
			{
				if (execv(args[0], args) == -1)
					exit(EXIT_FAILURE);
			}
			else
			{
				int status;

				waitpid(pid, &status, 0);
			}
		}
		else
			printf("command not found: %s\n", command);

	}

}
