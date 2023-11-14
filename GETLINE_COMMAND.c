#include "shell.h"

/**
 * GET_LINE_COMMAND - ITS PRINT "#cisfun$ " AND WAIT FOR THE USER TYPE SOMETING.
 *
 * Return: THE LINE OF THE STRING INPUT FOR USER
 */

char *GET_LINE_COMMAND(void)

{
        char *PTRLINE = NULL;
        size_t CHARACTER_USER = 0;

        if (isatty(STDIN_FILENO)

                write(STDOUT_FILENO, "$ ", 2);

        if (getline(&PTRLINE, &CHARACTER_USER, stdin) == -1)

        {
                free(PTRLINE);
                return (NULL);
        }

        return (PTRLINE);
