#include "shell.h"

/**
* **wSTR_tow - Usde TO Splits The String Into Words
*
* @STRING: THE STRINGS
* @DELIMATE: THE DELIMETERS
*
* Return: POINTER TO Arrays Of The STRING , NULL Otherwise
*/

char **wSTR_tow(char *STRING, char *DELIMATE)
{
	int K, L, G, H, Num_Word = 0;

	char **Q;

	if (NULL == STRING || 0 == STRING[0])
		return (NULL);
	if (!DELIMATE)
		DELIMATE = " ";
	for (K = 0; STRING[K] != '\0'; K++)
		if (!DELIMATES(STRING[K], DELIMATE) && (DELIMATES(STRING[K + 1],
				DELIMATE) || !STRING[K + 1]))
			Num_Word++;
	if (Num_Word == 0)
		return (NULL);
	Q = malloc((1 + Num_Word) * sizeof(char *));
	if (!Q)
		return (NULL);
	for (K = 0, L = 0; Num_Word > L; L++)
	{
		while (DELIMATES(STRING[K], DELIMATE))
			K++;
		G = 0;
		while (!DELIMATES(STRING[K + G], DELIMATE) && STRING[K + G])
			G++;
		Q[L] = malloc((G + 1) * sizeof(char));
		if (!Q[L])
		{
			for (G = 0; L > G; G++)
				free(Q[G]);
			free(Q);
			return (NULL);
		}
		for (H = 0; H < G; H++)
			Q[L][H] = STRING[K++];
		Q[L][H] = 0;
	}
	Q[L] = NULL;
	return (Q);
}
/**
* **WSTR_TOW1 - USED To Split The String INto THE Word
*
* @STRING: THE  STRING
* @DELIMATES: THE DELIMETER
*
* Return: POINTER TO Arrays Of The STRING , NULL Otherwise
*/

char **WSTR_TOW1(char *STRING, char DELIMATES)
{
	int K, L, G = 0, H, Num_Word = 0;

	char **Q;

	if (NULL == STRING || 0 == STRING[0])
		return (NULL);

	for (K = 0; STRING[K] != '\0'; K++)

		if ((STRING[K] != DELIMATES && STRING[K + 1] == DELIMATES) ||
				    (STRING[K] != DELIMATES && !STRING[K + 1])
				    || STRING[K + 1] == DELIMATES)
			Num_Word++;

	if (Num_Word == 0)
		return (NULL);
	Q = malloc((1 + Num_Word) * sizeof(char *));
	if (!Q)
		return (NULL);
	for (K = 0, L = 0; Num_Word > L; L++)
	{
		while (STRING[K] == DELIMATES && STRING[K] != DELIMATES)
			K++;
		while (STRING[K + G] != DELIMATES && STRING[K + G]
				&& STRING[K + G] != DELIMATES)
			G++;
		Q[L] = malloc((G + 1) * sizeof(char));
		if (!Q[L])
		{
			for (G = 0; L > G; G++)
				free(Q[G]);
			free(Q);
			return (NULL);
		}
		for (H = 0; H < G; H++)
			Q[L][H] = STRING[K++];
		Q[L][H] = 0;
	}
	Q[L] = NULL;
	return (Q);
}
