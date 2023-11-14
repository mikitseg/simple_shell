#include "shell.h"

/**
 * main - MAIN ARGUMENT FUNCTIONS
 * @QW: COUNT OF THE ARGUMENTS
 * @avr: THE ARGUMENTS
 * @ENVIRO: ENVIRONMENT
 * Return: -EXIT = 0
 */

int main(int QW, char **avr, char **ENVIRO)
{
	char *GET_COMMAND = NULL, **USER_COMMANDS = NULL;
	int PATH_VALUE = 0, EXIT = 0, z = 0;
	(void)QW;

	while (1)
	{
		GET_COMMAND = GET_LINE_COMMAND();
		if (GET_COMMAND)
		{
			PATH_VALUE++;
			USER_COMMANDS = GET_TOKEN(GET_COMMAND);
			if (!USER_COMMANDS)
			{
				free(GET_COMMAND);
				continue;
			}
			if ((!STRCOMP(USER_COMMANDS[0], "exit")) && USER_COMMANDS[1] == NULL)
				close_command(USER_COMMANDS, GET_COMMAND, EXIT);
			if (!STRCOMP(USER_COMMANDS[0], "ENVIRO"))
				GET_ENVIRO(ENVIRO);
			else
			{
				z = NEW_PATH(&USER_COMMANDS[0], ENVIRO);
				EXIT = fork_function(USER_COMMANDS, avr, ENVIRO,
					GET_COMMAND, PATH_VALUE, z);
				if(z == 0)
					free(USER_COMMANDS[0]);
			}
			free(USER_COMMANDS);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "z", 1);
			exit(EXIT);
		}
		free(GET_COMMAND);
	}
	return (-EXIT);
}
