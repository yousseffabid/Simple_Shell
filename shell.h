#ifndef SHELL_H
#define SHELL_H

/* header files */
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>

/* Global variable */
extern char **environ;

/* struct */

/**
 * struct p - Global data structure
 * @path_name: string holding the var name and value
 * (ex: "PWD=/home/me")
 * @next: pointer to var of struct p data type
 * Description: a structure that contains the environnment var
 * and its value in a string, it helps in creating
 * a singly linked list for environment variables
 */
typedef struct p
{
	char *path_name;
	struct p *next;
} path;

/**
 * struct b - Global data structure
 * @name: name of the builtin command
 * (ex: "cd", "env")
 * @func: pointer to function that implements the command
 * Description: a structure that manages the builtin commands
 */
typedef struct b
{
	char *name;
	void (*func)(char **, path *);
} builtin;

/*----write functions----*/
void _putchar(char c);
void _puts(char *string);

/*---- Handles Ctrl-c signal----*/
void signal_handler(int sig);

/*----Free functions----*/
void free_path(char **tokens);
void free_list(path *list);

/*----string functions---*/
char *_strcpy(char *dest, char *src);
int _strlen(char *string);
char *_strchr(char *s, char c);
int _pow(int number, int exponent);
int _atoi(char *string);
int search(char character, char *delimiter);
int _strcmp(char *s1, char *s2);
char *_strtok(char *s, char *delimiter);
char *_concat(char *s1, char *s2);
char *_concat_env(char *s1, char *s2);
int compare_env(char *env, char *input_env);

/*----Read from stdin----*/
int _getline(char **lineptr, size_t *n, FILE *stream);

/*----Set and unset environment variables----*/
void _setvar(char **tokens, path *list_env);
void _unsetvar(char **tokens, path *list_env);
char **get_dir(path *list_env, char *variable);
void set_dir(char *var, char *pathname, path *list_env);

/*----Create singly linked list----*/
path *create_list(char **tokens);

/*----Prase string----*/
char **tokenize(char *string, char *delimiter);
char **get_path(path *list_env, char *variable);

/*----Builtin commands----*/
void exit_program(char **tokens, path *list_env);
void _env(char **tokens, path *list_env);
void _setenv(char **tokens, path *list_env);
void _unsetenv(char **tokens, path *list_env);
void _cd(char **tokens, path *list_env);

/*----Checker functions----*/
int check_builtin(char **tokens, path *list_env);
char *check_path(char *string, char **parsed_path);

/*----Command Executer----*/
void exec_cmd(char **tokens, char **argv, path *list_env, char **parsed_path);



/*----Prints error----*/
void print_error(char **argv, char *command);

#endif
