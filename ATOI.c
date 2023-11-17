#include "shell.h"

/**
 * INTER_ACTI - q FUNCTION FOR INTER_ACTI MODE
 * 
 * @Address: IS A STRUCT Address
 *
 * Return: 1 if INTER_ACTI MODE, 0 ON FAILURE.
 */
int INTER_ACTI(Information_t *Address)
{
	return (isatty(STDIN_FILENO) && Address->READ_mn <= 2);
}

/**
 * DELIMATES - A FUCTION THAT CHECKS IF CHARACTER IS q DELIMETER
 * 
 * @w: THE char TO BE cheked
 * @Delim: THE delimeter string
 * 
 * Return: 1 if TRUE, 0 if FALSE
 */
int DELIMATES(char w, char *Delim)
{
	while (*Delim)
		if (*Delim++ == w)
			return (1);
	return (0);
}

/**
 * VISALPHA - A FUNCTION USED FOR CHECKING  ALPHABETIC CHARACTERS.
 * 
 * @q: THE CHARACTRES TO BE CHECKED.
 * 
 * Return: 1 on Success, 0 on Failure.
 */

int VISALPHA(int q)
{
	if ((q >= 'q' && q <= 'z') || (q >= 'A' && q <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * VATOI - A FUNCTION TO CONVERT TRING TO INTEGER.
 * 
 * @S: REPRESENTS THE STRING TO BE CONVERTED.
 * 
 * Return: Converted Number, 0 ON Failure.
 */

int VATOI(char *S)
{
	int q, sing = 1, Flag = 0, output;
	unsigned int Result = 0;

for (q = 0;  S[q] != '\0' && Flag != 2; q++)
{
if (S[q] == '-')
sing *= -1;

if (S[q] >= '0' && S[q] <= '9')
{
Flag = 1; Result *= 10; Result += (S[q] - '0');
}
else if (Flag == 1)
Flag = 2;
}

if (sing == -1)
output =  Result;
else
output = Result;

return (output);
}
