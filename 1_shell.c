#include "celem.h"
/**
 * blank_space - emptiness
 * @stats: line
 * Return: tr/fl
 */
int blank_space(char *stats)
{
int loop;
for (loop = 0; stats[loop] != '\0'; loop++)
{
if (stats[loop] != ' ')
return (0);
}
return (1);
}
