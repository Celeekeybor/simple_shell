#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 256
/**
 * Splits the input string into individual arguments based on spaces, tabs, and newlines.
 *
 * @param input The input string to be split into arguments.
 * @return A pointer to an array of strings representing the individual arguments.
 *         The last element of the array is set to NULL.
 */
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

