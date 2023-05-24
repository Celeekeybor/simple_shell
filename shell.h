#ifndef _SHELL_H_
#define _SHELL_H_

/*libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/*main.c*/
void INThandler(int sig);
void print_dollar(void);

/*find_command.c*/
unsigned int find_length_command(char *s);
char **array_strtok(char *str);

/*execute.c*/
void execute(char **commands, char *buffer, char **env,
		char **argv, int count);

/*function_for_strings.c*/
char *_strncpy(char *dest, char *src, int n);
char *_strncpyconst(char *dest, const char *src, int n);
unsigned int _strlen_const(const char *str);
unsigned int _strlen(char *str);
int _strcmp(char *s1, char *s2);

/*env.c*/
unsigned int find_num_dir(char *path);
char **store_e_variables(char *fir_com, char **environ);
char *_getenv(const char *name, char **environ);
char *_strncpcommand(char *dest, char *src, char *command, int n, int c);
void print_env(char **environ);

/*free_all.c*/
void free_all_dp(char **ptr);
void parent_free_commands(char *buffer, char **commands);
void send_to_free(char *buffer, char **commands);

/*error_messages.c*/
void build_message(char **av, char *fir_com, int count);
int _puterror(char c);
void end_file(char *buffer);
void fork_fail(void);

/*child_process.c*/
void null_command(char *buffer);
void get_out(char *buffer, char **commands);
void env_end(char *buffer, char **commands, char **env);
void _path(char **commands, char *buffer, char **env, char **argv, int count);

#endif /*SHELL.H*/

