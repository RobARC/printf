#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>


int printChar(char c);
int printString(char *string);
int printInteger(va_list ap);
int validatesDataype(char format, va_list list);
int _printf(const char *format, ...);

#endif
