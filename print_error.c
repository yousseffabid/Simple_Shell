#include "shell.h"
/**
 * print_error - prints error message
 * @argv: array of argument strings
 * @command: command name
 * Return: void
 */

void print_error(char **argv, char *command)
{
	(void)argv;
	_puts(command);
	_puts(": command not found\n");
}
