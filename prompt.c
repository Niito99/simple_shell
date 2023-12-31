#include "main.h"
/**
 * read_command - reads the command from standard input
 * @line: accepts no parameter.
 * @len: length
 *
 * Return: void
 */
void read_command(char *line, size_t len)
{
	if (fgets(line, len, stdin) == NULL)
	{
		if (feof(stdin))
		{
			print_sign("");
			exit(EXIT_SUCCESS);
		}
		else
		{
			print_sign("Error while reading input.");
			exit(EXIT_FAILURE);
		}
	}
	line[strcspn(line, "\n")] = '\0';
}
