#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 256
char* split_arguments(char* input)
{
static char* arguments[BUFFER_SIZE];
int index = 0;
char* token = strtok(input, " \t\n");
while (token != NULL)
{
arguments[index] = token;
index++;
token = strtok(NULL, " \t\n");
}
arguments[index] = NULL;
return (arguments);
}

