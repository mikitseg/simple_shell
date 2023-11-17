#include "shell.h"

/**
 * GET_ENVIRO - COPY OF Sting of the ARRAY of the environment
 *
 * @aastu: STRUCT Parameter.
 *
 * Return: ALWAYS 0
 */
char **GET_ENVIRO(Information_t *aastu)
{
	if (!aastu->ENVIRONM || aastu->ENV_UPDATE)

	{
		aastu->ENVIRONM = LIST_STRINGS(aastu->ENV_LOC);
		aastu->ENV_UPDATE = 0;
	}

	return (aastu->ENVIRONM);
}

/**
 * _UNSET_ENVIRO - UNSETS AN Enviroment Variables
 *
 * @aastu: STRUCT the parameters
 * @VAR: ENVIRONMENT varible
 *
 * Return: 1 ON Succes, 0 ON Failure.
 */

int _UNSET_ENVIRO(Information_t *aastu, char *VAR)
{
	list_t *Nodes = aastu->ENV_LOC;
	char *Q;
	size_t k = 0;

	if (!Nodes || !VAR)
		return (0);

	while (Nodes)
	{
		Q = START_WITH(Nodes->STRING, VAR);
		if (Q && *Q == '=')
		{
			aastu->ENV_UPDATE = REMO_Node_AT_INDEX(&(aastu->ENV_LOC), k);
			k = 0;
			Nodes = aastu->ENV_LOC;
			continue;
		}
		Nodes = Nodes->next;
		k++;
	}
	return (aastu->ENV_UPDATE);
}

/**
 * _SET_ENVIRO - SETS A NEW Environment variables
 *
 * @aastu: STRUCT Parameters
 * @VAR: STRING environment Variable
 * @VARIB: VALUE OF The Environment Variables
 *
 * Return: 0
 */
int _SET_ENVIRO(Information_t *aastu, char *VAR, char *VARIB)
{
	char *BUFFER = NULL;
	char *Q;
	list_t *Nodes;

	if (!VAR || !VARIB)
		return (0);

	BUFFER = malloc(STR_LENG(VAR) + STR_LENG(VARIB) + 2);

	if (!BUFFER)
		return (1);
	STR_CPY(BUFFER, VAR);
	STR_CAT(BUFFER, "=");
	STR_CAT(BUFFER, VARIB);
	Nodes = aastu->ENV_LOC;
	while (Nodes)
	{
		Q = START_WITH(Nodes->STRING, VAR);
		if (Q && *Q == '=')
		{
			free(Nodes->STRING);
			Nodes->STRING = BUFFER;
			aastu->ENV_UPDATE = 1;
			return (0);
		}
		Nodes = Nodes->next;
	}
	NODEADD_ATEND(&(aastu->ENV_LOC), BUFFER, 0);
	free(BUFFER);
	aastu->ENV_UPDATE = 1;
	return (0);
}

