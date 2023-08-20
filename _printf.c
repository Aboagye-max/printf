#include <stdarg.h>
#include <stdio.h>
#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
 
    while (*format != '\0') {
        if (*format == 's') {
            // Use char* instead of int for strings
            char *s = va_arg(args, char*);
            printf("%s\n", s);
        } else if (*format == 'c') {
            // Use int instead of char for characters
            int c = va_arg(args, int);
            printf("%c\n", c);
        } else if (*format == 'd' || *format == 'i') {
            int d = va_arg(args, int);
            printf("%d\n", d);
        }
        ++format;
    }
 
    va_end(args);
    return (0); // Return a value other than 0 to indicate an error
}
