#include "shell.h"

/**
* find_num_dir - Function to find the total number of directories
*@path: path string
*Return: number of directories in the path
*/
unsigned int find_num_dir(char *path)
{
	unsigned int i = 0, flag = 0, num_dir = 0;

	while (path[i])
	{
		if (path[i] != ':')
			flag = 1;

		if ((flag && path[i + 1] == ':') || (flag && path[i + 1] == '\0'))
		{
			num_dir++;
			flag = 0;
		}
		i++;
		}

		return (num_dir);
}

/**
* store_e_variables - Function that create a double pointer array, where stores
*each path directory as a pointer
*@fir_com: first command inserted in the prompt
*@environ: enviroment variables
*Return: enviroment
*/

char **store_e_variables(char *fir_com, char **environ)
{
	char **directories, *path_env, *directory;
	unsigned int length, i = 0;
	int dir_length, command_length;

	path_env = _getenv("PATH", environ);
	length = find_num_dir(path_env);
	directories = malloc(sizeof(char *) * (length + 1));
	if (directories == NULL)
		return (NULL);

	directory = strtok(path_env, ":");

	while (directory != NULL)
	{
		dir_length = _strlen(directory);
		command_length = _strlen(fir_com);
		directories[i] = malloc(sizeof(char *) *
		(dir_length + command_length + 2));
		if (directories[i] == NULL)
		{
			free_all_dp(directories);
			return (NULL);
		}
			_strncpcommand(directories[i], directory, fir_com,
			dir_length, command_length);
			i++;
		directory = strtok(NULL, ":");
	}

		directories[i] = NULL;

	return (directories);
}

/**
* _getenv - Function to get the enviroment variable
*@name: name of the enviroment variable
*@environ: enviroment variables
*Return: the value associated with the variable
*/

char *_getenv(const char *name, char **environ)
{
	char *env_value, *cp_name;
	unsigned int i = 0, length;

	/*find the length of the argument and malloc space for it*/
	length =  _strlen_const(name);

	cp_name = malloc(sizeof(char) * length + 1);
	if (cp_name == NULL)
		return (NULL);

	/*copy the contents of the name argument to cp_name*/
	_strncpyconst(cp_name, name, length);

	/*finding the enviroment variable*/
	env_value = strtok(environ[i], "=");
	while (environ[i])
	{
		if (_strcmp(env_value, cp_name))
			{																																										env_value = strtok(NULL, "\n");
			free(cp_name);
			return (env_value);
		}
		i++;
		env_value = strtok(environ[i], "=");
	}
	free(cp_name);
	return (NULL);
}

/**
* _strncpcommand - Function that copies the path and append a / and command
*@dest: destination to save
*@src: source
*@command: command to append
*@n: length of destination
*@c: length of command
*Return: addres of dest
*/

char *_strncpcommand(char *dest, char *src, char *command, int n, int c)
{
	int i, j;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	/*append "/" and "command" to the src*/
	dest[i] = '/';
	i++;

	for (j = 0; j < c && command[j] != '\0'; j++, i++)
		dest[i] = command[j];
	dest[i] = '\0';
	return (dest);
}

/**
* print_env - Function to print all enviroment variables
*@environ: enviroment variables for the user
*Return: Nothing(void)
*/

void print_env(char **environ)
{
	unsigned int i = 0, length;

	while (environ[i])
	{
		length = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], length);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

