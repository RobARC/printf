#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdio.h>
#include <stdarg.h>

/**
 *struct task0 - data type
 *@c: variable pointer
 *@f: pointer to function
 */
typedef struct task0
{
	char *c;
	int (*f)(va_list, char*, int);

} struct_0;

int print_c(va_list lista, char *ptr, int k);
int print_s(va_list lista, char *ptr, int k);
int print_p(va_list lista, char *ptr, int k);
int print_int(va_list lista, char *ptr, int k);
int _printf(const char *format, ...);


#endif
