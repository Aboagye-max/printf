#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * u_printf - a fnction that prints an unsigned integer
 * @format: the format to be printed
 * Return: the number of chracters printed
 */

int u_printf(const char *format, ...)
{
	unsigned int u_int;
	int count = 0;
	va_list ptr;

	va_start(ptr, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'u')
			{
				u_int = va_arg(ptr, unsigned int);
				printf("%u", u_int);
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

	return (count);
}
