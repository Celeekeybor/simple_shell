#include "shell.h"
/**
 * loop - function to get user input, tokonize directory and
 * check for builtins. Main loop to initiate shell
 * @env: double pointer
 * Return: void
 */
void loop(char **env)
{
	char *line;
	char **dir, **command;
	char *combine;

	while (1)
	{
		/**
		 *  Write prompt, then get user input
		 */
		prompt();
		signal(SIGINT, handler);
		line = get_line();
		/**
		 * Pass the command to be tokenized,
		 * Split the directories into tokens,
		 * Concat directory and input,
		 *  Check builtins
		 */
		command = split_line(line);
		dir = dirTok(env);
		combine = checkPath(dir, command[0]);
		checkBuiltins(combine, command);
		if (!combine)
			perror(combine);
	}
	buffers1(NULL, NULL);
	buffers2(NULL, NULL);
	buffers3(NULL, NULL);
	buffers4(NULL, NULL);
	buffers5(NULL);
}

