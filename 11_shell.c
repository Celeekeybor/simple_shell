#include "shell.h"
/**
 * prompt - function to print prompt
 * Return: void
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
	write(STDOUT_FILENO, "$ ", 2);
}

