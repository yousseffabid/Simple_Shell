#include "shell.h"
/**
 * get_path - parses the string value of the environament variable
 * @list_env: pointer to 1st node of the list
 * @variable: the environment variable to parse its string
 * Return: pointer to parsed string
 */

char **get_path(path *list_env, char *variable)
{
	char **tokens, *copy_path_name;
	int i;

	(void)list_env;
	tokens = NULL;
	i = 0;
	while (environ[i] != NULL)
	{
		if (compare_env(environ[i], variable) == 1)
		{
			copy_path_name = malloc(sizeof(char) * _strlen(environ[i]) + 1);
			_strcpy(copy_path_name, environ[i]);
			tokens = tokenize(copy_path_name, "=:");
			break;
		}
		i++;
	}
	return (tokens);
}
