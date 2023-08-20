#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int char_count = 0;

    while (*format != '\0') {
        if (*format == '%') {
            format++; // Move past the '%'
            char specifier = *format;

            switch (specifier) {
                case 'c':
                    putchar(va_arg(args, int));
                    char_count++;
                    break;
                case 's':
                    char *str = va_arg(args, char *);
                    while (*str != '\0') {
                        putchar(*str);
                        str++;
                        char_count++;
                    }
                    break;
                case '%':
                    putchar('%');
                    char_count++;
                    break;
                case 'd':
                case 'i':
                    // Handle integer printing
                    // Not implemented in this simplified version
                    break;
                // Handle other cases for different specifiers
                // ...
                default:
                    // Unsupported specifier, just print as is
                    putchar('%');
                    putchar(specifier);
                    char_count += 2;
                    break;
            }
        } else {
            putchar(*format);
            char_count++;
        }

        format++;
    }

    va_end(args);
    return char_count;
}
