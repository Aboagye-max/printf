#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * hexadecimal - a fuction that changes an integer to a
 * hexadecimal
 * @nun: the number to be converted
 */

void hexadecimal(int num)
{
	char digit[] = "123456789abcdef";
	char hexa[64];
	int index = 0, i;

	if (num == 0)
	{
		putchar('0');
		return;
	}

	while (num > 0)
	{
		hexa[index++] = digit[num % 16];
		num /= 16;
	}

	for (i = index - 1; i >= 0; i--)
	{
		putchar(hexa[i]);
	}
}

/**
 * hex_print - a function that prints a hexadecimal
 * @format: the format to be oprinted
 * Return: the number of character printed
 */

int hex_printf(const char *format, ...)
{
	va_list ptr;
	int int_hexa = 0, count = 0;


	va_start(ptr, format);

	while (*format)
	{
		if ( *format == '%')
		{
			format++;

			if (*format == 'x')
			{
				int_hexa = va_arg(ptr, int);
				hexadecimal(int_hexa);
				count += 2;
			}
			else
			{
				putchar('%');
				putchar(*format);
				count += 2;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(ptr);

	return (count);
}
