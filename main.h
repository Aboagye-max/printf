#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

typedef struct milk
{
	char *id;
	int (*f)(va_list);
} milk_t;

int _putchar(char c);
int _printf(const char *format, ...);
int print_c(va_list);
int print_s(va_list);
int print_per(va_list);
int print_di(va_list);
#endif
