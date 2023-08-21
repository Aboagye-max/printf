#include <stdio.h>
#include <stdarg.h>


/**
 * my_printf_integer - a function that prints and integer
 * handling the conversion 'i' and 'd'
 * @format: the format to be printed
 * Return: the number of characters printed
 */


int _printf(const char *format, ...)
{
	va_list ptr;
	int int_d, int_i, count = 0;

	va_start(ptr, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'd')
			{
				int_d = va_arg(ptr, int);
				printf("%d", int_d);
				count++;
			}
			else if (*format == 'i')
			{
				int_i = va_arg(ptr, int);
				printf("%d", int_i);
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
	    int num = 42;
	        int printed = _printf("Integer: %d, Another Integer: %i\n", num, 100);
		    printf("Total characters printed: %d\n", printed);
		        return 0;
}
