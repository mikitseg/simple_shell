#include "shell.h"

/**
* WIs_chain - Checks for the chain DELIMETER
*
* @aastu: Struct PARAMETER
* @BUFFER: The char BUFFER
* @Pass: ADDRESS of the current Position
*
* Return: 1 ON the Success , 0 Otherwise
*/

int WIs_chain(Information_t *aastu, char *BUFFER, size_t *Pass)

{
	size_t P = *Pass;

	if (BUFFER[P] == '|' && BUFFER[P + 1] == '|')

	{
		BUFFER[P] = 0;
		P++;
		aastu->cmd_BUFFER_TYPE = 1;
	}

	else if (BUFFER[P] == '&' && BUFFER[P + 1] == '&')

	{
		BUFFER[P] = 0;
		P++;
		aastu->cmd_BUFFER_TYPE = 2;
	}

	else if (BUFFER[P] == ';')
	{
		BUFFER[P] = 0;
		aastu->cmd_BUFFER_TYPE = 3;
	}

	else
		return (0);
	*Pass = P;
	return (1);
}

/**
*CHAIN_WCHECK - USED FOR Checking The Chain
*
*@aastu: struct PARAMETER
*@BUFFER: the BUFFER CHAR
*@Pass: ADDRESS OF the current Pisition
*@Q: THE INITIAL POSITION
*@LENGTH: Length of the BUFFER
*
*Return: Nothing
*/

void CHAIN_WCHECK(Information_t *aastu, char *BUFFER,
			size_t *Pass, size_t Q, size_t LENGTH)
{
	size_t P = *Pass;

	if (aastu->cmd_BUFFER_TYPE == 2)

	{
		if (aastu->stat)
		{
			BUFFER[Q] = 0;
			P = LENGTH;
		}
	}
	if (aastu->cmd_BUFFER_TYPE == 1)
	{
		if (!aastu->stat)
		{
			BUFFER[Q] = 0;
			P = LENGTH;
		}
	}

	*Pass = P;
}

/**
* Walias_Replace - USED FOR the Alias Replacement
*
* @aastu: Struct PARAMETER
*
* Return: 1 ON Success, 0 otherwises
*/

int Walias_Replace(Information_t *aastu)
{
	list_t *Nodes;
	int Q;
	char *Pass;

	for (Q = 0; Q < 10; Q++)

	{
		Nodes = _Nodes_bgin_WITH(aastu->ALIAS, aastu->argv[0], '=');

		if (!Nodes)
			return (0);
		free(aastu->argv[0]);
		Pass = Wstrn_chr(Nodes->STRING, '=');
		if (!Pass)
			return (0);
		Pass = STR_DUP(Pass + 1);
		if (!Pass)
			return (0);
		aastu->argv[0] = Pass;
	}

	return (1);
}

/**
* WVAR_REPLACE - Used For var
*
* @aastu: Struct PARAMETER
*
* Return: 1 ON Success, 0 ON failure
*/

int WVAR_REPLACE(Information_t *aastu)
{
	int Q = 0;

	list_t *Nodes;

	for (Q = 0; aastu->argv[Q]; Q++)

	{
		if (aastu->argv[Q][0] != '$' || !aastu->argv[Q][1])
			continue;

		if (!STR_CMP(aastu->argv[Q], "$?"))

		{
			STR_REPLACE(&(aastu->argv[Q]),
					STR_DUP(NUM_conversion(aastu->stat, 10, 0)));
			continue;
		}

		if (!STR_CMP(aastu->argv[Q], "$$"))

		{
			STR_REPLACE(&(aastu->argv[Q]),
					STR_DUP(NUM_conversion(getpid(), 10, 0)));
			continue;
		}
		Nodes = _Nodes_bgin_WITH(aastu->ENV_LOC, &aastu->argv[Q][1], '=');
		if (Nodes)

		{
			STR_REPLACE(&(aastu->argv[Q]),
					STR_DUP(Wstrn_chr(Nodes->STRING, '=') + 1));
			continue;
		}
		STR_REPLACE(&aastu->argv[Q], STR_DUP(""));

	}
	return (0);
}

/**
* STR_REPLACE - USED FOR the stings replacement
*
* @oldest: THE oldest STRING
* @newest: THE newest STRING
*
* Return: 1 ON the Success, 0 ON FAILURE
*/

int STR_REPLACE(char **oldest, char *newest)

{
	free(*oldest);
	*oldest = newest;
	return (1);
}

