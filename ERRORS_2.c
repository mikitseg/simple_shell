#include "shell.h"

/**
 * PUT_NUM - Writes K TO Given wq
 * @K: The Characters
 * @wq: FILE Discriptor to WRITE.
 *
 * Return: On SUCCESS 1. -1 ON failure.
 */
int PUT_NUM(char K, int wq)
{
	static int V;
	static char BUFFER[1024];

	if (K == -1 || V >= 1024)
	{
		write(wq, BUFFER, V);
		V = 0;
	}
	if (K != -1)
		BUFFER[V++] = K;
	return (1);
}

/**
 * PUT_SUNM - Prints The Inputs Strings.
 * @STRING: The string Must Be Printed.
 * @wq: Is The File Discripor
 *
 * Return: NUMBER Of CHARACTERS
 */
int PUT_SUNM(char *STRING, int wq)
{
	int V = 0;

	if (!STRING)
		return (0);
	while (*STRING)
	{
		V += PUT_NUM(*STRING++, wq);
	}
	return (V);
}
