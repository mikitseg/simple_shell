#include "shell.h"

/**
 * GET_hist_FILES - GETS THE HISTORY FILE
 *
 * @aastu: PARAMETERS STRUCT
 *
 * Return: ALLOCATED STRING CONTAINING HISTORY FILE
 */

char *GET_hist_FILES(Information_t *aastu)
{
	char *BUFFER, *DIRE;

	DIRE = GET_ENVIROment(aastu, "HOME=");
	if (!DIRE)
		return (NULL);
	BUFFER = malloc(sizeof(char) * (STR_LENG(DIRE) +
STR_LENG(".simple_shell_history"
) + 2));
	if (!BUFFER)
		return (NULL);
	BUFFER[0] = 0;
	STR_CPY(BUFFER, DIRE);
	STR_CAT(BUFFER, "/");
	STR_CAT(BUFFER, ".simple_shell_history"
);
	return (BUFFER);
}

/**
 * _hist_WRITE - CREATES afile or appends on it
 * If It Exist
 *
 * @aastu: STRUCT Parameter
 *
 * Return: 1 on SUCCESS, -1 ON Failure
 */

int _hist_WRITE(Information_t *aastu)
{
	ssize_t O;
	char *oname = GET_hist_FILES(aastu);
	list_t *Nodes = NULL;

	if (!oname)
		return (-1);

	O = open(oname, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(oname);
	if (O == -1)
		return (-1);
	for (Nodes = aastu->HEIST; Nodes; Nodes = Nodes->next)
	{
		PUT_SUNM(Nodes->STRING, O);
		PUT_NUM('\n', O);
	}
	PUT_NUM(-1, O);
	close(O);
	return (1);
}

/**
 * _hist_READ - A Function THAT READ the historys
 *
 * @aastu: STRUCT parameters
 *
 * Return: THE History Count, 0 OTHERWISE
 */
int _hist_READ(Information_t *aastu)
{
	char *BUFFER = NULL, *oname = GET_hist_FILES(aastu);
	struct stat FR;
	ssize_t O, LEN, f_size = 0;
	int L, LASTS = 0, LINE_Count = 0;

	if (!oname)
		return (0);

	O = open(oname, O_RDONLY);
	free(oname);
	if (O == -1)
		return (0);
	if (!fstat(O, &FR))
		f_size = FR.st_size;
	if (f_size < 2)
		return (0);
	BUFFER = malloc(sizeof(char) * (f_size + 1));
	if (!BUFFER)
		return (0);
	LEN = read(O, BUFFER, f_size);
	BUFFER[f_size] = 0;
	if (LEN <= 0)
		return (free(BUFFER), 0);
	close(O);
	for (L = 0; f_size > L; L++)
		if (BUFFER[L] == '\n')
		{
			BUFFER[L] = 0;
			_Vhist_listbuild(aastu, BUFFER + LASTS, LINE_Count++);
			LASTS = L + 1;
		}
	if (LASTS != L)
		_Vhist_listbuild(aastu, BUFFER + LASTS, LINE_Count++);
	free(BUFFER);
	aastu->HEIST_NUM_count = LINE_Count;
	while (aastu->HEIST_NUM_count-- >= 4096)
		REMO_Node_AT_INDEX(&(aastu->HEIST), 0);
	_hist_RE_NUM(aastu);
	return (aastu->HEIST_NUM_count);
}

/**
 * _Vhist_listbuild - ADDS AN ENTRY TO history linked lists
 *
 *  @aastu: STRUCT Parameters
 *  @BUFFER: BUFFER
 *  @LINE_Count: History LINE count
 *
 * Return: ALWAYS 0
 */
int _Vhist_listbuild(Information_t *aastu, char *BUFFER, int LINE_Count)
{
	list_t *Nodes = NULL;

	if (aastu->HEIST)
		Nodes = aastu->HEIST;
	NODEADD_ATEND(&Nodes, BUFFER, LINE_Count);

	if (!aastu->HEIST)
		aastu->HEIST = Nodes;
	return (0);
}

/**
 * _hist_RE_NUM - A FUNCTION THAT renumber a history linked list
 *
 * @aastu: STRUCT Parameters
 *
 * Return: THE New history Count
 */
int _hist_RE_NUM(Information_t *aastu)

{
	list_t *Nodes = aastu->HEIST;
int L = 0;

	for (; Nodes; Nodes = Nodes->next)
{
	Nodes->Number = L++;
}

return (aastu->HEIST_NUM_count = L);

}

