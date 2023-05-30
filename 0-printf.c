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
	int i, j = 0;
	char buffer[BUFF_SIZE];
	va_list list;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(list, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '\0')
		{
			buffer[j++] = format[i];
		}
	}
	if (format[i] == '%')
	{
		_putchar('%');
	}
	else
	{
		write(1, &buffer[0], j);
	}

	va_end(list);
	return (i);
}
