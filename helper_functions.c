#include "main.h"
/**
 * _strcmp - this function compares two strings
 *
 * @s1: dest string
 * @s2: src string
 *
 * Return: result
 */
int _strcmp(char *s1, char *s2)
{
	int result = 0;
	int i = 0;

	while ((s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i])
	{
		i++;
	}
	if (s1[i] == s2[i])
		result = 0;
	else
		result = s1[i] - s2[i];
	return (result);
}
/**
 * _strlen - finds the lenght of a string
 * @c: string given;
 *
 * Return: string length
 */
int _strlen(char *c)
{
	int i = 0;

	while (c[i] != '\0')
		i++;

	return (i);
}
/**
 * concat_path - concatenate the $PATH variable
 * with a '/' and input given
 * @tempToken: tokenized $PATH
 * @bufferIn: input
 *
 * Return: pointer to string concatenade
 */
char *concat_path(char *tempToken, char *bufferIn)
{
	char *buffer = NULL;
	int bufSize = 0;
	int tokSize = 0;

	tokSize = _strlen(tempToken);
	bufSize = _strlen(bufferIn);

	buffer = calloc((tokSize + bufSize) + 2, sizeof(char));
	if (buffer == NULL)
		return (NULL);

	_strcpy(buffer, tempToken);

	_strcat(buffer, "/");

	_strcat(buffer, bufferIn);

	return (buffer);
}

/**
 * *_strcpy - this function return the legth of a string
 *
 * @dest: where the source need to be copied
 * @src: source of the string
 *
 * Return: Dest ponter
 */
char *_strcpy(char *dest, char *src)
{
	int length;

	for (length = 0; src[length] != '\0'; length++)
	{
		dest[length] = src[length];
	}
	dest[length] = src[length];
	return (dest);
}

/**
 * _strcat - this function concatnates two strings
 *
 * @dest: dest string
 * @src: src string
 *
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	int length = 0;
	int length2 = 0;

	while (dest[length] != '\0')
	{
		length++;
		if (dest[length] == '\0')
		{
			while (src[length2] != '\0')
			{
				dest[length] = src[length2];
				length++;
				length2++;
			}
			dest[length] = '\0';
		}
	}
	return (dest);
}
