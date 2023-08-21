#include "main.h"

/**
 * print_number - prints number
 * @args: Lists arguments
 * Return: Number of arguments
 */
int print_number(va_list args)
{
        int tg;
        int randy;
        int len;
        unsigned int num;

        tg = va_arg(args, int);
        randy = 1;
        len = 0;

        if (tg < 0)
        {
                len += _putchar('-');
                num = tg * -1;
        }
        else
                num = tg;

        for (; num / randy > 9; )
                randy *= 10;

        for (; randy != 0; )
        {
                len += _putchar('0' + num / randy);
                num %= randy;
                randy /= 10;
        }

        return (len);
}
            
