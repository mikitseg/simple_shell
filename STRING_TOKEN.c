#include "shell.h"

/**
 * TOKEN_STR - BREAKS THE STRING s1 INTO TOKENS AND NULL-TERMINATES THEM 
 * DELIMITER-CHARACTERS AT THE BEGINNING AND END
 * OF STR ARE SKIPPED. ON EACH SUBSEQUENT CALL DELIM MAY CHANGE
 *
 * @STR: THE STRING TOKENIZE
 * @DELIMITERS: THE STRING WITH THE CHARECTER THAT DELIMIT STR
 *  
 * Return: THE FIRST OR NEXT TOKEN IF POSSIBLE, A NULL-POINTER OTHERWISE.
 **/

char *TOKEN_STR(char *STR, const char *DELIMITERS)

{
	static char *o;

	if (STR)
		o = STR;
	else if (!o)
		return (0);
	STR = o + STRSPN(o, DELIMITERS);
	o = STR + STRCSPN(STR, DELIMITERS);
	if (o == STR)
		return (o = 0);
	o = *o ? *o = 0, o + 1 : 0;
	return (STR);
}

/**
 * STRCSPN - COMPUTES THE LENGTH O THE MAXIMUM INITIAL SGMENT OF THE
 * STRING POINTED TO BY S1 WHICH CONSISTS ENTIRELY OF CHARACTERS NOT FROM
 * THE STRING POINTED TO BY S2.
 *  
 * @strlen: STRING TO CHECK
 * @strle: STRING USEFUL TO COMPARE
 *
 * Return: THE LENGTH OF THE SEGMENT
 **/

size_t STRCSPN(const char *strlen, const char *strle)

{
	size_t RAT = 0;

	while (*strlen)
	{
		if (STRCHAR(strle, *strlen))
			return (RAT);
		strlen++, RAT++;
	}
	return (RAT);
}

/**
 * STRSPN - COMPUTE THE LENGTH OF THE MAXIMUM INITIAL SEGMENT OF THE STRING
 * POINTED TO BY S1 WHICH CONSIST ENTIRELY OF THE CHARACTERS FROM THE
 * STRING POINTED TO BY S2
 *  
 * @strlen: STRINGINT TO COMPUTE THE LENGTH
 * @strle: STRING DELIMIT
 * 
 * Return: THE LENGTH OF THE SEGEMENT 
 **/

size_t STRSPN(const char *strlen, const char *strle)

{
	size_t RAT = 0;

	while (*strlen && STRCHAR(strle, *strlen++))
		RAT++;
	return (RAT);
}

/**
 * STRCHAR - LOCATES THE FIRST OCCURANCE OF THE t CONVERTED TO char IN THE
 * STRING POINTED TO BY q. THE TERMINATING NULL CHARACTER IS CONSIDERED TO BE
 * PART OF THE STRING
 *  
 * @q: STRING
 * @t: CHARACTER
 * 
 * Return: A POINTER TO THE LOCATED CHARACTER, OR A NULL POINTER
 * IF THE CHARACTER DOES NOT OCCUR IN THE STRING. 
 **/

char *STRCHAR(const char *q, int t)

{
	while (*q != (char)t)
		if (!*q++)
			return (0);
	return ((char *)q);
}
