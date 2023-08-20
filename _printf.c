#include <stdarg.h>
#include <stdio.h>
#include "main.h"


int digit_count(int n)
{
	int count = 0;

	while (n > 0 || n < 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
 
    while (*format != '\0') {
        if (*format == 's') {
	    int i = 0;
            char *s = va_arg(args, char *);
	    while (s[i] != '\0')
	    {
		_putchar(s[i]);
		i++;
	    }
        } else if (*format == 'c') {
            int c = va_arg(args, int);
            _putchar(c);
        } else if (*format == 'd' || *format == 'i') {
	        int i, k = 0, numlength;
		int n = va_arg(arg, int);
		unsigned int pos_n = 0;
		int mul = 1;
	
		if (n == 0)
		{
			_putchar(pos_n + '0');
			return (1);
		}
		else if (n < 0)
		{
			_putchar('-');
			pos_n = -n;
			k++;
		}
		else
		{
			pos_n = n;
		}
	
		numlength = digit_count(pos_n);
	
	/* calculate multiplier for largest place*/
		i = numlength;
		while (i != 1)
		{
			mul = mul * 10;
			i--;
		}
	/* print digit values as characters */
		_putchar((pos_n / mul) + '0');
		while (mul != 1)
		{
			mul = mul / 10;
			_putchar(((pos_n / mul) % 10) + '0');
		}
	
		k += numlength;
        }
        ++format;
    }
 
    va_end(args);
    return 0;
}
