#include "shell.h"

/**
 * ENVIRO - PRINTS The  current Environment
 * 
 * @AASTU: STRUCT Parameters
 * 
 * Return: ALWAYS 0
 */
int ENVIRO(Information_t *AASTU)
{
	PRINT_LIST_STRING(AASTU->ENV_LOC);
	return (0);
}

/**
 * GET_ENVIRO - GETS the variable Environment Values
 * 
 * @AASTU: STRUCT Parameters
 * @Name: IT'S The Name Of Environment Variable
 *
 * Return: The Values
 */
char *GET_ENVIRO(Information_t *AASTU, const char *Name)
{
	list_t *NODES = AASTU->ENV_LOC;
	char *q;

	while (NODES)
	{
		q = START_WITH(NODES->str, Name);
		if (q && *q)
			return (q);
		NODES = NODES->next;
	}
	return (NULL);
}

/**
 * SET_ENVIRO - SET THE New Environmet Variable, Modify Existing One
 * 
 * @AASTU: Struct Parameters
 * 
 * Return: ALWAYS 0
 */

int SET_ENVIRO(Information_t *AASTU)
{
	if (AASTU->argc != 3)

	{
		W_PUTS("Incorrect number of arguements\n");
		return (1);
	}

	if (_SET_ENVIRO(AASTU, AASTU->argv[1], AASTU->argv[2]))
		return (0);
	return (1);
}

/**
 * UNSSET_ENVIRO - UNSETS the enviromet variable
 * 
 * @AASTU: STRUCT Parameters
 * 
 * Return: ALWAYS 0
 */
int UNSSET_ENVIRO(Information_t *AASTU)
{
	int U;

	if (AASTU->argc == 1)
	{
		W_PUTS("very few arguements.\n");
		return (1);
	}
	for (U = 1; U <= AASTU->argc; U++)
		_UNSET_ENVIRO(AASTU, AASTU->argv[U]);

	return (0);
}

/**
 * ENV_POPUL - USED for Population Of the Linked List
 * 
 * @AASTU: STRUCT Parameters
 * 
 * Return: ALWAYS 0
 */
int ENV_POPUL(Information_t *AASTU)
{
	list_t *NODES = NULL;
	size_t U;

	for (U = 0; ENVIRONM[U]; U++)
		NODEADD_ATEND(&NODES, ENVIRONM[U], 0);
	AASTU->ENV_LOC = NODES;
	return (0);
}

