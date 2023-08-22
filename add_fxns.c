#include "main.h"

/**
 * rev_string - Reverses a string
 * @s: String to reverse
 * Return: A pointer
 */
char *rev_string(char *s)
{
	int len;
	int tg;
	char tmp;
	char *randy;

	for (len = 0; s[len] != '\0'; len++)
	{}

	randy = malloc(sizeof(char) * len + 1);
	if (randy == NULL)
		return (NULL);

	_memcpy(randy, s, len);
	for (tg = 0; tg < len; tg++, len--)
	{
		tmp = randy[len - 1];
		randy[len - 1] = randy[tg];
		randy[tg] = tmp;
	}
	return (randy);
}

/**
 * put_base - Parses characters on standard output
 * @str: String to parse
 */
void put_base(char *str)
{
	int r;

	for (r = 0; str[r] != '\0'; r++)
		_putchar(str[r]);
}

/**
 * base_len - Calculates the length for a number
 * @num: Number's length
 * @base: Base required
 * Return: Length of number
 */
unsigned int base_len(unsigned int num, int base)
{
	unsigned int b;

	for (b = 0; num > 0; b++)
	{
		num = num / base;
	}
	return (b);
}

/**
 * _memcpy - Copies memory
 * @dest: Destination
 * @src: Source
 * @n: size
 * Return: Pointer to destination
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int m;

	for (m = 0; m < n; m++)
		dest[m] = src[m];
	dest[m] = '\0';
	return (dest);
}
