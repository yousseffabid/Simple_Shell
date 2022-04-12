#include "shell.h"
/**
 * _getline - reads input and put it in a string
 * @lineptr: allocated memory for input
 * @n: size of allocated memory
 * @stream: input
 * Return: on success the number of character read, -1 on failure
 */
int _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *line, *string;
	size_t size, i, flag;

	if (n == NULL || stream == NULL)
	{
		perror("no input");
		return (-1);
	}
	flag = 0;
	size = 30;
	i = 0;
	line = malloc(sizeof(char) * 2);
	string = malloc(sizeof(char) * size);
	if (line == NULL || string == NULL)
		return (-1);
	while (read(STDIN_FILENO, line, 1) > 0)
	{
		if (line[0] != ' ' && line[0] != '\t')
			flag = 1;
		if (flag == 1)
			string[i++] = line[0];
		if (line[0] == '\n')
			break;
		if (i > size)
		{
			size *= 2;
			string = realloc(string, size);
			if (string == NULL)
				return (-1);
		}
	}
	string[i] = '\0';
	*lineptr = string;
	*n = i;
	free(line);
	return (i);
}
