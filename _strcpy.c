#include "shell.h"
/**
 * *_strcpy - copy a string
 * @dest: char
 * @src : char
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	char *holder;

	if (src == NULL)
		return (NULL);
	holder = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (holder);
}
