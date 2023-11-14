#include "shell.h"


/**
 * fork_function - FUNCTION THAT CREAT A FORK
 *
 *@path: COMMAND AND VALUE PATH
 *@avr: HAS THE NAME OF THE PROGRAM
 *@ENVIRO: THE ENVIRONMENT
 *@LINEPTR: THE COMMAND LINE  OF THE USER
 *@np: THE ID OF THE PROCESS
 *@t: CHECKER ADDS THE NES TEST
 *
 *Return: 0 success
 */


int fork_function(char **path, char **avr, char **ENVIRO, char *LINEPTR, int np, int t)

{

        pid_t CHILD;
        int STATUS;
        char *Form = "%s: %d: %s: not found\z";

        CHILD = fork();

<<<<<<< HEAD
        if (CHILD == 0)
=======
	if (CHILD == 0)

	{
>>>>>>> 48cbdc8b3fa8453d04f68ce2774b0f9f159c033f

        {

                if (execve(path[0], path, ENVIRO) == -1)

                {

                        fprintf(stderr, Form, avr[0], np, path[0]);
                        if (!t)

                                free(path[0]);
                        free(path);
                        free(LINEPTR);
                        exit(errno);

                }
        }

        else

        {

                wait(&STATUS);

                if (WIFEXITED(STATUS) && WEXITSTATUS(STATUS) != 0)
			return (WEXITSTATUS(STATUS));
        }
        return (0);
}
