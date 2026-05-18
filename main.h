#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/* Specifier struct */
typedef struct specifier
{
    char type;
    int (*handler)(va_list);
} specifier_t;

/* Core */
int _printf(const char *format, ...);
int _putchar(char c);

/* Number helpers */
int print_number(long n);
int print_unsigned_number(unsigned long n);
int print_base(unsigned long n, int base, const char *digits);

/* Handler functions */
int print_char(va_list args);
int print_string(va_list args);
int print_integer(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex_lower(va_list args);
int print_hex_upper(va_list args);
int print_pointer(va_list args);
int print_percent(va_list args);

#endif /* _MAIN_H_ */
