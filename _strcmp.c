#include "shell.h"
/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 1 if the strings are the same else -1
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (-1);
		s1++;
		s2++;
	}
	return (1);
}
/**
 * compare_env - conpares the input environement with existing env
 * @env: existing env
 * @input_env: input environement
 * Return: 1 if the env are the same else -1
 */
int compare_env(char *env, char *input_env)
{
	while (*env != '=' && *input_env != '\0')
	{
		if (*env != *input_env)
			return (-1);
		env++;
		input_env++;
	}
	if (*env != '=' || *input_env != '\0')
		return (-1);

	return (1);
}
