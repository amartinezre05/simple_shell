#ifndef _SIMPLESHELL_
#define _SIMPLESHELL_

/* Libraries */
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

/* Prototypes */
char **usetok(char *buff);
extern char **environ;
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void printenv(void);
void _execve(char **args);
#endif
