#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _prt - prints int
 * @n: takes int
 * Return: void
 */
int _prt(int n)
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
	return (0);
}

/**
 * print_int - prints numbers
 * @format: takes pointer
 * Return: integer
 */
int print_int(const char *format, ...)
{
	va_list list;

	va_start(list, format);

	if (format == NULL)
	{
		return (-1);
	}

	return (_prt(va_arg(list, int)));
}
