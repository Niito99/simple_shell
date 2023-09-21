#include "main.h"
/**
 * two - handles path for command entered
 * @command: string entered in the command line
 *
 * Return: void
 */

void two(const char *command)
{
	char *path_env = getenv("PATH");
	char *path = copy(path_env);
	char *token = strtok(path, ":");
	bool command_found = false;
	pid_t pid;

	while (token != NULL)
	{
		char full_path[256];

		snprintf(full_path, sizeof(full_path), "%s/%s", token, command);
		if (access(full_path, X_OK) == 0)
		{
			command_found = true;
			pid = fork();

			if (pid < 0)
				exit(EXIT_FAILURE);
			else if (pid == 0)
			{
				char *exec_args[2];

				exec_args[0] = copy(full_path);
				exec_args[1] = NULL;
				if (execv(full_path, exec_args) == -1)
					exit(EXIT_FAILURE);
			}
			else
			{
				int status;

				waitpid(pid, &status, 0);
			}
			break;
		}
		token = strtok(NULL, ":");
	}
	free(path);
	if (!command_found)
		printf("command not found: %s\n", command);
}
