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

/**
 * _abs - computes absolute value of integer
 * @i: takes integer value
 * Return: Always 0
 */

int _abs(int i)
{
	int num;

	if (i < 0)
	{
		num = i * -1;
		return (num);
	}
	else if (i == 0)
	{
		num = i * 0;
		return (num);
	}
	else
	{
		num = i * 1;
		return (num);
	}
}

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
	int i, j = 0, k = 0;
	int num,  _len, len = 1;
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
	if (buffer[1] == 'd' || buffer[1] == 'i')
	{
		num = va_arg(list, int);
		_prt(num);
	}
	if (num < 0)
	{
		int num1;

		num1 = _abs(num);
		for (_len = 0; num1 > 0; _len++)
		{
			num1 = num1 / 10;
		}
		len = _len + 1;
	}
	else if (num > 0)
	{
		for (len = 0; num > 0; len++)
		{
			num = num / 10;
		}
	}
	va_end(list);
	return (len);
}
