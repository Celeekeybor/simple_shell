#include "shell.h"

/**
 * fork_fail - function that handles a fork fail
 * Return: Nothing
*/

void fork_fail(void)
{
	perror("Error: ");
	exit(EXIT_FAILURE);
}

/**
* build_message - Function to write an error message
*@av: argument vector
*@fir_com: first command to print if not found
*@count: number of times executed
*Return: Nothing(void)
*/

void build_message(char **av, char *fir_com, int count)
{
	int num_length = 1, cp, mult = 1;

	write(STDERR_FILENO, av[0], _strlen(av[0]));
	write(STDERR_FILENO, ": ", 2);
	cp = count;

	while (cp >= 10)
	{
		cp /= 10;
		mult *= 10;
		num_length++;
	}

	while (num_length > 1)
	{
		if ((count / mult) < 10)
			_puterror((count / mult + '0'));
		else
			_puterror((count / mult) % 10 + '0');
		--num_length;
		mult /= 10;
	}

	_puterror(count % 10 + '0');
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, fir_com, _strlen(fir_com));
	write(STDERR_FILENO, ": not found\n", 12);
}

/**
* _puterror - Prints a char
*@c: character to write
*Return: int to print
*/

int _puterror(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}

/**
* end_file - function to control the interrupt signal
*@buffer: buffer array created by new line
*Return: Nothing(void)
*/

void end_file(char *buffer)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(0);
}

