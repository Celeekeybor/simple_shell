#ifndef _SHELL_H_
#define _SHELL_H_

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <signal.h>
extern char **environ;
extern int dircount;
#define DELIM " \n\t"

void env(char **env);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
void prompt(void);
char *get_line(void);
char **split_line(char *line);
char *get_env(char **env);
char *pathCat(char *dir, char *av);
char **dirTok(char **env);
void loop(char **env);
char *checkPath(char **dir, char *command);
int execute(char *fullPath, char **command);
int exit_sh(char **command);
int cd(char **command);
int printenv(char **command);
int checkBuiltins(char *combine, char **command);
void handler(int sig);
void buffers1(char *line, char **command);
void buffers2(char **dir, char *combine);
void buffers3(char **tokens, char *buf);
void buffers4(char **tok, char *buf2);
void buffers5(char *dup);
#endif

