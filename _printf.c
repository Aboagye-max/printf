#include 'main.h'

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;
    while (*format != '\0') {
        if (*format == '%') {
            format++; // Move past the '%'

            // Handle conversion specifiers
            switch (*format) {
                case 'c':
                    putchar(va_arg(args, int)); // Print a character
                    count++;
                    break;
                case 's': {
                    const char *str = va_arg(args, const char *); // Get the string pointer
                    while (*str != '\0') {
                        putchar(*str); // Print each character of the string
                        str++;
                        count++;
                    }
                    break;
                }
                case '%':
                    putchar('%'); // Print a literal '%'
                    count++;
                    break;
                default:
                    // If an unsupported specifier is encountered, simply print the character
                    putchar(*format);
                    count++;
                    break;
            }
        } else {
            putchar(*format); // Print non-% characters as they are
            count++;
        }

        format++; // Move to the next character in the format string
    }

    va_end(args);

    return count;
}
