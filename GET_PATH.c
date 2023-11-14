#include "shell.h"

/**
 * path_get - GETS THE VARIABLE  PATH.
 *
 * @ENVIRO: THE LOCAL ENVIRONMENT
 *
 * Return: THE VALUES OF PATH.
 */


char *path_get(char **ENVIRO)

{
	size_t INDEX = 0, VARI = 0, COUNT = 5;
	char *path = NULL;

	for (INDEX = 0; _strncmp(ENVIRO[INDEX], "PATH=", 5); INDEX++);
	if (ENVIRO[INDEX] == NULL)

		return (NULL);

	for (COUNT = 5; ENVIRO[INDEX][VARI]; VARI++, COUNT++);
	path = malloc(sizeof(char) * (COUNT + 1));

	if (path == NULL)

		return (NULL);

	for (VARI = 5, COUNT = 0; ENVIRO[INDEX][VARI]; VARI++, COUNT++)

		path[COUNT] = ENVIRO[INDEX][VARI];

	path[COUNT] = '\0';

	return (path);

}

