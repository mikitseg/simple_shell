#include "shell.h"

/**
 *STRNCAT_S - COPY STRINGS TO ANOTHEER STRINGS.
 *
 *@DRIVE: characters
 *@SRC: characters
 *
 *Return: DRIVE
 */

char *STRNCAT_S(char *DRIVE, char *SRC)
{
	int S = 0;
	int T = 0;

	while (DRIVE[S] != '\0')
	{
		S++;
	}
	while (SRC[T] != '\0')
	{
		DRIVE[S] = SRC[T];
		S++;
		T++;
	}
	DRIVE[S] = '\0';
	return (DRIVE);
}

/**
 * STRCOMP - COMPARE THE VALUES OF G STRING
 *
 * @strlen: CHARACTER
 * @strle: CHARACTER
 *
 * Return: 0
 */

int STRCOMP(char *strlen, char *strle)

{
	int G;

	for (G = 0; strlen[G] != '\0' && strle[G] != '\0'; G++)
	{
		if (strlen[G] != strle[G])
			return ((int)strlen[G] - strle[G]);
	}
	return (0);
}

/**
 * STRLENG - COPIES THE STRING PINTED TO BY BY SRC INTO DRIVE
 *
 * @T: A POINTER
 *
 * Return: CHAR POINTER TO THE DRIVE
 */

int STRLENG(char *T)
{
	int QW = 0;

	while (*(T + QW) != '\0')
	{
		QW++;
	}

	return (QW);
}

/**
 *STRNCMP -  FUNCTION THAT COMPARES THE TWO STRINGS.
 *@strlen: STRING ONE
 *@strle: STRING TWO
 *@z: NUMBERS OF THE CHARACTERS
 * Return: THE DIFERENCE
 */

size_t STRNCMP(char *strlen, char *strle, size_t z)
{
	size_t w, Q;

	for (Q = 0; strlen[Q] != '\0' && Q < z; Q++)
	{
		w = strlen[Q] - strle[Q];

		if (w != 0)
		{
			return (w);
		}
	}
	return (0);
}

/**
 * COPY_STR - COPIES THE STRING POINTED TO BY SRC INTO DRIVE
 *
 * @DRIVE: THE DESTINATION OF THE FILE
 * @SRC: SOURCES OF THE COPY
 *
 * Return: CHAR POINTERS TO  DRIVE
 */

char *COPY_STR(char *DRIVE, char *SRC)
{
	int w = 0;

	while (*(SRC + w) != '\0')
	{
		*(DRIVE + w) = *(SRC + w);
		++w;
	}
	*(DRIVE + w) = *(SRC + w);

	return (DRIVE);
}

