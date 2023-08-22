#include "main.h"

/**
 * print_d - Prints a decimal.
 * @d: Decimal to print.
 *
 * Return: Number of characters and digits printed.
 */
int print_d(va_list d)
{
	int n = va_arg(d, int);
	int count = 0;
	int flag_plus = 0;
	int flag_space = 0;

	if (n < 0)
	{
		n *= -1;
	}
	else if (n >= 0 && flag_plus)
	{
		_putchar('+');
		count++;
	}
	else if (n >= 0 && flag_space)
	{
		_putchar(' ');
		count++;
	}

	print_positive_integer(n, &count, flag_plus, flag_space);

	return (count);
}
