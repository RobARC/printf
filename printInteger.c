#include "holberton.h"
/**
* printInteger - Entry point
* @ap: list of arguments to receive.
* Return: ammount added to pointer.
*/
int printInteger(va_list ap)
{
	int n = va_arg(ap, int), last = n % 10, exp = 1;

	int i = 1, number, digt;

	n = n / 10;

	number = n;

	if (last < 0)
	{
		printChar('-');
		number = -number;
		n = -n;
		last = -last;
		i++;
	}
		if (number > 0)
		{
			while (number / 10 != 0)
			{
				exp = exp * 10;
				number = number / 10;
			}
			number = n;

			while (exp > 0)
			{
				digt = number / exp;
				printChar(digt + '0');
				number = number - (digt * exp);
				exp = exp / 10;
				i++;
			}
		}
		printChar(last + '0');
		return (i);
}
