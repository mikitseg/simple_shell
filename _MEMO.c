#include "shell.h"

/**
* G_Free - USED TO Free the Pointer
*
* @POINTER: ADDRESS OF THE pointer to be freed
*
* Return: 1 ON Success, 0 Otherwise
*/

int G_Free(void **POINTER)
{
	if (POINTER && *POINTER)

	{
		free(*POINTER);
		*POINTER = NULL;
		return (1);
	}
	return (0);
}
