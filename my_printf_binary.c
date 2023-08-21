#include <stdio.h>
#include <stdarg.h>

/**
 * _binary - a function that prints a binary
 * @b: the number to convert
 */

void _binary(int b)
{
	int binary[64], index = 0, i;
	
	if (b == 0)
	{
		putchar('0');
		return;
	}

	while (b > 0)
	{
		binary[index++] = b % 2;
		b /= 2;
	}

	for (i = index - 1; i >= 0; i--)
	{
		putchar(binary[i] + '0');
	}
}



/**
 * _printf - a function that prints the binary of a number using
 * a costom conversion 'b' and the specifier '%'
 * @format: the format to be printed
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int int_b, count = 0;
	va_list ptr;

	va_start(ptr, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'b')
			{
				int_b = va_arg(ptr, int);
				_binary(int_b);
				count++;
			}
			else
			{
				putchar('%');
				putchar(*format);
				count++;
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

int main() {
	    int num = 42;
	        _printf("Binary: %b\n", num);
		    return 0;
}
