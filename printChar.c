#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "holberton.h"

/**
 * printChar - Entry function print characters
 * @c: parameter
 * Return: add character
 */

int printChar(char c)
{
	return (write(1, &c, 1));
}
