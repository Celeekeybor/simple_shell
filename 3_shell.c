#include "shell.h"

/**
* execute - Function to verify and execute every command
*@commands: command get
*@buffer: command in getline
*@env: enviroment variable
*@argv: argument counter
*@count: number of times that executed
*Return: Nothing(void)
*/

void execute(char **commands, char *buffer, char **env, char **argv, int count)
{
	struct stat fileStat;

	/*check if command is NULL or empty spaces*/
	if (commands == NULL)
		null_command(buffer);
	/*check if command is exit to exit from shell*/
	else if (_strcmp("exit", commands[0]))
		get_out(buffer, commands);
	/* check if the command is ENV to print environment variables */
	else if (_strcmp("env", commands[0]))
		env_end(buffer, commands, env);
	/*check if the command is a full path to an executable file*/
	else if (stat(commands[0], &fileStat) == 0)
		execve(commands[0], commands, NULL);
	/*check all $PATH directories for executable commands*/
	else
		_path(commands, buffer, env, argv, count);
}

