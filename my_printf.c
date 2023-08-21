#include <stdio.h>
#include <stdarg.h>


/**
 * _printf - a function that prints a format to the consol
 * with respect to 'c' or 's' hanling the format specifier '%'
 * @format: the output to expect
 * Return: The number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list ptr;
	char c, *s;
	int count = 0;

	va_start(ptr, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'c')
			{
				c = (char)va_arg(ptr, int);
				putchar(c);
				count++;
			}
			else if(*format == 's')
			{
				s = va_arg(ptr, char *);
				while (*s)
				{
					putchar(*s);
					s++;
					count++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
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

int main() 
{
	    int printed = _printf("Character: %c, String: %s, Percent: %%\n", 'A', "Hello");
	        printf("Total characters printed: %d\n", printed);
		    return 0;
}

