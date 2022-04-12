#include "shell.h"
/**
 * _putchar - prints a character to the stdin
 * @c: character
 * Return: void
 */
void _putchar(char c)
{
	write(1, &c, 1);
}

/**
 * _puts - prints a string  to the stdin
 * @string: output to be printed
 * Return: void
 */
void _puts(char *string)
{
	int i;

	for (i = 0; string[i] != '\0'; i++)
	{
		write(STDOUT_FILENO, &(string[i]), 1);
	}
}
