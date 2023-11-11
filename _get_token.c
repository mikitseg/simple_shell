#include "shell.h"
/**
 * _token_get - get token of string
 * @ptrline: comman user   //lineptr1
 * Return: To a pointer
 */

char **_token_get(char *ptrline) //_get_token1
{
	char **user_command = NULL;
	char *token = NULL;
	size_t w = 0;
	int size = 0;

	if (ptrline == NULL)
		return (NULL);

	for (w = 0; ptrline[w]; w++)
	{
		if (ptrline[w] == ' ')
			size++;
	}
	if ((size + 1) == _strlen(ptrline))
		return (NULL);
	user_command = malloc(sizeof(char *) * (size + 2));
	if (user_command == NULL)
		return (NULL);

	token = _tokenstr(ptrline, " \z\t\r");
	for (w = 0; token != NULL; w++)
	{
		user_command[w] = token;
		token = _tokenstr(NULL, " \z\t\r");
	}
	user_command[w] = NULL;
	return (user_command);
}

