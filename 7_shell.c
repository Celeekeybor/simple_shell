#include "shell.h"

/**
* INThandler - handles signals and write the prompt
*@sig: signal to handle
*Return: Nothing (void)
*/

void INThandler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
* print_dollar - Function to print the dollar sign
*Return: Nothing(void)
*/

void print_dollar(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}

/**
* main - principal function to run the shell
*@argc: argument count
*@argv: argument vector
*@env: enviroment variables
*Return: 0 on exit, 1 if any failures happen
*/

int main(int argc, char **argv, char **env)
{
	char *buffer, **commands;
	size_t length;
	ssize_t characters;
	pid_t pid;
	int status, count;
	(void)argc;
	buffer = NULL, length = 0, count = 0;
	/*write promt only if it's from standard input*/
	print_dollar();
	/*infinite loop*/
	while ((characters = getline(&buffer, &length, stdin)))
	{
		/*signal kill for contro+c */
		signal(SIGINT, INThandler);
		/*check the end of file*/
		if (characters == EOF)
			end_file(buffer);
		count++;
		/*collect commands from the prompt and store in double pointer*/
		commands = array_strtok(buffer);
		/*create new process*/
		pid = fork();
		if (pid == -1)
			fork_fail();
		if (pid == 0)
			execute(commands, buffer, env, argv, count);
		/*free everithing*/
		else
		{
			wait(&status);
			send_to_free(buffer, commands);
		}
		length = 0, buffer = NULL; /*reset for getline*/
		print_dollar();
	}
	if (characters == -1)
		return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
}

