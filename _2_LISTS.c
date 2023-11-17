#include "shell.h"

/**
* Nodes_Add - Nodes IS Added at First
*
* @Heads: POINTER Address FOR Heads Nodes
* @STRING: The String
* @Numbers: Endexs OF The Nodes
*
* Return: LIST Size
*/

list_t *Nodes_Add(list_t **Heads, const char *STRING, int Numbers)
{
	list_t *HEADNEWS;

	if (!Heads)
		return (NULL);
	HEADNEWS = malloc(sizeof(list_t));
	if (!HEADNEWS)
		return (NULL);
	Memset((void *)HEADNEWS, 0, sizeof(list_t));
	HEADNEWS->Number = Numbers;
	if (STRING)
	{
		HEADNEWS->STRING = STR_DUP(STRING);
		if (!HEADNEWS->STRING)
		{
			free(HEADNEWS);
			return (NULL);
		}
	}
	HEADNEWS->next = *Heads;
	*Heads = HEADNEWS;
	return (HEADNEWS);
}

/**
* NODEADD_ATEND - IT Adds Nodes AT The End
*
* @Heads: POINTER Address FOR Heads Nodes
* @STRING: the String
* @Numbers: Nodes Endexs USED BY HISTORY
*
* Return: SIZE OF THE LIST
*/
list_t *NODEADD_ATEND(list_t **Heads, const char *STRING, int Numbers)
{
	list_t *NODESNEW, *Nodes;

	if (!Heads)
		return (NULL);

	Nodes = *Heads;
	NODESNEW = malloc(sizeof(list_t));
	if (!NODESNEW)
		return (NULL);
	Memset((void *)NODESNEW, 0, sizeof(list_t));
	NODESNEW->Number = Numbers;
	if (STRING)
	{
		NODESNEW->STRING = STR_DUP(STRING);
		if (!NODESNEW->STRING)
		{
			free(NODESNEW);
			return (NULL);
		}
	}
	if (Nodes)
	{
		while (Nodes->next)
			Nodes = Nodes->next;
		Nodes->next = NODESNEW;
	}
	else
		*Heads = NODESNEW;
	return (NODESNEW);
}

/**
* PRINT_LIST_STRING - It Print all The String
*
* @TFIRST: IS A POINTER For the first Nodes
*
* Return: LIST Size
*/

size_t PRINT_LIST_STRING(const list_t *TFIRST)
{
	size_t B = 0;

	while (TFIRST)
	{
		W_PUTS(TFIRST->STRING ? TFIRST->STRING : "(nil)");
		W_PUTS("\n");
		TFIRST = TFIRST->next;
		B++;
	}
	return (B);
}

/**
* REMO_Node_AT_INDEX - Removes Nodes AT Endexs
*
* @Heads: POINTER Address FOR First Nodes
* @Endexs: Endexs TO BE Deleted
*
* Return: 1 on Sucess , 0 on the  Failure
*/

int REMO_Node_AT_INDEX(list_t **Heads, unsigned int Endexs)
{
	unsigned int B = 0;
	list_t *Nodes, *LASTNODES;

	if (!Heads || !*Heads)
		return (0);

	if (!Endexs)
	{
		Nodes = *Heads;
		*Heads = (*Heads)->next;
		free(Nodes->STRING);
		free(Nodes);
		return (1);
	}
	Nodes = *Heads;
	while (Nodes)
	{
		if (B == Endexs)
		{
			LASTNODES->next = Nodes->next;
			free(Nodes->STRING);
			free(Nodes);
			return (1);
		}
		B++;
		LASTNODES = Nodes;
		Nodes = Nodes->next;
	}
	return (0);
}

/**
* LISTS_FREE_ - Nodes ARE FREED in teh lists
*
* @HEADpointer: POINTER Address TO THE Heads Nodes
*
* Return: Nothing
*/

void LISTS_FREE_(list_t **HEADpointer)
{
	list_t *Nodes, *NEXTNODES, *Heads;

	if (!HEADpointer || !*HEADpointer)
		return;
	Heads = *HEADpointer;
	Nodes = Heads;
	while (Nodes)
	{
		NEXTNODES = Nodes->next;
		free(Nodes->STRING);
		free(Nodes);
		Nodes = NEXTNODES;
	}
	*HEADpointer = NULL;
}

