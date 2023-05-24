#include "main.h"

/**
 * search_path - show file path
 * @argc: cmd
 * Return: cmd path
 */

char *search_path(char *argc)
{
	char *path = _getenv("PATH"), *path_cpy;
	char **path_split;
	char *path_concat = NULL;
	int i = 0, path_len = 0;
	struct stat info;

	if (stat(argc, &info) == 0)
		return (argc);

	path_cpy = malloc(_strlen(path) + 1);

	path_cpy = _strcpy(path_cpy, path);
	path_split = _split(path_cpy, ":");

	while (path_split[i])
	{
		path_len = _strlen(path_split[i]);

		if (path_split[i][path_len - 1] != '/')
			path_concat = _strcat(path_split[i], "/");

		path_concat = _strcat(path_split[i], argc);

		if (stat(path_concat, &info) == 0)
			break;

		i++;
	}

	free(path_cpy);

	if (!path_split[i])
	{
		free(path_split);
		return (NULL);
	}

	free(path_split);
	return (path_concat);
}





