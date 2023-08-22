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
/**
 * print_unsigned_number - Prints unsigned number
 * @n: Unsigned int
 * Return: Numbers printed
 */
int print_unsigned_number(unsigned int n)
{
	int randy;
	int len;
	unsigned int num;

	randy = 1;
	len = 0;
	num = n;

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

/**
 * int print_integer - Prints integer
 * @id: Arguments list
 * @Return: Count Characters
 */
int print_integer(va_list id)
{
	int len;

	len = print_number(id);

	return (len);
}

