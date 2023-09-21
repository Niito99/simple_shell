#include "main.h"

/**
 * exec - executes a command on the command line
 * @command: string entered in the commad line
 *
 * Return: void
 */

void exec(const char *command)
{
	if (strchr(command, '/') != NULL)
	{
		one(command);
	}
	else
	{
		two(command);
	}
}
