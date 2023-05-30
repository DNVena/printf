#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _prt - prints int
 * @n: takes int
 * Return: void
 */
void _prt(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	if (n / 10)
	{
		_prt(n / 10);
	}
	_putchar(n % 10 + '0');
}

/**
 * print_int - prints numbers
 * @format: takes pointer
 * Return: integer
 */
int print_int(const char *format, ...)
{
	int i = 0;

	va_list list;

	va_start(list, format);

	if (format == NULL)
	{
		return (-1);
	}

	if (format)
	{
		while (format[i])
		{
			_prt(va_arg(list, int));
			i++;
			break;
		}
	}
	va_end(list);
	return (0);
}
