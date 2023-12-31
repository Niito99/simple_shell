#include "main.h"
/**
 * execute_command - forks a process and executes a command
 * @line: the command read from std in
 *
 * Return: void
 */

void execute_command(const char *line)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		print_sign("Error forking process.\n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		char *args[128];
		int i = 0;
		char *token = strtok((char *)line, " ");

		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;

		if (execvp(args[0], args) == -1)
		{
			fprintf(stderr, "./hsh: %d: %s: not found\n", i, args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
