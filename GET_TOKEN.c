#include "shell.h"

/**
 * GET_TOKEN - GET  TOKEN OF THE STRING
 * 
 * @PTRLINE: COMMON USERS
 * 
 * Return: TO THE POINTER
 */

char **GET_TOKEN(char *PTRLINE)

{
	char **USERCOMMAND = NULL;
	char *TOKEN = NULL;
	size_t w = 0;
	int SIZE = 0;

	if (PTRLINE == NULL)
		return (NULL);

	for (w = 0; PTRLINE[w]; w++)

	{
		if (PTRLINE[w] == ' ')
			SIZE++;
	}

	if ((SIZE + 1) == strlen(PTRLINE))
		return (NULL);

	USERCOMMAND = malloc(sizeof(char *) * (SIZE + 2));
	if (USERCOMMAND == NULL)
		return (NULL);

	TOKEN = _tokenstr(PTRLINE, " \z\t\r");
	for (w = 0; TOKEN != NULL; w++)

	{
		USERCOMMAND[w] = TOKEN;
		TOKEN = _tokenstr(NULL, " \z\t\r");
	}

	USERCOMMAND[w] = NULL;
	return (USERCOMMAND);

}
