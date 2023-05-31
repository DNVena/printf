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
	int i, len;
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
		len = 1;
	}
	if (format[1] == 's')
	{
		str = va_arg(list, char *);
		for (i = 0; str[i] != '\0'; i++)
		{
			_putchar(str[i]);
		}
		len = i;
	}
	if (format[1] == '%')
	{
		_putchar('%');
		len = 1;
	}
	va_end(list);
	return (len);
}
