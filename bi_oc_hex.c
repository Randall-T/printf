#include "main.h"

/**
 * print_binary - Converts base 10 to 2
 * @list: Arguments list
 * Return: Length of output
 */
int print_binary(va_list list)
{
	unsigned int num;
	int r, len;
	char *str;
	char *rev_str;

	num = va_arg(list, unsigned int);
	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);

	len = base_len(num, 2);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (-1);

	for (r = 0; num > 0; r++)
	{
		if (num % 2 == 0)
			str[r] = '0';
		else
			str[r] = '1';
		num = num / 2;
	}
	str[r] = '\0';
	rev_str = rev_string(str);
	if (rev_str == NULL)
		return (-1);
	put_base(rev_str);
	free(str);
	free(rev_str);
	return (len);
}

/**
 * print_octal - Prints numbers in base 8
 * @list: Argument list
 * Return: Number of symbols
 */
int print_octal(va_list list)
{
	unsigned int num;
	int len;
	char *oct_val;
	char *rev_str;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 8);

	oct_val = malloc(sizeof(char) * len + 1);
	if (oct_val == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		oct_val[len] = (num % 8) + 48;
		num = num / 8;
	}
	oct_val[len] = '\0';
	rev_str = rev_string(oct_val);
	if (rev_str == NULL)
		return (-1);

	put_base(rev_str);
	free(oct_val);
	free(rev_str);
	return (len);
}

/**
 * hex_check - Checks either hex functions
 * @num: Conversion var
 * @x: Chooses the hex function
 * Return: ASCII value
 */
int hex_check(int num, char x)
{
	char *hex = "abcdef";
	char *Hex = "ABCDEF";

	num = num - 10;
	if (x == 'x')
		return (hex[num]);
	else
		return (Hex[num]);
	return (0);
}

/**
 * print_hex - Prints numbers in lower base 16
 * @list: Argument list
 * Return: Number of characters printed
 */
int print_hex(va_list list)
{
	unsigned int num;
	int len;
	int mem_num;
	char *hex_val;
	char *rev_hex;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 16);
	hex_val = malloc(sizeof(char) * len + 1);
	if (hex_val == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		mem_num = num % 16;
		if (mem_num > 9)
		{
			mem_num = hex_check(mem_num, 'x');
			hex_val[len] = mem_num;
		}
		else
			hex_val[len] = mem_num + 48;
		num = num / 16;
	}
	hex_val[len] = '\0';
	rev_hex = rev_string(hex_val);
	if (rev_hex == NULL)
		return (-1);
	put_base(rev_hex);
	free(hex_val);
	free(rev_hex);
	return (len);
}

/**
 * print_heX - Prints numbers in upper base 16
 * @list: Argument list
 * Return: Number of characters printed
 */
int print_heX(va_list list)
{
	unsigned int num;
	int len;
	int mem_num;
	char *hex_val;
	char *rev_hex;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 16);
	hex_val = malloc(sizeof(char) * len + 1);
	if (hex_val == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		mem_num = num % 16;
		if (mem_num > 9)
		{
			mem_num = hex_check(mem_num, 'X');
			hex_val[len] = mem_num;
		}
		else
			hex_val[len] = mem_num + 48;
		num = num / 16;
	}
	hex_val[len] = '\0';
	rev_hex = rev_string(hex_val);
	if (rev_hex == NULL)
		return (-1);
	put_base(rev_hex);
	free(hex_val);
	free(rev_hex);
	return (len);
}
