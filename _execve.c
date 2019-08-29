#include "simple_shell.h"
/**
* concat - concatenate strings
* @s1: pointer to args1
* @s2: pointer to args2
* Return: char result
*/
char *concat(char *s1, char *s2)
{
	char *result = malloc(strlen(s1) + strlen(s2) + 1);

	_strcpy(result, s1);
	_strcat(result, s2);
	return (result);
}
/**
* get_path -  obtain path
* Return: void function.
*/
char *get_path(void)
{
	char *var;
	int i = 0;

	while (environ[i])
	{
		var = strtok(environ[i], "=");
			if (!_strcmp(var, "PATH"))
			{
				return (strtok(NULL, "="));
			}
			var = strtok(NULL, "=");
			i++;
	}
	return (NULL);
}
/**
* concat_path - concatenate path
* @args: double pointer to args
* Return: void function.
*/
char **concat_path(char **args)
{
	char *path, **paths, *tok;
	int n = 0;

	path = get_path();
	tok = strtok(path, ":");
	paths = malloc(64 * sizeof(char *));

	while (tok != NULL)
	{
		paths[n] = concat(tok, concat("/", args[0]));
		n++;
		tok = strtok(NULL, ":");
	}
	paths[n] = NULL;
	return (paths);
}
/**
* _execve -  execute program
* @args: double pointer to args
* Return: void function.
*/
void _execve(char **args)
{
	int exe, flag = 0, n = 0;
	char **path, **exec;

	path = concat_path(args);
	exe = execve(args[0], args, environ);
	exec = malloc(64 * sizeof(char *));

	/*while (path[n] != NULL)
	{
		exec[0] = path[n];
		exec[1] = NULL;
		exe = execve(exec[0], exec, environ);

		if (access(path, F_OK) != 0)
		{
			printf("'%s' does not exist!\n", path);
			flag = 1;
		}
		n++;
	}*/
	while (path[n] != NULL)
	{
		exec[0] = path[n];
		exec[1] = NULL;
		exe = execve(exec[0], exec, environ);
		if (exe != -1)
		{
			flag = 1;
		}
		n++;
	}
	printf("-->*%d\n", flag);
	if (flag == 0)
	{
		perror("Error");
		free_double(path);
		free(args[0]);
		free_double(exec);
		exit(0);
	}
	else
	{
		printf("--->%s\n", args[0]);
		free(args[0]);
		exit(127);
	}
}
