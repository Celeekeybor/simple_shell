#include "shell.h"

/**
 * get_line - get line from command
 * Return: buffer
 */
char *get_line(void)
{
	char *buf = NULL;
	size_t bufsize = 0;
	int test;

	test = getline(&buf, &bufsize, stdin);
	buffers3(NULL, buf);

	if (test == EOF)
	{
		buffers1(NULL, NULL);
		buffers2(NULL, NULL);
		buffers3(NULL, NULL);
		buffers4(NULL, NULL);
		buffers5(NULL);
		_exit(0);
	}
	return (buf);
}

/**
 * split_line - split line into tokens
 * @line: command line input
 * Return: tokens
 */
char **split_line(char *line)
{
	char *dup_buf;
	char *token;
	char *toks;
	char **tok;
	int i = 1;

	dup_buf = _strdup(line);
	token = strtok(line, DELIM);
	while (token)
	{
		token = strtok(NULL, DELIM);
		i++;
	}
	tok = malloc(4096);
	buffers4(tok, NULL);

	toks = strtok(dup_buf, DELIM);
	i = 0;
	while (toks)
	{
		tok[i] = toks;
		toks = strtok(NULL, DELIM);
		i++;
	}
	tok[i] = '\0';
	return (tok);
}

