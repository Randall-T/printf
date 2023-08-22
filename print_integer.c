#include "main.h"

/**
 * print_positive_integer - Prints a positive integer.
 * @n: Positive integer to print.
 * @count: Pointer to the count of characters printed.
 * @flag_plus: Flag indicating the presence of the '+' flag.
 * @flag_space: Flag indicating the presence of the ' ' flag.
 */
void print_positive_integer(int n, int *count, int flag_plus, int flag_space)
{
	int a[10];
	int j, m, sum;

	m = 1000000000;
	a[0] = n / m;

	if (flag_plus)
	{
		_putchar('+');
		(*count)++;
	}
	else if (flag_space)
	{
		_putchar(' ');
		(*count)++;
	}

	for (j = 1; j < 10; j++)
	{
		m /= 10;
		a[j] = (n / m) % 10;
	}

	for (j = 0, sum = 0; j < 10; j++)
	{
		sum += a[j];
		if (sum != 0 || j == 9)
		{
			_putchar('0' + a[j]);
			(*count)++;
		}
	}
}

/**
 * print_i - Prints an integer.
 * @i: Integer to print.
 *
 * Return: Number of characters and digits printed.
 */
int print_i(va_list i)
{
	int n = va_arg(i, int);
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
