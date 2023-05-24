#include "celem.h"

/**
 * _getenv - receive environment var
 * @elem: element
 * Return: 0
 */

char *_getenv(char *elem)
{
	int num = 0, val;
	int result;

	while (environ[num])
	{
		result = 1;

		for (val = 0; environ[num][val] != '='; val++)
		{
			if (environ[num][val] != elem[val])
				result = 0;
		}
		if (result == 1)
    {
        break;
        
    }
			
		num++;
	}
	return (&environ[num][val + 1]);
}

/**
 * _env - write environment var
*/
void _env(void)
{
	int num = 0;

	while (environ[num])
	{
		printf("%s\n", environ[num]);
		num++;
	}
}



