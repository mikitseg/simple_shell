#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>



char *path_get(char **ENVIRO);

int NEW_PATH(char **path, char **ENVIRO);
char *GET_LINE_COMMAND(void);
void GET_ENVIRO(char **ENVIRO);

char **GET_TOKEN(char *LINEPTR);
void close_command(char **ARGS, char *LINEPR, int CLOSE);
int fork_function(char **path, char **avr,
		char **ENVIRO, char *LINEPTR, int np, int t);
char *TOKEN_STR(char *STR, const char *DELIMA);

int STRCOMP(char *strlen, char *strle);
size_t STRNCMP(char *strlen, char *strle, size_t z);
int STRLENG(char *T);
char *COPY_STR(char *DRIVE, char *SRC);
char *STRNCAT_S(char *DRIVE, char *SRC);
int _jputchar(char t);
char *STRCHAR(const char *q, int t);
size_t STRSPN(const char *strlen, const char *strle);
size_t STRCSPN(const char *strlen, const char *strle);

extern char **environ;
#endif /* SHELL_H */
