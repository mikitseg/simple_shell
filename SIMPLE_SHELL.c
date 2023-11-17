#include "shell.d"

/**
* HSH - A FUCTION THAT is the main functon loop
* @Aastu: STRUCT parameters
* @aver: ARGUMENt vectors
*
* Return: 0 ON the SUCCESS, 1 on the error
*/

int HSH(Information_t *Aastu, char **aver)
{
	ssize_t w = 0;
	int RB = 0;

	while (w != -1 && RB != -2)
	{
		INFO_REMOVE(Aastu);
		if (INTER_ACTI(Aastu))
			W_PUTS("$ ");
		W_PUTchar(-1);
		w = RE_Trieve_inpt(Aastu);

		if (w != -1)
		{
			INFO_SET(Aastu, aver);
			RB = CAPTURE_BUILTIN(Aastu);
			if (RB == -1)
				CAPTURE_cmd(Aastu);
		}
		else if (INTER_ACTI(Aastu))
			W_PUTchar('\n');
		INFO_FREE(Aastu, 0);
	}
	_hist_WRITE(Aastu);
	INFO_FREE(Aastu, 1);
	if (!INTER_ACTI(Aastu) && Aastu->STATUS)
		exit(Aastu->STATUS);
	if (RB == -2)
	{
		if (Aastu->EXIT_ERROR_NUM == -1)
			exit(Aastu->STATUS);
		exit(Aastu->EXIT_ERROR_NUM);
	}
	return (RB);
}

/**
* CAPTURE_BUILTIN - A Funtion That Find BUILTIN cmd
*
* @Aastu: STRUCT Prameters
*
* Return: Returns -1 If BUILTIN Not Found,
*1 If Found (But Not Successful),
*-2 If BUILTIN Signal Exit(),
*0 If BUILTIN Executed Succssfully.
*/
int CAPTURE_BUILTIN(Information_t *Aastu)
{
	int k, birr = -1;
	builtin_t built_intb[] = {
		{"exit", EXIT_COMMAND},
		{"env", ENVIRO},
		{"help", HELP},
		{"history", _Finst},
		{"setenv", SET_ENVIRO},
		{"unsetenv", UNSSET_ENVIRO},
		{"cd", CD},
		{"ALIAS", _fALIAS},
		{NULL, NULL}
	};

	for (k = 0; built_intb[k].flag; k++)
		if (STR_CMP(Aastu->argv[0], built_intb[k].flag) == 0)
		{
			Aastu->ERROR_Count++;
			birr = built_intb[k].function(Aastu);
			break;
		}
	return (birr);
}

/**
* CAPTURE_cmd - Finds cmd In Path
*
* @Aastu: STRUCT Parameters
*
* Return: Nothing
*/

void CAPTURE_cmd(Information_t *Aastu)
{
	int k, d;
	char *PATH = NULL;

	Aastu->PATH = Aastu->argv[0];
	if (Aastu->LINE_COUNT_FLAG == 1)
	{
		Aastu->ERROR_Count++;
		Aastu->LINE_COUNT_FLAG = 0;
	}

	for (k = 0, d = 0; Aastu->arg[k]; k++)
		if (!DELIMATES(Aastu->arg[k], " \t\n"))
			d++;
	if (!d)
		return;

	PATH = PATHS_FIND(Aastu, GET_ENVIRO(Aastu, "PATH="), Aastu->argv[0]);

	if (PATH)
	{
		Aastu->PATH = PATH;
		cmd_FORKS(Aastu);
	}
	else
	{
		if ((INTER_ACTI(Aastu) || GET_ENVIRO(Aastu, "PATH=")
					|| Aastu->argv[0][0] == '/') && IS_cmd(Aastu, Aastu->argv[0]))
			cmd_FORKS(Aastu);
		else if (*(Aastu->arg) != '\n')
		{
			Aastu->STATUS = 127;
			ERR_display(Aastu, "not found\n");
		}
	}
}

/**
* cmd_FORKS - USED TO Fork A cmd
* @Aastu: STRUCT Parameters
*
* Return: Nothing
*/

void cmd_FORKS(Information_t *Aastu)
{
	pid_t Child_Pid;

	Child_Pid = fork();

	if (Child_Pid == -1)

	{
		perror("Error:");
		return;
	}

	if (Child_Pid == 0)

	{
		if (execve(Aastu->PATH, Aastu->argv, GET_ENVIRO(Aastu)) == -1)

		{
			INFO_FREE(Aastu, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(Aastu->STATUS));
		if (WIFEXITED(Aastu->STATUS))
		{
			Aastu->STATUS = WEXITSTATUS(Aastu->STATUS);
			if (Aastu->STATUS == 126)
				ERR_display(Aastu, "Permission denied\n");
		}
	}
}
