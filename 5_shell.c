#include "main.h"

/**
 * _calloc - allocate function
 * @argc: argument
 * @len: length
 * Return: zero
 */

void *_calloc(unsigned int argc, unsigned int len)
{
	unsigned int location = 0;
	char *show = NULL;

	if (argc == 0 || len == 0)
		return (NULL);

	show = malloc(argc * len);

	if (show == NULL)
		return (NULL);

	for (; location < (argc * len); location++)
    {
		show[location] = 0;
    }

	return (show);
}
