#include <stdio.h>

void my_printf(char *str)
{
    while (*str)
    {
        putchar(*str);
        str++;
    }
}

int main()
{
    my_printf("Hello World");

    return 0;
}


