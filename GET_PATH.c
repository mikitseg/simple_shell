#include "shell.h"

/**
 * INFO_REMOVE - CLEARS information
 *
 * @Aastu: ADDRESS struct
 *
 * RETURN: Nothing
 */
void INFO_REMOVE(Information_t *Aastu)
{
	Aastu->arg = NULL;
	Aastu->argv = NULL;
	Aastu->PATH = NULL;
	Aastu->argc = 0;
}

/**
 * INFO_SET - SETS Information
 *
 * @Aastu: ADDRESS struct
 * @AVG: REPRESENTS an argument vectors
 *
 * RETURN: Nothing
 */

void INFO_SET(Information_t *Aastu, char **AVG)
{
	int K = 0;

	Aastu->FILE_NNAME = AVG[0];
	if (Aastu->arg)
	{
		Aastu->argv = wSTR_tow(Aastu->arg, " \t");
		if (!Aastu->argv)
		{

			Aastu->argv = malloc(sizeof(char *) * 2);
			if (Aastu->argv)
			{
				Aastu->argv[0] = STR_DUP(Aastu->arg);
				Aastu->argv[1] = NULL;
			}
		}
		for (K = 0; Aastu->argv && Aastu->argv[K]; K++)
			;
		Aastu->argc = K;

		Walias_Replace(Aastu);
		WVAR_REPLACE(Aastu);
	}
}

/**
 * INFO_FREE - IT Frees the Information
 *
 * @Aastu: ADDRESS of the struct
 *
 * @All: REPRESENT all The Field
 */
void INFO_FREE(Information_t *Aastu, int All)
{
	Free(Aastu->argv);
	Aastu->argv = NULL;
	Aastu->PATH = NULL;
	if (All)
	{
		if (!Aastu->cmd_BUFFER)
			free(Aastu->arg);
		if (Aastu->ENV_LOC)
			LISTS_FREE_(&(Aastu->ENV_LOC));
		if (Aastu->HEIST)
			LISTS_FREE_(&(Aastu->HEIST));
		if (Aastu->ALIAS)
			LISTS_FREE_(&(Aastu->ALIAS));
		Free(Aastu->ENVIRONM);
		Aastu->ENVIRONM = NULL;
		G_Free((void **)Aastu->cmd_BUFFER);
		if (Aastu->READ_mn > 2)
			close(Aastu->READ_mn);
		W_PUTchar(-1);
	}
}
