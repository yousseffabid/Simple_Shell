#include "shell.h"
/**
 * exit_program - exits function with status
 * @tokens: pointer to command strings
 * @list_env: singly linked list holding environment var
 * Return: void
 */

void exit_program(char **tokens, path *list_env)
{
	int status;

	status = 0;
	if (tokens[1] != NULL && tokens[2] != NULL)
		_puts("failed: command syntax\n");
	if (tokens[1] != NULL)
		status = _atoi(tokens[1]);
	free_list(list_env);
	free(tokens);

	exit(status);

}


/**
 * _env - displays all environment variables
 * @tokens: pointer to command strings
 * @list_env: singly linked list holding environment var
 * Return: void
 */

void _env(char **tokens, path *list_env)
{

	if (tokens[1] != NULL)
	{
		_puts("failed: command syntax\n");
		return;
	}
	if (list_env == NULL)
		return;
	set_dir("_", "/usr/bin/env", list_env);
	while (list_env != NULL)
	{
		_puts(list_env->path_name);
		_putchar('\n');
		list_env = list_env->next;
	}
}


/**
 * _setenv -  checks if after typing "setenv" command we wrote the name
 * of the var to ommit in order to call the _setvar function or
 * just prompts an error msg.
 * @tokens: pointer to command strings
 * @list_env: singly linked list holding environment var
 * Return: void
 */

void _setenv(char **tokens, path *list_env)
{
		if (tokens[1] != NULL)
		{
			_setvar(tokens, list_env);
		}
		else
			_puts("You must type the name of the env variable\n");
}


/**
 * _unsetenv - checks if after typing "unsetenv" command we wrote the name
 * of the var to ommit in order to call the unsetvar function or
 * just prompts an error msg.
 * @tokens: pointer to command strings
 * @list_env: singly linked list holding environment var
 * Return: void
 */
void _unsetenv(char **tokens, path *list_env)
{
	if (_strcmp(tokens[0], "unsetenv") == 1)
	{
		if (tokens[1] != NULL)
			_unsetvar(tokens, list_env);
		else
			_puts("You must insert a variable name to unset\n");
	}
}


/**
 * _cd - changes current working directory
 * @tokens: pointer to command strings
 * @list_env: singly linked list holding environment var
 * Return: void
 */

void _cd(char **tokens, path *list_env)
{
	int value;
	char **home_path, *update_cwd;

	if (tokens[1] == NULL)
	{
		home_path = get_dir(list_env, "HOME");
		value = chdir(home_path[1]);
		free_path(home_path);
	}
	else
	{
		value = chdir(tokens[1]);
	}
	if (value == -1)
		perror("./shell");

	update_cwd = malloc(sizeof(char) * 100);
	if (update_cwd != NULL)
	{
		update_cwd = getcwd(update_cwd, 100);
		set_dir("PWD", update_cwd, list_env);
		free(update_cwd);
	}
}

