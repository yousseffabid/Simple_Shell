#include "shell.h"

/**
 * check_builtin - checks if the command is a builtin command
 * so it calls the function related to that command
 * @tokens: pointer to command strings
 * @list_env: singly linked list holding environment var
 * Return: void
 */

int check_builtin(char **tokens, path *list_env)
{
	int i;
	builtin builtin_array[] = {{"exit", exit_program}, {"env", _env},
		{"setenv", _setenv}, {"unsetenv", _unsetenv}, {"cd", _cd}};

	for (i = 0; i <= 4; i++)
	{
		if (_strcmp(builtin_array[i].name, tokens[0]) == 1)
		{
			builtin_array[i].func(tokens, list_env);
			return (1);
		}
	}
	return (-1);
}
