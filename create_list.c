#include "shell.h"
/**
 * create_list - creates a singly linked list
 * @tokens: array of strings
 * Return: pointer to the 1st node of the list
 */

path *create_list(char **tokens)
{
	path *head, *ptr, *new_node;
	int i;
	char *copy_pathname;

	head = NULL;
	i = 1;
	while (tokens[i] != NULL)
	{
		new_node = malloc(sizeof(path));
		if (new_node == NULL)
		{
			perror("Could not allocate");
			return (NULL);
		}
		copy_pathname = malloc(sizeof(char) * _strlen(tokens[i]) + 1);
		_strcpy(copy_pathname, tokens[i]);
		new_node->path_name = copy_pathname;
		new_node->next = NULL;

		if (head == NULL)
		{
			head = new_node;
			ptr = head;
		}
		else
		{
			while (ptr->next != NULL)
				ptr = ptr->next;
			ptr->next = new_node;
		}
		i++;
	}

	return (head);
}
