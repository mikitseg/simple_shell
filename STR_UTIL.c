#include "shell.h"

/**
 * STR_CPY - A Function That Copies A String
 *
 * @Dests: Destination
 * @SOURCE: Soources
 *
 * Return: pointer Of The Destination
 */
char *STR_CPY(char *Dests, char *SOURCE)
{
	int k = 0;

	if (Dests == SOURCE || 0 == SOURCE)
		return (Dests);
	while (SOURCE[k])
	{
		Dests[k] = SOURCE[k];
		k++;
	}
	Dests[k] = 0;
	return (Dests);
}

/**
 * STR_DUP - Duplicates The Strings
 *
 * @STR_replace: Strings
 *
 * Return: Pointer To Duplicates The String
 */

char *STR_DUP(const char *STR_replace)
{
	char *Returns;
	int Leng = 0;

	if (STR_replace == NULL)
		return (NULL);
	while (*STR_replace++)
		Leng++;
	Returns = malloc(sizeof(char) * (Leng + 1));
	if (!Returns)
		return (NULL);
	for (Leng++; Leng--;)
		Returns[Leng] = *--STR_replace;
	return (Returns);
}

/**
 * W_PUTS - Prints The String
 *
 * @STR_replace: String
 *
 * Return: Void
 */

void W_PUTS(char *STR_replace)
{
	int k = 0;

	if (!STR_replace)
		return;

	while (STR_replace[k] != '\0')
	{
		W_PUTchar(STR_replace[k]);
		k++;
	}
}

/**
 * W_PUTchar - Prints The Character To STDOUT
 *
 * @O: The Characters
 *
 * Return: 1 On Success , 0 On Failure
 */

int W_PUTchar(char O)
{
	static char BUFFER[1024];
	static int k;

	if (O == -1 || k >= 1024)
	{
		write(1, BUFFER, k);
		k = 0;
	}

	if (O != -1)
		BUFFER[k++] = O;
	return (1);
}
