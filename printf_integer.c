#include "main.h"

/**
 * print_integer - Prints an integer number
 * @args: Number argument from va_list
 * @printed: The number of characters printed so far
 * Return: The updated number of printed characters
 */

int print_integer(va_list args, int printed)
{
    int num = va_arg(args, int);
    int digits = 0;
    int temp = num;
    int digit;

    if (num < 0)
    {
        printed += _putchar('-');
        temp = -num;
    }

    if (temp == 0)
    {
        printed += _putchar('0');
        return printed;
    }

    while (temp != 0)
    {
        digits++;
        temp /= 10;
    }

    while (digits > 0)
    {
        int pow10 = 1;
        int i;

        for (i = 1; i < digits; i++)
        {
            pow10 *= 10;
        }

        digit = num / pow10;
        printed += _putchar(digit + '0');
        num -= digit * pow10;
        digits--;
    }

    return printed;
}
