#include "main.h"

/
 * print_char - Print character
 * @list: lists arguments
 * Return: 1
 */
int print_char(va_list list)
{
        _putchar(va_arg(list, int));
        return (1);
}

/
 * print_percent - Prints %
 * @list: lists arguments
 * Return: 1
 */
int print_percent(attribute((unused))va_list list)
{
        _putchar('%');
        return (1);
}

/**
 * print_string - Print string
 * @list: lists arguments
 * Return: number of characters printed
 */
int print_string(va_list list)
{
        int t;
        char *str;

        str = va_arg(list, char *);

        if (str == NULL)
        {
                str = "(null)";
        }
        for (t = 0; str[t] != '\0'; t++)
        {
                _putchar(str[t]);
        }
        return (t);
}
