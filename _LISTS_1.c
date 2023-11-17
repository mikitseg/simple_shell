#include "shell.h"

/**
* LIST_LENG - USED TO FIND length of the list
*
* @FIRST: POINTER TO the FIRST Nodes
*
* Return: LIST Size
*/

size_t LIST_LENG(const list_t *FIRST)
{
	size_t O = 0;

	while (FIRST)
	{
		FIRST = FIRST->next;
		O++;
	}
	return (O);
}

/**
* LIST_STRINGS - Changes the LIST TO String
*
* @FIRST: pointer to FIRST Nodes
*
* Return: STRINGS which type is  ARRAY
*/

char **LIST_STRINGS(list_t *FIRST)
{
	char *STRING;
	list_t *Nodes = FIRST;
	size_t O = LIST_LENG(FIRST), n;
	char **STR;

	if (!FIRST || !O)
		return (NULL);
	STR = malloc(sizeof(char *) * (O + 1));
	if (!STR)
		return (NULL);
	for (O = 0; Nodes; Nodes = Nodes->next, O++)
	{
		STRING = malloc(STR_LENG(Nodes->STRING) + 1);
		if (!STRING)
		{
			for (n = 0; n < O; n++)
				free(STR[n]);
			free(STR);
			return (NULL);
		}

		STRING = STR_CPY(STRING, Nodes->STRING);
		STR[O] = STRING;
	}
	STR[O] = NULL;
	return (STR);
}


/**
* LIST_PRINTS - A FUCNTION THAT PRINTSelementsof the list
*
* @FIRST: IS A Pointer TO FIRST Nodes
*
* Return: LIST SIZE
*/
size_t LIST_PRINTS(const list_t *FIRST)
{
	size_t O = 0;

	while (FIRST)
	{
		W_PUTS(NUM_conversion(FIRST->Number, 10, 0));
		W_PUTchar(':');
		W_PUTchar(' ');
		W_PUTS(FIRST->STRING ? FIRST->STRING : "(nil)");
		W_PUTS("\n");
		FIRST = FIRST->next;
		O++;
	}
	return (O);
}

/**
* _Nodes_bgin_WITH - USED TO return STRING WHICH BEGIN WITH PREfix
*
* @Nodes: Pointer TO THE Nodes LIST
* @PREfix: THE STRING To be matched
* @T: NEXT CHARACTER AFTER THE PREfix
*
* Return: THE Mached Nodes, null ON Failure
*/

list_t *_Nodes_bgin_WITH(list_t *Nodes, char *PREfix, char T)
{
	char *M = NULL;

	while (Nodes)
	{
		M = START_WITH(Nodes->STRING, PREfix);
		if (M && ((T == -1) || (*M == T)))
			return (Nodes);
		Nodes = Nodes->next;
	}
	return (NULL);
}

/**
* RETRIEVE_NODE_AT_indexs - retrieve INDEX OF Nodes
*
* @FIRST: pointer to  FIRST
* @Nodes: Nodes Pointer
*
* Return: INDEX of Nodes, -1 ON Failure
*/

ssize_t RETRIEVE_NODE_AT_indexs(list_t *FIRST, list_t *Nodes)
{
	size_t O = 0;

	while (FIRST)
	{
		if (Nodes == FIRST)
			return (O);
		FIRST = FIRST->next;
		O++;
	}
	return (-1);
}

