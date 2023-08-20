#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;
    char c;
    while ((c = *format++) != '\0') {
        if (c == '%') {
            c = *format++;
            if (c == '\0') {
                // Incomplete format specifier
                break;
            }
            switch (c) {
                case 'c':
                    putchar(va_arg(args, int));
                    count++;
                    break;
                case 's': {
                    const char *str = va_arg(args, const char *);
                    while (*str != '\0') {
                        putchar(*str);
                        str++;
                        count++;
                    }
                    break;
                }
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    putchar('%');
                    putchar(c);
                    count += 2;
                    break;
            }
        } else {
            putchar(c);
            count++;
        }
    }

    va_end(args);
    return count;
}
