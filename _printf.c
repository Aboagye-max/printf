#include "main.h"

int _printf(const char *format, ...) {
     va_list args;
     va_start(args, format);
  
     while (*format != '\0') {
         if (*format == '%') {
             format++; // Move to the character after '%'
             
             if (*format == 's') {
                 char *str = va_arg(args, char *);
                 printf("%s", str);
             } else if (*format == 'c') {
                 int c = va_arg(args, int);
                 printf("%c", c);
             } else if (*format == 'd' || *format == 'i') {
                 int d = va_arg(args, int);
                 printf("%d", d);
             } else {
                 putchar('%');
                 putchar(*format);
             }
         } else {
             putchar(*format);
         }
         format++;
     }
  
     va_end(args);
     return 0;
 }
