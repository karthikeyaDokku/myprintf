#include <stdarg.h>
#include <stddef.h>
#include "main.h"

/**
 * print_char - Prints a single character
 * @args: va_list of arguments
 * Return: number of chars printed
 */
int print_char(va_list args)
{
    char c = (char)va_arg(args, int);
    return (_putchar(c));
}

/**
 * print_string - Prints a string
 * @args: va_list of arguments
 * Return: number of chars printed
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    if (str == NULL)
        str = "(null)";
    while (*str)
    {
        _putchar(*str);
        str++;
        count++;
    }
    return (count);
}

/**
 * print_integer - Prints a signed decimal integer
 * @args: va_list of arguments
 * Return: number of chars printed
 */
int print_integer(va_list args)
{
    int n = va_arg(args, int);
    int count = 0;
    long num = n;

    if (num < 0)
    {
        _putchar('-');
        count++;
        num = -num;
    }
    if (num >= 10)
        count += print_number(num / 10);
    _putchar((num % 10) + '0');
    count++;
    return (count);
}

/**
 * print_number - Helper to print digits recursively
 * @n: the number (must be >= 0)
 * Return: number of chars printed
 */
int print_number(long n)
{
    int count = 0;

    if (n >= 10)
        count += print_number(n / 10);
    _putchar((n % 10) + '0');
    count++;
    return (count);
}

/**
 * print_unsigned - Prints an unsigned decimal integer
 * @args: va_list of arguments
 * Return: number of chars printed
 */
int print_unsigned(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);

    return (print_unsigned_number((unsigned long)n));
}

/**
 * print_unsigned_number - Helper to print unsigned digits recursively
 * @n: unsigned long number
 * Return: number of chars printed
 */
int print_unsigned_number(unsigned long n)
{
    int count = 0;

    if (n >= 10)
        count += print_unsigned_number(n / 10);
    _putchar((n % 10) + '0');
    count++;
    return (count);
}

/**
 * print_octal - Prints an unsigned integer in octal
 * @args: va_list of arguments
 * Return: number of chars printed
 */
int print_octal(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);

    return (print_base((unsigned long)n, 8, "01234567"));
}

/**
 * print_hex_lower - Prints an unsigned integer in lowercase hex
 * @args: va_list of arguments
 * Return: number of chars printed
 */
int print_hex_lower(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);

    return (print_base((unsigned long)n, 16, "0123456789abcdef"));
}

/**
 * print_hex_upper - Prints an unsigned integer in uppercase hex
 * @args: va_list of arguments
 * Return: number of chars printed
 */
int print_hex_upper(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);

    return (print_base((unsigned long)n, 16, "0123456789ABCDEF"));
}

/**
 * print_base - Generic base printer (octal, hex, etc.)
 * @n: the number
 * @base: numeric base (8, 16, etc.)
 * @digits: digit characters to use
 * Return: number of chars printed
 */
int print_base(unsigned long n, int base, const char *digits)
{
    int count = 0;

    if (n >= (unsigned long)base)
        count += print_base(n / base, base, digits);
    _putchar(digits[n % base]);
    count++;
    return (count);
}

/**
 * print_pointer - Prints a pointer address in hex (0x...)
 * @args: va_list of arguments
 * Return: number of chars printed
 */
int print_pointer(va_list args)
{
    void *ptr = va_arg(args, void *);
    unsigned long addr = (unsigned long)ptr;
    int count = 0;

    count += _putchar('0');
    count += _putchar('x');
    count += print_base(addr, 16, "0123456789abcdef");
    return (count);
}

/**
 * print_percent - Prints a literal percent sign
 * @args: va_list (unused)
 * Return: 1
 */
int print_percent(va_list args)
{
    (void)args;
    return (_putchar('%'));
}
