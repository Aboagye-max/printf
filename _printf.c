#include <stdarg.h>
#include <stdio.h>
#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
 
    while (*format != '\0') {
        if (*format == 's') {
            int i = va_arg(args, int);
            printf("%s\n", i);
        } else if (*format == 'c') {
            // A 'char' variable will be promoted to 'int'
            // A character literal in C is already 'int' by itself
            int c = va_arg(args, int);
            printf("%c\n", c);
        } else if (*format == 'd') {
            int d = va_arg(args, int);
            printf("%d\n", d);
        } else if (*format == 'i'){
            int i = va_arg(args, int);
            printf("%i\n", d);
        }
        ++format;
    }
 
    va_end(args);
    return (0);
}
