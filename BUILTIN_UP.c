#include "shell.h"

int ALI_unset(Information_t *Aastd, char *STRING);
int ALIAS_Aset(Information_t *Aastd, char *STRING);
int ALIAS_Sprint(list_t *NodeAli);

/**
 * _Finst - Display The History List
 *
 * @Aastd: a STRUCT That Contains Arguments
 *
 * Return: ALWAYS 0
 */
int _Finst(Information_t *Aastd)
{
	LIST_PRINTS(Aastd->HEIST);
	return (0);
}

/**
 * ALI_unset - It UNSETS ALIAS TO THE STRING
 *
 * @Aastd: STRUCT Parameter
 * @STRING: Is The String Alias
 *
 * Return: 0 ON SUCCESS, 1 ON ERROR
 */

int ALI_unset(Information_t *Aastd, char *STRING)
{
	char *Q, K;
	int Returns;

	Q = Wstrn_chr(STRING, '=');
	if (!Q)
		return (1);
	K = *Q;
	*Q = 0;
	Returns = REMO_Node_AT_INDEX(&(Aastd->ALIAS),
			RETRIEVE_NODE_AT_indexs(Aastd->ALIAS, _Nodes_bgin_WITH
				(Aastd->ALIAS, STRING, -1)));
	*Q = K;
	return (Returns);
}

/**
 * ALIAS_Aset - it Sets Alias To Strings
 *
 * @Aastd: its a STRUCT parameters
 * @STRING: its a STRING ALIAS
 *
 * Return: Always 0 on success, 1 on error
 */

int ALIAS_Aset(Information_t *Aastd, char *STRING)
{
	char *Q;

	Q = Wstrn_chr(STRING, '=');

	if (!Q)
		return (1);
	if (!*++Q)

		return (ALI_unset(Aastd, STRING));

	ALI_unset(Aastd, STRING);

	return (NODEADD_ATEND(&(Aastd->ALIAS), STRING, 0) == NULL);
}

/**
 * ALIAS_Sprint - Prints An Alias String
 *
 * @NodeAli: IT'S An Alias Node.
 *
 * Return: ALWAYS 0 ON SUCCESS , 1 ON ERROR
 */

int ALIAS_Sprint(list_t *NodeAli)
{
	char *Q = NULL, *Y = NULL;

	if (NodeAli)
	{
		Q = Wstrn_chr(NodeAli->STRING, '=');
		for (Y = NodeAli->STRING; Y <= Q; Y++)
			W_PUTchar(*Y);
		W_PUTchar('\'');
		W_PUTS(Q + 1);
		W_PUTS("'\n");
		return (0);
	}
	return (1);
}

/**
 * _fALIAS - OPERATES AS THE ALIAS BUILTIN
 *
 * @Aastd: STRUCT ParameterS
 *
 * Return: ALWAYS 0
 */
int _fALIAS(Information_t *Aastd)
{
	int INDEX = 0;
	char *Q = NULL;
	list_t *NodeAli = NULL;

	if (Aastd->argc == 1)
	{
		NodeAli = Aastd->ALIAS;
		while (NodeAli)
		{
			ALIAS_Sprint(NodeAli);
			NodeAli = NodeAli->next;
		}
		return (0);
	}
	for (INDEX = 1; Aastd->argv[INDEX]; INDEX++)
	{
		Q = Wstrn_chr(Aastd->argv[INDEX], '=');
		if (Q)
			ALIAS_Aset(Aastd, Aastd->argv[INDEX]);
		else
			ALIAS_Sprint(_Nodes_bgin_WITH(Aastd->ALIAS, Aastd->argv[INDEX], '='));
	}

	return (0);
}
