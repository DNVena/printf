#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - prints char and string
 * @format: takes pointer
 * Return: int
 */
int _printf(const char *format, ...)
{
	char c;
	int i;
	char *str;
	va_list list;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(list, format);
	if (format[1] == 'c')
	{
		c = va_arg(list, int);
		_putchar(c);
		return (1);
	}
	if (format[1] == 's')
	{
		str = va_arg(list, char *);
		for (i = 0; str[i] != '\0'; i++)
		{
			_putchar(str[i]);
		}
		return (i);
	}
	if (format[1] == '%')
	{
		_putchar('%');
	}
	va_end(list);
	return (0);
}
