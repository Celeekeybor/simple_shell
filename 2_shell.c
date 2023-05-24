#include "celem.h"
/**
* fetch_env - receive environment var
* @elem: element
* Return: 0
*/
char *fetch_env(char *elem)
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
 * environment - write environment var
*/
void environment(void)
{
	int num = 0;

	while (environ[num])
	{
		printf("%s\n", environ[num]);
		num++;
	}
}



