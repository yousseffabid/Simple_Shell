#include "shell.h"
/**
 * free_path - free path
 * @tokens: array of strings
 * Return:void
 */
void free_path(char **tokens)
{
	free(tokens[0]);
	free(tokens);
}
/**
 * free_list - free list
 * @list: singly linked list
 * Return: void
 */
void free_list(path *list)
{
	path *holder;

	while (list != NULL)
	{
		holder = list;
		list = list->next;
		free(holder->path_name);
		free(holder);
	}
}
