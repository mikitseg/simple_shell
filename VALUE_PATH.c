#include "shell.h"

/**
 * NEW_PATH - SEPARATE THE PATH IN NEW STRINGS.
 * @path: COMMANDS INPUT OF THE USER
 * @envir: THE ENVIRONMENT
 * Return: A POINTER TO STRINGTH.
 */

int NEW_PATH(char **path, char **envir)

{
	char *TOKEN = NULL, *PATH_REL = NULL, *PATH_ABS = NULL;
	size_t PATH_VALUE, COMMANDS;
	struct stat status_line_ptr;

	if (stat(*path, &status_line_ptr) == 0)
		return (-1);
PATH_REL = path_get(envir);

	if (!PATH_REL)
		return (-1);

	TOKEN = TOKEN_STR(PATH_REL, ":");
	COMMANDS = STRLENG(*path);
	while (TOKEN)
	{
		PATH_VALUE = STRLENG(TOKEN);
		PATH_ABS = malloc(sizeof(char) * (PATH_VALUE + COMMANDS + 2));
		if (!PATH_ABS)
		{
			free(PATH_REL);
			return (-1);
		}
		PATH_ABS = COPY_STR(PATH_ABS, TOKEN);
		STRNCAT_S(PATH_ABS, "/");
		STRNCAT_S(PATH_ABS, *path);

		if (stat(PATH_ABS, &status_line_ptr) == 0)

		{
			*path = PATH_ABS;
			free(PATH_REL);
			return (0);
		}

		free(PATH_ABS);
		TOKEN = TOKEN_STR(NULL, ":");
	}
	free(PATH_REL);
	return (-1);
}
