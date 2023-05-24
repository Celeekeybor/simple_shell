#include "main.h"

/**
 * search_path - show file source
 * @argc: argument
 * Return: true/false
 */

char *search_path(char *argc)
{
	char *source = _getenv("PATH"), *source_dup;
	char **source_div;
	char *source_add = NULL;
	int mic = 0, source_size = 0;
	struct stat info;

	if (stat(argc, &info) == 0)
		return (argc);

	source_dup = malloc(_strlen(source) + 1);

	source_dup = _strcpy(source_dup, source);
	source_div = _split(source_dup, ":");

	while (source_div[mic])
	{
		source_size = _strlen(source_div[mic]);

		if (source_div[mic][source_size - 1] != '/')
        {
			source_add = _strcat(source_div[mic], "/");

		source_add = _strcat(source_div[mic], argc);
        }

		if (stat(source_add, &info) == 0)
			break;

		mic++;
	}

	free(source_dup);

	if (!source_div[i])
	{
		free(source_div);
		return (NULL);
	}

	free(source_div);
	return (source_add);
}
