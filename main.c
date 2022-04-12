#include "shell.h"
/**
 * main - the main function
 *@argc: the number of arguments
 *@argv: pointer to string arguments
 * Return: on success 0
 * on failure we exit loop
 */
int main(int argc, char **argv)
{
	char **tokens, *input, **parsed_path;
	size_t size;
	path *list_env;

	(void)argc;
	input = NULL;
	size = 0;
	signal(SIGINT, signal_handler);
	list_env = create_list(environ);
	parsed_path = get_path(list_env, "PATH");
	while (1)
	{
		if (isatty(STDIN_FILENO))
			_puts("$ ");
		if (_getline(&input, &size, stdin) == -1 || input[0] == '\0')
		{
			free_list(list_env);
			free_path(parsed_path);
			free(input);
			exit(0);
		}
		if (_strcmp(input, "\n") == 1)
		{
			free(input);
			continue;
		}
		else
		{
			tokens = tokenize(input, " \n\a\r\t");
			exec_cmd(tokens, argv, list_env, parsed_path);
			free(input);
			free(tokens);
		}
	}
}
