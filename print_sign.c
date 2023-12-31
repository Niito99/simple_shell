#include "main.h"

/**
 * print_sign - prints message to standard output
 *
 * @message: a constant char
 * Return: void
 */

void print_sign(const char *message)
{
	write(STDOUT_FILENO, message, strlen(message));
}
