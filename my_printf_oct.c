#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * octal - a function that converts an in to an octal
 * oct: the number to be changed
 */

void octal(int oct)
{
	int Octal[64], index = 0, i;

	if (oct == 0)
	{
		putchar('0');
		return;
	}

	while (oct > 0)
	{
		Octal[index++] = oct % 8;
		oct = oct / 8;
	}

	for (i = index - 1; i >= 0; i--)
	{
		putchar(Octal[i] + '0');
	}
}


/**
 * oct_printf - a function that prints an octect
 * @format: the format to be printed
 * Return: the number of characters to be printed
 */

int oct_printf(const char *format, ...)
{
	int int_oct, count = 0;

	va_list ptr;

	va_start(ptr, format);

	while(*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'o')
			{
				int_oct = va_arg(ptr, int);
				printf("%o", int_oct);
				count++;
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

	return(count);
}
