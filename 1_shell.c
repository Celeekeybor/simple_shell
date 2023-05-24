#include "celem.h"

/**
 * empty_line - emptiness
 * @stats: line
 * Return: tr/fl
 */

int empty_line(char *stats)
{
	int loop;

	for (loop = 0; stats[loop] != '\0'; loop++)
	{
		if (stats[loop] != ' ')
			return (0);
	}
	return (1);
}

