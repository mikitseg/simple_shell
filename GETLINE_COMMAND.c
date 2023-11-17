#include "shell.h"

/**
* BUFF_Sinput - IS chaind commmand of the buffers
*
* @aastu: STRUCT parameters
* @BUFFER: ADDRESS for BUFFER
* @LENGTH: Length
*
* Return: RETURNS the BYTE reads
*/
ssize_t BUFF_Sinput(Information_t *aastu, char **BUFFER, size_t *LENGTH)
{
	ssize_t r = 0;
	size_t LENG = 0;

	if (!*LENGTH)
	{
		free(*BUFFER);
		*BUFFER = NULL;
		signal(SIGINT, SIGNS_HANDLERS);
#if (0)
r = getline(BUFFER, &LENG, stdin);
#else
r = GET_LINE(aastu, BUFFER, &LENG);
#endif
if (r > 0)
{
	if ((*BUFFER)[r - 1] == '\n')
	{
		(*BUFFER)[r - 1] = '\0';
		r--;
	}
	aastu->LINE_COUNT_FLAG = 1;
	COMMENT_REMOVE(*BUFFER);
	_Vhist_listbuild(aastu, *BUFFER, aastu->HEIST_NUM_count++);

	{
		*LENGTH = r;
		aastu->cmd_BUFFER = BUFFER;
	}
}
}
return (r);
}

/**
* RE_Trieve_inpt - It Gets the INputs
*
* @aastu: STRUCT Parameters
*
* Return: IT returns the Bytes Reads
*/

ssize_t RE_Trieve_inpt(Information_t *aastu)
{
	ssize_t r = 0;
	static char *BUFFER;
	char **buffer = &(aastu->arg), *U;
	static size_t q, w, LENGTH;

	W_PUTchar(-1);
	r = BUFF_Sinput(aastu, &BUFFER, &LENGTH);
	if (r == -1)
		return (-1);
	if (LENGTH)
	{
		w = q;
		U = BUFFER + q;

		CHAIN_WCHECK(aastu, BUFFER, &w, q, LENGTH);
		while (w < LENGTH)
		{
			if (WIs_chain(aastu, BUFFER, &w))
				break;
			w++;
		}

		q = w + 1;
		if (q >= LENGTH)
		{
			q = LENGTH = 0;
			aastu->cmd_BUFFER_TYPE = 0;
		}

		*buffer = U;
		return (STR_LENG(U));
	}

	*buffer = BUFFER;
	return (r);
}

/**
* READ_BUFF - IT reads the BUFFER
*
* @aastu: STRUCT Parameters
* @BUFFER: represent the BUFFER
* @q: SIZE
*
* Return: r
*/

ssize_t READ_BUFF(Information_t *aastu, char *BUFFER, size_t *q)
{
	ssize_t r = 0;

	if (*q)
		return (0);
	r = read(aastu->READ_mn, BUFFER, 1024);
	if (r >= 0)
		*q = r;
	return (r);
}

/**
* GET_LINE - Get Inputs From STDIN.
*
* @aastu: STRUCT Parameters
* @PTR: POINTER
* @LENGTH: Size of the POINTER
*
* Return: h
*/

int GET_LINE(Information_t *aastu, char **PTR, size_t *LENGTH)
{
	size_t r;
	static char BUFFER[1024];
	char *U = NULL, *Bnew = NULL, *g;
	static size_t q, LENGTH;
	ssize_t r = 0, h = 0;

	U = *PTR;
	if (U && LENGTH)
		h = *LENGTH;
	if (q == LENGTH)
		q = LENGTH = 0;

	r = READ_BUFF(aastu, BUFFER, &LENGTH);
	if (r == -1 || (r == 0 && LENGTH == 0))
		return (-1);

	g = Wstrn_chr(BUFFER + q, '\n');
	r = g ? 1 + (unsigned int)(g - BUFFER) : LENGTH;
	Bnew = REALLOC(U, h, h ? h + r : r + 1);
	if (!Bnew)
		return (U ? free(U), -1 : -1);

	if (h)
		WSTRN_CAT(Bnew, BUFFER + q, r - q);
	else
		VSTRN_CPY(Bnew, BUFFER + q, r - q + 1);

	h += r - q;
	q = r;
	U = Bnew;

	if (LENGTH)
		*LENGTH = h;
	*PTR = U;
	return (h);
}

/**
* SIGNS_HANDLERS - A FUNCTION THAT  handles sign
*
* @NUM_signal: NUMBER USED for signal
*
* Return: void
*/
void SIGNS_HANDLERS(__attribute__((unused))int NUM_signal)
{
	W_PUTS("\n");
	W_PUTS("$ ");
	W_PUTchar(-1);
}

