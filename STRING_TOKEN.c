#include "shell.h"

/**
 * STR_LENG - determines the LENGTH of the STRING
 *
 * @O: The STRINGS
 *
 * Return: Length Of The String
 */

int STR_LENG(char *O)
{
	int G = 0;

	if (!O)
		return (0);

	while (*O++)
		G++;
	return (G);
}

/**
 * STR_CMP - Compares The Strings
 *
 * @S1: First String
 * @S2: Second String
 *
 * Return: Positive If The String is Greater, Negative
 * If It is  LessThan, 0 If They are Equal.
 */

int STR_CMP(char *S1, char *S2)
{
	while (*S1 && *S2)
	{
		if (*S1 != *S2)
			return (*S1 - *S2);
		S1++;
		S2++;
	}

	if (*S1 == *S2)
		return (0);
	else
		return (*S1 < *S2 ? -1 : 1);
}

/**
 * START_WITH - CHECKS IF PIN STARTS WITH Pile
 *
 * @Pile: THE string
 * @PIN: Substring to Find
 *
 * Return: Address of The Next char In The Pile, Otherwise NULL
 */

char *START_WITH(const char *Pile, const char *PIN)

{
	for (; *PIN; ++PIN, ++Pile)
{
	if (*PIN != *Pile)
	return (NULL);
}

return ((char *)Pile);

}

/**
 * STR_CAT - Used To Concatnate The Destination
 *
 * @Dests: Destination
 * @SOURCE: Source
 *
 * Return: Pointer to Destination
 */

char *STR_CAT(char *Dests, char *SOURCE)
{
	char *Return = Dests;

	while (*Dests)
		Dests++;
	while (*SOURCE)
		* Dests++ = *SOURCE++;
	*Dests = *SOURCE;
	return (Return);
}

