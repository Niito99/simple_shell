#include "main.h"
/**
 * main - entry point to the simple shell program
 *
 * Return: an int
 */

int main(void)
{
	char line[128];
	int interactive_mode = isatty(STDIN_FILENO);

	while (true)
	{
		if (interactive_mode)
			display();
		read_command(line, sizeof(line));
		if (line[0] == 'e' && line[1] == 'x' && line[2] == 'i' && line[3] == 't')
		{
			if (line[4] == '\0')
				exit(0);
			else
				exit(2);
			exit(2);
		}
		if (*line == ' ')
			exit(0);
		execute_command(line);
	}
	return (0);
}
