#include "celem.h"

/**
 * search_path - show file source
 * @elem: element
 * Return: cmd source
 */

char *search_path(char *elem)
{
	char *source = _getenv("PATH"), *source_dup;
	char **source_div;
	char *source_add = NULL;
	int d = 0, source_size = 0;
	struct stat info;

	if (stat(elem, &info) == 0)
    {
		return (elem);
    }
	source_dup = malloc(_strlen(source) + 1);

	source_dup = _strcpy(source_dup, source);
	source_div = _split(source_dup, ":");

	while (source_div[d])
	{
		source_size = _strlen(source_div[d]);

		if (source_div[d][source_size - 1] != '/')
        {
			source_add = _strcat(source_div[d], "/");
        }

		source_add = _strcat(source_div[d], elem);

		if (stat(source_add, &info) == 0)
			break;

		d++;
	}

	free(source_dup);

	if (!source_div[d])
	{
		free(source_div);
		return (NULL);
	}

	free(source_div);
	return (source_add);
}





