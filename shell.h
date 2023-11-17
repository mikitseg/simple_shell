#ifndef SHELL_H
#define SHELL_H

#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

extern char **environ;

/**
* struct List_Str - Is A STRUCTURE for singly linked list
*
* @NUM: REPRESENTS the number field
* @STRING: represents a STRIING
* @NEXT:  STRUCTURE THAT points to the NEXT node
*/

typedef struct List_Str
{
	int Number;
	char *STRING;
	struct List_Str *next;
} list_t;

/**
*struct information_pass - PASS THE ARGUMENT into a FUNCTION,
*- Allows prototype for FUNCTION pointer structure.
*
*@arg: IS a STRING coming FROM  GET LINE.
*@argv: IS ARRAY of STRINGS FROM GET LINE.
*@PATH: IS THE PATH for a COMMAND THAT IS CURRENTLY IN USE.
*@argc: IT COUNTS ARRGUMENTS given in terminal.
*@ERROR_Count: IS a error COUNT.
*@EXIT_ERROR_NUM: IS THE CODE FOR ERROR OR IXIT FUNCTION.
*@LINE_COUNT_FLAG: line of the input IF ON COUNT
*@FILE_NNAME: IS  PROGRAM FILE NAME
*@ENV_LOC: IS LOCAL COPY of environmelt
*@ENVIRONM: MODIFIED COPY of ENVIRONM from.
*@HEIST: REFERS TO THE HISTORY node
*@ALIAS: REFERS TO the ALIAS node
*@ENV_UPDATE: APPLYS WHEN THE ENVIRONMENT IS UPDATED.
*@stat: IS RETURN STATUS of executed COMMAND LAST.
*@cmd_BUFFER: IS ADDRESS OF POINTER to cmd_BUFFER.
*@cmd_BUFFER_TYPE: CMD_type ||, &&, ;
*@READ_mn: USED to READ line input
*@HEIST_NUM_count: IS THE line NUM count OF HISORY.
*/

typedef struct information_pass
{

	list_t *ENV_LOC;
	char **ENVIRONM;
	list_t *HEIST;
	list_t *ALIAS;
	int ENV_UPDATE;
	int stat;
	char *arg;
	char **argv;
	char *PATH;
	int argc;
	unsigned int ERROR_Count;
	int EXIT_ERROR_NUM;
	int LINE_COUNT_FLAG;
	char *FILE_NNAME;

	char **cmd_BUFFER;
	int cmd_BUFFER_TYPE;
	int READ_mn;
	int HEIST_NUM_count;
} Information_t;

/**
*struct BUILT_IN - the struct FOR BUILTIN STRING
*@FLAG: the FLAG.
*@FUNCTION: A FUNCTION in this structure
*/

typedef struct BUILT_IN
{
	char *FLAG;
	int (*FUNCTION)(Information_t *);

} builtin_t;

/*GET_LINE.c */
void SIGNS_HANDLERS(int);
int GET_LINE(Information_t *, char **, size_t *);
ssize_t READ_BUFF(Information_t *, char *, size_t *);
ssize_t BUFF_Sinput(Information_t *info, char **buf, size_t *len);
ssize_t RE_Trieve_inpt(Information_t *);

/* nEXIT.c */
char *WSTRN_CAT(char *, char *, int);
char *Wstrn_chr(char *, char);
char *VSTRN_CPY(char *, char *, int);

/* ERRORS.c */
int PUT_SUNM(char *STRING, int nm);
int W_PUTchar(char);
void W_PUTS(char *);
int PUT_NUM(char c, int nm);

/* ERRORS.c */
void COMMENT_REMOVE(char *);
void ERR_display(Information_t *, char *);
int S_Print(int, int);
int err_watoi(char *);
char *NUM_conversion(long int, int, int);

/* STRING.c */
int STR_CMP(char *, char *);
char *STR_CAT(char *, char *);
char *START_WITH(const char *, const char *);
int STR_LENG(char *);

/* STRING2.c */
int W_PUTchar(char);
char *STR_DUP(const char *);
char *STR_CPY(char *, char *);
void W_PUTS(char *);


/* W_TOKEN.c */
char **WSTR_TOW1(char *, char);
char **wSTR_tow(char *, char *);

/* REALLOC.c */
void *REALLOC(void *, unsigned int, unsigned int);
void Free(char **);
char *Memset(char *, char, unsigned int);


/*VATOI.c */
int VATOI(char *);
int VISALPHA(int);
int INTER_ACTI(Information_t *address);
int DELIMATES(char, char *);

/* _MEMO.c */
int G_Free(void **);

/* BUILT_IN.c */
int HELP(Information_t *);
int CD(Information_t *);
int EXIT_COMMAND(Information_t *);

/* BUINTIN_UP.c */
int _fALIAS(Information_t *);
int _Finst(Information_t *);


/* _d_PARSE.c */
char *PATHS_FIND(Information_t *, char *, char *);
char *_char_VDUP(char *, int, int);
int IS_cmd(Information_t *, char *);

/*GET_INFO.c */
void INFO_SET(Information_t *, char **);
void INFO_FREE(Information_t *, int);
void INFO_REMOVE(Information_t *);

/* w_VAR.c */
int WVAR_REPLACE(Information_t *);
int WIs_chain(Information_t *, char *, size_t *);
int STR_REPLACE(char **, char *);
int Walias_Replace(Information_t *);
void CHAIN_WCHECK(Information_t *, char *, size_t *, size_t, size_t);

/*ENVIRONMENT.c */
int SET_ENVIRO(Information_t *);
int ENVIRO(Information_t *);
char *GET_ENVIROment(Information_t *, const char *);
int ENV_POPUL(Information_t *);
int UNSSET_ENVIRO(Information_t *);

/* GET_INVIRONMENT.c */
int _SET_ENVIRO(Information_t *, char *, char *);
int _UNSET_ENVIRO(Information_t *, char *);
char **GET_ENVIRO(Information_t *);


/* _LISTS.c */
void LISTS_FREE_(list_t **);
list_t *NODEADD_ATEND(list_t **, const char *, int);
size_t PRINT_LIST_STRING(const list_t *);
list_t *Nodes_Add(list_t **, const char *, int);
int REMO_Node_AT_INDEX(list_t **, unsigned int);

/* _LISTS_1.c */
list_t *_Nodes_bgin_WITH(list_t *, char *, char);
size_t LIST_LENG(const list_t *);
ssize_t RETRIEVE_NODE_AT_indexs(list_t *, list_t *);
size_t LIST_PRINTS(const list_t *);
char **LIST_STRINGS(list_t *);

/*HEIST.c */
int _hist_RE_NUM(Information_t *info);
int _hist_READ(Information_t *info);
int _hist_WRITE(Information_t *info);
char *GET_hist_FILES(Information_t *info);
int _Vhist_listbuild(Information_t *info, char *buff, int linecount);

/* SHELL_LOOP.c */
int hsh_loop(char **);
int CAPTURE_BUILTIN(Information_t *);
void CAPTURE_cmd(Information_t *);
int HSH(Information_t *, char **);
void cmd_FORKS(Information_t *);

#endif
