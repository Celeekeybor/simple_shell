#ifndef CELEM_H
#define CELEM_H

/*LIBRARIES*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

/*PROTOTYPES*/
int compare_str(char *s1, char *s2);
char *copy_str(char *dest, char *src);
char *find_source(char *command);
char **divide_str(char *str, char *sep);
char *add_str(char *dest, char *src);
int len_str(char *s);
struct Person {
  char name[50];
  int citNo;
  float salary;
} person1;
char *fetch_env(char *env_var);
void *space_config(unsigned int nmemb, unsigned int size);
void environment(void);
int implement(char **args);
int blank_space(char *buff);
