#include "shell.h"
/**
 * _path_get - get variable PATH.
 * @envir: enviromente local
 * Return: value of PATH.
 */

char *_path_get(char **envir)  //_path_get
{
	size_t index = 0, var = 0, count = 5;
	char *path = NULL;

	for (index = 0; _strncmp(envir[index], "PATH=", 5); index++)
		;
	if (envir[index] == NULL)
		return (NULL);

	for (count = 5; envir[index][var]; var++, count++)
		;
	path = malloc(sizeof(char) * (count + 1));

	if (path == NULL)
		return (NULL);

	for (var = 5, count = 0; envir[index][var]; var++, count++)
		path[count] = envir[index][var];

	path[count] = '\0';
	return (path);
}
