#include "shell.h"

/**
* main - USED TO CREATE A simple shell project
*
* @argc: Represents the ARGUMENT count
* @argv: Represents the  ARGUMENT Vector
*
* Return: 1 ON Failure. 0 ON Success.
*/

int main(int argc, char **argv)
{
	Information_t INFO[] = { {NULL, NULL, NULL, 0, 0, 0, 0, NULL,
	NULL, 0, 0, 0, 0, 0}};

	int Z = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (Z)
			: "r" (Z));

	if (argc == 2)
	{
		Z = open(argv[1], O_RDONLY);
		if (Z == -1)
		{
			if (errno == EACCES)
				exit(126);

			if (errno == ENOENT)
			{
				W_PUTS(argv[0]);
				W_PUTS(": 0: Can't open ");
				W_PUTS(argv[1]);
				W_PUTchar('\n');
				W_PUTchar(-1);
				exit(127);
			}

			return (EXIT_FAILURE);
		}
		INFO->READ_mn = Z;
	}

	ENV_POPUL(INFO);
	_hist_READ(INFO);
	HSH(INFO, argv);
	return (EXIT_SUCCESS);
}
