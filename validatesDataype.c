#include "holberton.h"

/**
* validatesDataype - Function
* @format: parameter
* @list: parameter
* Return: int
*/

int validatesDataype(char format, va_list list)
{
	int c = 1;

	char *cadena, *cadNull = "(null)";

	switch (format)
	{
	case 'c':
		printChar(va_arg(list, int));
		break;
	case 's':

	cadena = va_arg(list, char *);

		if (cadena == NULL || cadena == '\0')
		{
			c = printString(cadNull);
		}
		else
		{
			c = printString(cadena);
		}
		break;
	case '%':
		printChar('%');
		break;
	case 'd':
		printInteger(list);
		break;
	case 'i':
		printInteger(list);
		break;
		default:
			printChar('%');
			c += printChar(format);
			break;
	}
	return (c);
}
