#include "shell.h"
/**
 * _setvar - set or modify an environment variable
 * @tokens: pointer parsed input
 * @list_env: list of environment variables
 * Return: void
 */

void _setvar(char **tokens, path *list_env)
{
	char *s1, *s2;
	path *new_env, *holder;
	int flag;

	flag = 0;
	while (list_env != NULL)
	{
		if (compare_env(list_env->path_name, tokens[1])  == 1)
		{
			s1 = _concat_env(tokens[1], "=");
			free(list_env->path_name);
			list_env->path_name = _concat_env(s1, tokens[2]);
			flag = 1;
			break;
		}
		holder = list_env;
		list_env = list_env->next;
	}
	if (flag == 0)
	{
		new_env = malloc(sizeof(path));
		if (new_env == NULL)
			perror("could not set env variable, error in mem allocation");
		s1 = _concat_env(tokens[1], "=");
		if (tokens[2] == NULL)
			s2 = _concat_env(s1, "\0");
		else
			s2 = _concat_env(s1, tokens[2]);

		new_env->path_name = s2;
		new_env->next = NULL;
		holder->next = new_env;
	}
	free(s1);
}


/**
 * _unsetvar - unset an environment variable
 * @tokens: pointer parsed input
 * @list_env: list of environment variables
 * Return: void
 */

void _unsetvar(char **tokens, path *list_env)
{
	path *ptr_env, *prev_env;
	int i;

	i = 0;

	while (list_env != NULL)
	{
		i = compare_env(list_env->path_name, tokens[1]);
		if (i == 1)
		{
			ptr_env = list_env->next;
			prev_env->next = ptr_env;
			free(list_env->path_name);
			free(list_env);
			break;
		}
		prev_env = list_env;
		list_env = list_env->next;
	}
	if (i != 1)
		perror("the variable you want to unset does not exist");
}


/**
 * set_dir - updates the the PWD or OLDPWD variable
 * @var: pointer to "PWD" or "OLDPWD"
 * @pathname: pointer to the pathname "/../../"
 * @list_env: list of environment variables
 * Return: void
 */
void set_dir(char *var, char *pathname, path *list_env)
{
	char *s1;

	while (list_env != NULL)
	{
		if (compare_env(list_env->path_name, var)  == 1)
		{
			s1 = _concat_env(var, "=");
			free(list_env->path_name);
			list_env->path_name = _concat_env(s1, pathname);
			break;
		}
		list_env = list_env->next;
	}
	free(s1);
}


/**
 * get_dir - gets the pathname present in "PWD" or "OLDPWD"
 * @list_env: list of environment variables
 * @variable: variable name "PWD" or "OLDPWD"
 * Return: pointer ot pathname
 */

char **get_dir(path *list_env, char *variable)
{
	char **tokens, *copy_path_name;

	tokens = NULL;

	while (list_env != NULL)
	{
		if (compare_env(list_env->path_name, variable) == 1)
		{
			copy_path_name = malloc(sizeof(char) * _strlen(list_env->path_name) + 1);
			_strcpy(copy_path_name, list_env->path_name);
			tokens = tokenize(copy_path_name, "=:");
			break;
		}
		list_env = list_env->next;
	}
	return (tokens);
}
