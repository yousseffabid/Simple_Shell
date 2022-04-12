#include "shell.h"

/**
 * check_path - checks if the command is found in one of
 * the pathnames present in the PATH variable
 * @string: pointer to command string
 * @parsed_path: pointer to tokens of the parsed string that
 * contains the the value of the varible PATH
 * Return: absolute pathname of the command or NULL
 * if the command is not found
 */

char *check_path(char *string, char **parsed_path)
{
	char *pathname, *tmp;
	struct stat st;
	int i;

	pathname = NULL;
	if (_strcmp(string, "./ls") == 1)
		pathname = string;

	else
	{
		if (string[0] == '/')
		{
			if (stat(string, &st) == 0)
				pathname = string;
		}
		else
		{
			i = 0;
			while (parsed_path[i] != NULL)
			{
				tmp = _concat(parsed_path[i], string);

				if (stat(tmp, &st) == 0)
				{
					pathname = tmp;
					break;
				}
				else
					free(tmp);

				i++;
			}
		}
	}
	return (pathname);
}
