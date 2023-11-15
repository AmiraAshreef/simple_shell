#ifndef BUILTINS_H
#define BUILTINS_H
#include "header.h"
/**
 **shell_exit - exits the shell
 **Return: void
 **/
int shell_exit(void)
{
	return (-1);
}
/**
 **shell_env - prints environment in shell
 **Return: void
 **/

int shell_env(void)
{
	unsigned int i;

	i = 0;
	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}
/**
 * child - function for child process
 * @fullpath: full path of executable
 * @tokens: tokenized user input
 * Return: 0 on success
 */
int Initiate(char *fullpath, char **tokens)
{
	pid_t child_pid;
	int status;
	int execve_status;
	char **envp = environ;

	child_pid = fork();
	if (child_pid == -1)
	{
		errors(1);
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		execve_status = execve(fullpath, tokens, envp);
		if (execve_status == -1)
			return (-1);
	}
	else
		wait(&status);

	return (0);
}
#endif /*BUILTINS_H */
