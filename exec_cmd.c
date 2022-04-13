#include "shell.h"
/**
 * exec_cmd - executes command
 * @tokens: array of strings(input)
 * @argv: array of argument strings
 * @list_env: pointer to 1st node of the list
 * @parsed_path: pointer to parsed string
 * Return: void
 */

void exec_cmd(char **tokens, char **argv, path *list_env, char **parsed_path)
{
	pid_t id_child;
	int status;
	char *tmp;

	if (tokens[0] == NULL)
		return;
	if (check_builtin(tokens, list_env) != 1)
	{
		tmp = tokens[0];
		tokens[0] = check_path(tokens[0], parsed_path);
		if (tokens[0] != NULL)
		{
			id_child = fork();
			if (id_child < 0)
			{
				perror("Error forking");
				free(tokens[0]);
				return;
			}
			if (id_child == 0)
			{
				if (execve(tokens[0], tokens, environ) == -1)
					return;
			}
			else
			{
				wait(&status);
				if (_strcmp(tmp, tokens[0]) == -1)
					free(tokens[0]);
			}
		}
		else
			print_error(argv, tmp);
	}

}
