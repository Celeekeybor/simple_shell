#ifndef CELEM_H
#define CELEM_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *search_path(char *command);
struct Point
{
int x;
int y;
};
char **_split(char *str, char *sep);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
struct Person
{
char name[50];
int citNo;
float salary;
} person1;
char *_getenv(char *env_var);
void *_calloc(unsigned int nmemb, unsigned int size);
void _env(void);
int execute(char **args);
struct shell_file
{
int id;
char buff[50];
int ppid;
};
int empty_line(char *buff);
extern char **environ;
#endif
