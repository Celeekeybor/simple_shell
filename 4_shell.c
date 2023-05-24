#include "celem.h"

/**
 * main - shell project
 * Return: zero
 */

int main(void)
{
	char *data_flow = NULL, **elem;
	size_t get = 0;
	ssize_t data_size = 0;
	int cancel = 0;

	while (1)
	{
		if (isatty(0))
			printf("hsh$ ");

		data_size = getline(&data_flow, &get, stdin);
		if (data_size == -1 || _strcmp("exit\n", data_flow) == 0)
		{
			free(data_flow);
			break;
		}
		data_flow[data_size - 1] = '\0';

		if (_strcmp("env", data_flow) == 0)
		{
			_env();
			continue;
		}

		if (empty_line(data_flow) == 1)
		{
			cancel = 0;
			continue;
		}

		elem = _split(data_flow, " ");
		elem[0] = search_path(elem[0]);

		if (elem[0] != NULL)
        {
			cancel = execute(elem);
        }
        
		else
        {
			perror("Error");
        }
		free(elem);
	}
	return (cancel);
}
