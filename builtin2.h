#ifndef BUILTIN2_H
#define BUILTIN2_H
/**
 **builtin_execute - executes the built in functions
 **@tokens: arguments being passed
 **Return: tokens
 **/
int builtin_execute(char **tokens)
{	unsigned int  num, i, status, length = _strlen(tokens[0]);
	built_s builtin[] = {	{"exit", shell_exit},
		{"env", shell_env}, {NULL, NULL}	};

	if (tokens[0] == NULL)
		return (1);
	else if (strcmp(tokens[0], "setenv") == 0)
	{
		if (tokens[1] == NULL || tokens[2] == NULL || tokens[3] != NULL)
		{	fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
			return (0);	}
		if (setenv(tokens[1], tokens[2], 1) != 0)
		{	perror("setenv");
		}	return (0);
	}	else if (strcmp(tokens[0], "unsetenv") == 0)
	{
		if (tokens[1] == NULL || tokens[2] != NULL)
		{	fprintf(stderr, "Usage: unsetenv VARIABLE\n");
			return (0);	}
		if (unsetenv(tokens[1]) != 0)
		{	perror("unsetenv");
		}	return (0);
	}	num = shell_num_builtins(builtin);
	for (i = 0; i < num; i++)
	{
		if (_strcmp(tokens[0], builtin[i].name, length) == 0)
		{	status = (builtin[i].p)();
			return (status);
		}	}	return (1);	}
/**
 **shell_num_builtins - this check num built-ins
 **@builtin: takes the builtin to be counted
 **Return: num of built-ins
 **/
int shell_num_builtins(built_s builtin[])
{	unsigned int i = 0;

	while (builtin[i].name != NULL)
		i++;
	return (i);	}
#endif /*BUILTIN2_H */
