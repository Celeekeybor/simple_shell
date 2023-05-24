#include "celem.h"
/**
 * find_source - show file source
 * @elem: element
 * Return: cmd source
 */

char *find_source(char *elem)
{
	char *source = fetch_env("PATH"), *source_dup;
	char **source_div;
	char *source_add = NULL;
	int d = 0, source_size = 0;
	struct stat info;

	if (stat(elem, &info) == 0)
    {
		return (elem);
    }
	source_dup = malloc(len_str(source) + 1);

	source_dup = copy_str(source_dup, source);
	source_div = (source_dup, ":");

	while (source_div[d])
	{
		source_size = len_str(source_div[d]);

		if (source_div[d][source_size - 1] != '/')
        {
			source_add = (source_div[d], "/");
        }

		source_add = (source_div[d], elem);

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





