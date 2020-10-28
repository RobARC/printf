#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "holberton.h"

/**
 * printString - print a string
 * @string: variable pointer
 * Return: int.
 */

int printString(char *string)
{
int c = 0;

	while (string[c] != '\0')
	{
		printChar(string[c]);
		c++;
	}
	return (c);
}
