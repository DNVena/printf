#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - prints char and string
 * @format: takes pointer
 * Return: int
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int j;
	char c;
	char *str;
	va_list list;

	va_start(list, format);
	if (format)
	{
		while (format[i])
		{
			switch (format[i])
			{
				case 'c':
					c = va_arg(list, int);
					_putchar(c);
					_putchar('\n');
					break;
				case 's':
					str = va_arg(list, char *);
					for (j = 0; str[j] != '\0'; j++)
					{
						_putchar(str[j]);
					}
					_putchar('\n');
					break;
				case '%':
					va_arg(list, char *);
					_putchar('%');
					_putchar('\n');
					break;
				default:
					i++;
					continue;
			}
			i++;
		}
	}
	va_end(list);
	return (0);
}
