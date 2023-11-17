#include "shell.h"

/**
 * err_watoi - Changes The String To Entigers
 *
 * @l: The STRING To Be converted
 *
 * Return: THE Converted Entiger, 0 IF string does not
 * CONTAIN numbers AND -1 on the error.
 */
int err_watoi(char *l)
{
	int Indexs = 0;
	unsigned long int Results = 0;

if (*l == '+')
l++;
	for (Indexs = 0;  l[Indexs] != '\0'; Indexs++)
	{
		if (l[Indexs] >= '0' && l[Indexs] <= '9')
		{
			Results *= 10;
			Results += (l[Indexs] - '0');
			if (Results > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (Results);
}

/**
 * ERR_display - ERROR MESSAGE is printed
 *
 * @aastu: STRUCT Parameter
 * @STRING: A STRING With specific types of error
 *
 * Return: THE Converted Entiger, 0 IF STRING does not
 * CONTAIN number AND -1 ON Error.
 */
void ERR_display(Information_t *aastu, char *STRING)
{
	W_PUTS(aastu->FILE_NNAME);
	W_PUTS(": ");
	S_Print(aastu->ERROR_Count, STDERR_FILENO);
	W_PUTS(": ");
	W_PUTS(aastu->argv[0]);
	W_PUTS(": ");
	W_PUTS(STRING);
}

/**
 * S_Print - PRINTs decimal Numbers.
 *
 * @Inputs: is the INPUTS
 * @ud: THE FILE desctiptor
 *
 * Return: NUMBER OF Character that are printed
 */
int S_Print(int Inputs, int ud)

{
	int (*__vputchar)(char) = W_PUTchar;
	int Indexs, Counts = 0;
	unsigned int Abso, Currents;

	if (ud == STDERR_FILENO)
		__vputchar = W_PUTchar;
	if (Inputs < 0)
	{
		Abso = -Inputs;
		__vputchar('-');
		Counts++;
	}
	else
		Abso = Inputs;
	Currents = Abso;
	for (Indexs = 1000000000; Indexs > 1; Indexs /= 10)
	{
		if (Abso / Indexs)
		{
			__vputchar('0' + Currents / Indexs);
			Counts++;
		}
		Currents %= Indexs;
	}
	__vputchar('0' + Currents);
	Counts++;

	return (Counts);
}

/**
 * NUM_conversion - PERFORMS THE Number of conversion
 *
 * @N: THE Number
 * @Ba: THE Base
 * @FLAG: Flags of the argument
 *
 * Return: Returns the number
 */
char *NUM_conversion(long int N, int Ba, int FLAG)
{
	static char *Aarg;
	static char BUFFER[50];
	char sing = 0;
	char *pointer;

	if (!(FLAG & 2) && N < 0)
	{
		N = -N;
		sing = '-';

	}
	Aarg = FLAG & 1 ? "0123456789abcdef" : "0123456789ABCDEF";
	pointer = &BUFFER[49];
	*pointer = '\0';

	do	{
		*--pointer = Aarg[N % Ba];
		N /= Ba;
	} while (N != 0);

	if (sing)
		*--pointer = sing;
	return (pointer);
}

/**
 * COMMENT_REMOVE - IT Replaces this  '#' With'\0'
 *
 * @BUFFER: ADDRESS OF The string to Be modify.
 *
 * Return: 0;
 */
void COMMENT_REMOVE(char *BUFFER)
{
	int Indexs;

	Indexs = 0;
	while (BUFFER[Indexs] != '\0')
{
	if (BUFFER[Indexs] == '#' && (!Indexs || BUFFER[Indexs - 1] == ' '))
	{
	BUFFER[Indexs] = '\0';
	break;
	}
	Indexs++;
}

}
