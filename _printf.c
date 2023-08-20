#include <stdarg.h>
#include <stdio.h>
#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
 
    while (*format != '\0') {
        if (*format == 's') {
            char *str = va_arg(args, char*);
            printf("%s\n", str);
        } else if (*format == 'c') {
            int c = va_arg(args, int);
            printf("%c\n", c);
        } else if (*format == 'd' || *format == 'i') {
            int num = va_arg(args, int);
            printf("%d\n", num);
        }
        ++format;
    }
 
    va_end(args);
    return 0;
}
