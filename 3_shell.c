#include "celem.h"

/**
 * implement - implement path
 * @param: parameter
 * Return: 0
 */

int implement(char **param)
{
	int value = fork(), output;

	if (value == 0)
	{
		if (execve(param[0], param, environ) == -1)
			perror("Error");
	}
	else
	{
		wait(&output);
		if (WIFEXITED(output))
        {
            output = WEXITSTATUS(output);
        }
	}

	return (output);
}

