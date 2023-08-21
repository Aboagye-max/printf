#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, int num);
int hex_printf(const char *format, ...);
int bin_printf(const char *format, ...);
int my_printf_int(const char *format, ...);
int oct_printf(const char *format, ...);
int _2_hex_printf(const char *format, ...);
int u_printf(const char *format, ...);
void hexadecimal(int num);
void Hexadecimal(int num);
void flush_buffer(char *buffer, int *buffer_index);
void _binary(int b);
void octal(int oct);

#endif
