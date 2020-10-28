#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
* _printf - Function
* @format: parameter
* Return: int
*/

int _printf(const char *format, ...)
{
	int i = 0;
	int c = 0;

	va_list List;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(List, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				va_end(List);
				return (-1);
			}
			c = c + validatesDataype(format[i + 1], List);
			i++;
		}
		else
		c = c + printChar(format[i]);
		i++;
	}
	va_end(List);
	return (c);
}
