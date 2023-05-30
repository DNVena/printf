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
	int k = 0;
	int l = 0;
	char buffer[BUFF_SIZE];
	va_list list;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(list, format);
	if (format[l] == '%')
	{
		_putchar('%');
		return (1);
	}
	else
	{
		for (i = 0; format && format[i] != '\0'; i++)
		{
			while (format[k])
			{
				buffer[j++] = format[i];
				k++;
				break;
			}
		}
	}
	write(1, &buffer[0], j);

	va_end(list);
	return (i);
}
