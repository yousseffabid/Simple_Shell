#include "shell.h"
/**
 * signal_handler - Receives Ctrl-c and ignores the signal
 *	@sig: signal
 *	Return: void
 */

void signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		_putchar('\n');
		_puts("$ ");
	}
}
