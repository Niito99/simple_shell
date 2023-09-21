#include "main.h"

/**
 * main - entry point of the shell program.
 *
 * Description: this program is a Simple Interactive Shell Program.
 *
 * Return: 0 upon successful exeution.
 */

int main(void)
{
	ssize_t read;
	char *line = NULL;
	size_t n = 0;

	while (1)
	{
		prompt();
		read = getline(&line, &n, stdin);

		if (read == -1)
		{
			printf("\n");
			free(line);
			break;
		}
		line[strcspn(line, "\n")] = '\0';

		exec(line);
	}
	return (0);
}
