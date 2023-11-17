#include "shell.h"

/**
 * EXIT_COMMAND - A FUNCTION USED TO EXIST THE SHELL.
 * 
 * @Aastu: A STRUCT THAT CONTAINS POTENTIAL ARGUMENT,
 * for Maintaining constans Funtion Protype.
 * 
 * Return: EXIT WITH SPECIFIC EXIT STATUS
 * 0 if Aastu. argv[0] != "exit"
 */

int EXIT_COMMAND(Information_t *Aastu)
{
	int chk_exit;

	if (Aastu->argv[1])
	{
		chk_exit = err_watoi(Aastu->argv[1]);
		if (chk_exit == -1)
		{
			Aastu->STATUS = 2;
			ERR_display(Aastu, "Illegal number: ");
			W_PUTS(Aastu->argv[1]);
			W_PUTchar('\n');
			return (1);
		}
		Aastu->EXIT_ERROR_NUM = err_watoi(Aastu->argv[1]);
		return (-2);
	}
	Aastu->EXIT_ERROR_NUM = -1;
	return (-2);
}

/**
 * CD - CHANGES the Current directory.
 * 
 * @Aastu: A STRUCT  THAT CONTAINS PPOTENTIAL ARGUMENTS,
 * FOR  maintaining constant FUNCTION prototypes.
 * Return: Always 0
 */
int CD(Information_t *Aastu)
{
	char *G, *DIRK, BUFFER[1024];
	int CHECHDIR_RET;

	G = getcwd(BUFFER, 1024);
	if (!G)
		W_PUTS("TODO: >>getcwd failure emsg here<<\n");
	if (!Aastu->argv[1])
	{
		DIRK = GET_ENVIRO(Aastu, "HOME=");
		if (!DIRK)
			CHECHDIR_RET = /* TODO: WHAT SHOULD THIS BE? */
				chdir((DIRK = GET_ENVIRO(Aastu, "PWD=")) ? DIRK : "/");
		else
			CHECHDIR_RET = chdir(DIRK);
	}
	else if (STR_CMP(Aastu->argv[1], "-") == 0)
	{
		if (!GET_ENVIRO(Aastu, "OLDPWD="))
		{
			W_PUTS(G);
			W_PUTchar('\n');
			return (1);
		}
		W_PUTS(GET_ENVIRO(Aastu, "OLDPWD=")), W_PUTchar('\n');
		CHECHDIR_RET = /* TODO: WHAT SHOULD THIS BE? */
			chdir((DIRK = GET_ENVIRO(Aastu, "OLDPWD=")) ? DIRK : "/");
	}
	else
		CHECHDIR_RET = chdir(Aastu->argv[1]);
	if (CHECHDIR_RET == -1)
	{
		ERR_display(Aastu, "can't cd to ");
		W_PUTS(Aastu->argv[1]), W_PUTchar('\n');
	}
	else
	{
		_SET_ENVIRO(Aastu, "OLDPWD", GET_ENVIRO(Aastu, "PWD="));
		_SET_ENVIRO(Aastu, "PWD", getcwd(BUFFER, 1024));
	}
	return (0);
}

/**
 * HELP - Provides Helps.
 * 
 * @Aastu: A Struct THAT CONTAINS potential argument,
 * FOR  Maintaining constant FUNCTION Prototype.
 * Return: ALWAYS 0
 */

int HELP(Information_t *Aastu)
{
	char **Array_ar;

	Array_ar = Aastu->argv;

	W_PUTS("help call works. Function Not Yet Implimented \n");

	if (0)
		W_PUTS(*Array_ar);
	return (0);
}
