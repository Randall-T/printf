#include "main.h"

/**
 * print_String - Function prints string and nonprintable ASCII
 * @Str: String to print
 * Return: Printed characters
 */
int print_String(va_list Str)
{
	unsigned int t = 0;
	int count = 0;
	char *S = va_arg(Str, char *);

	if (S == NULL)
		S = "(null)";
	for (; S[t]; t++)
	{
		if (S[t] < 32 || S[t] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			count += 2;
			count += print_String(Str);
		}
		else
		{
			_putchar(S[t]);
			count++;
		}
	}
	return (count);
}
/**
 * print_reversed - Prints reversed string
 * @arg: Function Argument
 * Return: Number of characters printed
 */
int print_reversed(va_list arg)
{
	int len;
	char *tg;
	char *randy;

	tg = va_arg(arg, char *);
	if (tg == NULL)
		return (-1);
	randy = rev_string(tg);
	if (randy == NULL)
		return (-1);
	for (len = 0; randy[len] != '\0'; len++)
		_putchar(randy[len]);
	free(randy);
	return (len);
}

/**
 * rot13 - Converts string to rot13
 * @list: string
 * Return: converted string
 */
int rot13(va_list list)
{
	int r;
	int t;
	char *randy;
	char n[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char c[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	randy = va_arg(list, char *);
	if (randy == NULL)
		return (-1);
	for (r = 0; randy[r] != '\0'; r++)
	{
		for (t = 0; t <= 52; t++)
		{
			if (randy[r] == n[t])
			{
				_putchar(c[t]);
				break;
			}
		}
		if (t == 53)
			_putchar(randy[r]);
	}
	return (r);
}
