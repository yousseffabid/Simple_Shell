#include "shell.h"
/**
 * search - search the delimiter
 * @character: character
 * @delimiter:delimiter poiter
 * Return: 1 if charater is found else 0
 */
int search(char character, char *delimiter)
{
	while (*delimiter)
	{
		if (*delimiter == character)
			return (1);
		delimiter++;
	}
	return (-1);
}
/**
 * _strtok - breaks a string into tokens using a delimiter
 * @s: string
 * @delimiter: delimiter
 * Return: a pointer to the first token
 */
char *_strtok(char *s, char *delimiter)
{
	static char *last;
	int count, check;

	count = 0;
	if (delimiter == NULL || *delimiter == '\0')
		return (s);

	if (s == NULL)
		s = last;
	while (s != NULL && *s != '\0')
	{
		check = search(*s, delimiter);
		if (check == 1 && count != 0)
		{
			*s = '\0';
			last = s + 1;
			while (*last != '\0' && search(*last, delimiter) == 1)
				last++;
			break;
		}
		count++;
		s++;
	}
	if ((last == (s - count)) || (*last == '\0'))
		last = NULL;

	return (s - count);
}
