#include "shell.h"

/**
 * Memset - THE function THAT FILL  MEMORY WITH CONSTANT BYTES
 *
 * @Q: POINTER to the memory area
 * @BYTES: THE BYTE TO fill thed memory
 * @Amount: AMOUNT OF BYTEs to be filled
 *
 * Return: RETURN the poninters to the memory area
 */
char *Memset(char *Q, char BYTES, unsigned int Amount)

{
	unsigned int k;

	for (k = 0; k < Amount; k++)
		Q[k] = BYTES;
	return (Q);
}

/**
 * Free - A FUNCTION That Frees String Of Strings
 * @W: Represents The String of STRINGS
 */
void Free(char **W)

{
char **Q = W;

if (!W)
return;
while (*W)
free(*W++);
free(Q);
}

/**
 * REALLOC - A FUCTION THAT reallocates blocks of memory
 *
 * @pointer: REFERS TO THE previous block that mallocates
 * @PREV_SIZE: PREVIOUS BLOCK byte size
 * @NEW_SIZE: NEW BLOCK bytes size
 *
 * Return: A POINTER TO The Previous Block Name
 */

void *REALLOC(void *pointer, unsigned int PREV_SIZE, unsigned int NEW_SIZE)

{
	char *Q;

	if (!pointer)
		return (malloc(NEW_SIZE));

	if (!NEW_SIZE)
		return (free(pointer), NULL);

	if (NEW_SIZE == PREV_SIZE)
		return (pointer);

	Q = malloc(NEW_SIZE);
	if (!Q)
		return (NULL);

	PREV_SIZE = PREV_SIZE < NEW_SIZE ? PREV_SIZE : NEW_SIZE;
	while (PREV_SIZE--)
		Q[PREV_SIZE] = ((char *)pointer)[PREV_SIZE];
	free(pointer);

	return (Q);

}

