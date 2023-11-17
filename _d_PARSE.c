#include "shell.h"

/**
* IS_cmd - USED TO DETERMINE IF the command is excutable
*
* @aastu: STRUCT parameteres
* @Paths: Paths
*
* Return: 1 ON Success, 0 ON Failure
*/

int IS_cmd(Information_t *aastu, char *Paths)
{
	struct stat ds;

	(void)aastu;
	if (!Paths ||stat(Paths, &ds))
		return (0);

	if (ds.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
* _char_VDUP - USED FOR character duplication
*
* @PATHSTR: THE STRING USED FOR THE Paths
* @Initials: THE Initial indexs
* @FINALS: Final Indexs
*
* Return: POINTER to the NEw BUFFER.
*/

char *_char_VDUP(char *PATHSTR, int Initials, int FINALS)
{
	static char BUFFER[1024];
	int L = 0, P = 0;

	for (P = 0, L = Initials; L < FINALS; L++)
		if (PATHSTR[L] != ':')
			BUFFER[P++] = PATHSTR[L];
	BUFFER[P] = 0;
	return (BUFFER);
}

/**
* PATHS_FIND - FINDS THE COMMAND in the PATH string
*
* @aastu: THE struct PARAMETERE
* @PATHSTR: the Paths STRING
* @CMD: COMMAND TO finds
*
* Return: Paths OF COMMAND, NULL otherwise
*/

char *PATHS_FIND(Information_t *aastu, char *PATHSTR, char *CMD)
{
	char *Paths;
	int L = 0, _pass_Current = 0;

	if (!PATHSTR)
		return (NULL);

	if ((STR_LENG(CMD) > 2) && START_WITH(CMD, "./"))
	{
		if (IS_cmd(aastu, CMD))
			return (CMD);
	}

	while (1)
	{
		if (!PATHSTR[L] || PATHSTR[L] == ':')
		{
			Paths = _char_VDUP(PATHSTR, _pass_Current, L);
			if (!*Paths)
				STR_CAT(Paths, CMD);
			else
			{
				STR_CAT(Paths, "/");
				STR_CAT(Paths, CMD);
			}
			if (IS_cmd(aastu, Paths))
				return (Paths);
			if (!PATHSTR[L])
				break;
			_pass_Current = L;
		}
		L++;
	}
	return (NULL);
}

