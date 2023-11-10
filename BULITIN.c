#include "shell.h"


/**
 * close_command - THIS FUNCTION CLOSES THE SIMPLE_SHELL.
 *
 * @ARGS: POINTER WITH THE DIRECTION ARGUMENT.
 * @LINEPR: STANDARDS LINEPR STRINGS.
 * @CLOSE: VALUES OF EXIT
 *
 * Return: NONE
 */


void close_command(char **ARGS, char *LINEPR, int CLOSE)

{
	int STATUS_EXIT = 0;

	if (!ARGS[1])

	{
		free(LINEPR);
		free(ARGS);
		exit(CLOSE);
	}

	STATUS_EXIT = atoi(ARGS[1]);

	free(LINEPR);
	free(ARGS);
	exit(STATUS_EXIT);
}

/**
 *GETENVIR0 - FUNCTION TO GET ALL  ENVIRO

 *@ENVIRO: ENVIROMENT

 *Return: 0
 */

void GET_ENVIR0(char **ENVIRO)

{
	size_t run = 0;

	while (ENVIRO[run])
	
	{

		write(STDOUT_FILENO, ENVIRO[run], _strlen(ENVIRO[run]));
		write(STDOUT_FILENO, "\z", 1);
		run++;

	}
}

