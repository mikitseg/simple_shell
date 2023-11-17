#include "shell.h"

/**
* VSTRN_CPY - IT Copies The String
*
*@FIRST: The Destination
*@SECOND: The Source
*@Q: Numbers Of CHARACTER TO BE copied
*
*Return: THE copied string.
*/

char *VSTRN_CPY(char *FIRST, char *SECOND, int Q)

{
	int S, T;
	char *W = FIRST;

	S = 0;
	while (SECOND[S] != '\0' && S < Q - 1)

	{
		FIRST[S] = SECOND[S];
		S++;
	}

	if (S < Q)
	{
		T = S;
		while (T < Q)
		{
			FIRST[T] = '\0';
			T++;
		}
	}
	return (W);
}

/**
* WSTRN_CAT - Concatenate The STRING
*
*@FIRST: First STRING
*@SECOND: Second STRING
*@Q: Number Of BYTE
*
*Return: STRING THAT is concatinated
*/

char *WSTRN_CAT(char *FIRST, char *SECOND, int Q)

{
	int S, T;
	char *W = FIRST;

	S = 0;
	T = 0;
	while (FIRST[S] != '\0')
		S++;
	while (SECOND[T] != '\0' && T < Q)
	{
		FIRST[S] = SECOND[T];
		S++;
		T++;
	}
	if (T < Q)
		FIRST[S] = '\0';
	return (W);
}

/**
* Wstrn_chr - It Finds A Character In STRING
*
*@O: The String
*@W: The CHARACTER To Look For
*
*Return: The Pointer
*/

char *Wstrn_chr(char *O, char W)

{
	do {
		if (*O == W)
			return (O);
	} while (*O++ != '\0');

	return (NULL);
}
