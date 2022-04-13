#include "shell.h"
/**
 * _strlen - counts the length of a string
 * @string: input
 * Return: string legth
 */
int _strlen(char *string)
{
	int i;

	for (i = 0; string[i] != '\0'; i++)
		;
	return (i);
}
/**
 * _concat - concatenates two strings adding a '/' between them
 * @s1: first string
 * @s2: second string
 * Return: concatenated string
 */
char *_concat(char *s1, char *s2)
{
	unsigned int i, j, k;
	char *string;

	i = _strlen(s1);
	j = _strlen(s2);
	string = malloc(sizeof(char) * (i + j + 2));
	if (string == NULL)
		return (NULL);
	for (k = 0; k < (i + j + 2); k++)
	{
		if (k < i)
			string[k] = s1[k];
		else if (k == i)
			string[k] = '/';
		else
			string[k] = s2[k - i - 1];
	}
	return (string);

}
/**
 * _concat_env - concatenates two strings adding a / between them
 * @s1: first string
 * @s2: second string
 * Return: concatenated string
 */
char *_concat_env(char *s1, char *s2)
{
	unsigned int i, j, k;
	char *string;

	i = _strlen(s1);
	j = _strlen(s2);
	string = malloc(sizeof(char) * (i + j + 1));
	if (string == NULL)
		return (NULL);
	for (k = 0; k < (i + j + 1); k++)
	{
		if (k < i)
			string[k] = s1[k];
		else
			string[k] = s2[k - i];
	}
	return (string);
}
