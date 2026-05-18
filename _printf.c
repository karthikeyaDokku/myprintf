#include <stdarg.h>
#include <stddef.h>
#include "main.h"

static int (*get_handler(char type))(va_list)
{
    specifier_t specifiers[] = {
        {'c', print_char},
        {'s', print_string},
        {'d', print_integer},
        {'i', print_integer},
        {'u', print_unsigned},
        {'o', print_octal},
        {'x', print_hex_lower},
        {'X', print_hex_upper},
        {'p', print_pointer},
        {'%', print_percent},
        {0,   NULL}
    };
    int i = 0;

    while (specifiers[i].type != 0)
    {
        if (specifiers[i].type == type)
            return (specifiers[i].handler);
        i++;
    }
    return (NULL);
}

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    int (*handler)(va_list);

    if (format == NULL)
        return (-1);
    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '\0')
                break;
            handler = get_handler(*format);
            if (handler)
                count += handler(args);
            else
            {
                count += _putchar('%');
                count += _putchar(*format);
            }
        }
        else
        {
            count += _putchar(*format);
        }
        format++;
    }
    va_end(args);
    return (count);
}
