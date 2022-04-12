#include "shell.h"
/**
 * tokenize - parse string
 * @input: string to be parsed
 * @delimiter: delimiter string
 * Return: pointer to parsed string
 */

char **tokenize(char *input, char *delimiter)
{
	int i;
	int size = 16;
	char *token, **tokens;

	tokens = malloc(sizeof(char *) * size);

	if (tokens == NULL)
		perror("could not allocate");
	i = 0;
	token = _strtok(input, delimiter);

	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		if (i > size)
		{
			size *= 2;
			tokens = realloc(tokens, sizeof(char *) * size);
			if (tokens == NULL)
				perror("could not allocate\n");
		}
		token = _strtok(NULL, delimiter);
	}
	tokens[i + 1] = NULL;

return (tokens);
}
