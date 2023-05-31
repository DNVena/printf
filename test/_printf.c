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
	int i, j = 0, m, k = 0, len;
	char *str;
	char buffer[BUFF_SIZE];
	va_list list;

	va_start(list, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		while (format[k])
		{
			buffer[j++] = format[i];
			k++;
			break;
		}
	}
	if (buffer[0] == '%' && buffer[1] == 'c')
	{
		c = va_arg(list, int);
		_putchar(c);
		len = 1;
	}
	else if (buffer[0] == '%' && buffer[1] == 's')
	{
		str = va_arg(list, char *);
		for (m = 0; str[m] != '\0'; m++)
		{
			_putchar(str[m]);
		}
		len = m;
	}
	else
	{
		write(1, &buffer[0], j);
		len = j;
	}
	va_end(list);
	return (len);
}
