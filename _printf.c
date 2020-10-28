#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "holberton.h"

/**
 * print_c - adds a char to the pointer ptr
 * @lista: list of arguments a recibir.
 * @k: pointer counter.
 * @ptr: variable pointer.
 * Return: amount added to ptr.
 */

int print_c(va_list lista, char *ptr, int k)
{
	int a = va_arg(lista, int);

	ptr[k] = a;
	return (1);
}

/**
 * print_s - adds a string to the pointer ptr
 * @lista: list of arguments a recibir.
 * @ptr: variable pointer
 * @k: pointer counter.
 * Return: amount added to ptr.
 */

int print_s(va_list lista, char *ptr, int k)
{

	int i;
	char *str;

	str = va_arg(lista, char *);
	if (str == NULL)
	str = "(nil)";
	for (i = 0; str[i] != '\0'; i++, k++)
		ptr[k] = str[i];
	return (i);
}

/**
 * print_p- adds a string to the pointer ptr
 * @lista: list of arguments to receive.
 * @k: pointer counter.
 * @ptr: Variable pointer.
 * Return: amount added to ptr.
 */

int print_p(va_list lista, char *ptr, int k)
{
	(void) lista;
	ptr[k] = '%';
	return (1);
}

/**
 * print_int - adds a string of int to pointer ptr.
 * @lista: list of arguments to receive.
 * @ptr: variable pointer.
 * @k: pointer counter.
 * Return: ammount added to pointer.
 */

int print_int(va_list lista, char *ptr, int k)
{
	long int a = va_arg(lista, int), b = 0;
	long int temp = a, c = 0;

	if (a < 0)
	{
		temp = a *= -1;
		ptr[k] = '-';
		b++;
	}
	while (temp / 10 > 0)
	{
		temp = temp / 10;
		b++;
	}
	c = b;
	while (a / 10 > 0)
	{
		ptr[k + b] = a % 10 + '0';
		a = a / 10;
		b--;
	}
	ptr[k + b] = a % 10 + '0';
	c++;
	return (c);
}
/**
 * _printf - pseudo-printf function.
 * @format: ammount of parameters received.
 * Return: length of buffer.
 */
int _printf(const char *format, ...)
{
int i, j, k = 0, h = 0;
char *ptr;
	va_list lista;
	struct_0 array0[] = {{"c", print_c}, {"s", print_s}, {"%", print_p},
				{"d", print_int}, {"i", print_int}, {NULL, NULL},};
	ptr = malloc(1024);

	if (format == NULL || ptr == NULL)
		return (-1);
	va_start(lista, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			ptr[k] = format[i];
			k++;
		}
		else
		{
			if (format[i + 1] != '\0')
			{
				for (j = 0; array0[j].c; j++)
				{
					if (format[i + 1] == array0[j].c[0])
					{	h = array0[j].f(lista, ptr, k);
						i++;
						break;
					}
				}
				k = k + h;
			}
		}
	}
	write(1, ptr, k);
	free(ptr);
	va_end(lista);
	return (k);
}
