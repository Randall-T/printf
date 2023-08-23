#include "main.h"

/**
 * printer_pointer - Prints a pointer address
 * @list: Arguments list
 * Return: Character count
 */
int print_pointer(va_list list)
{
	int tg, count;
	void *randy = va_arg(list, void*);

	char hex[17];

	sprintf(hex, "%p", randy);
	count = 0;

	_putchar('0');
	_putchar('x');
	count +=2;

	for (tg = 2; hex[tg] != '\0'; tg++)
	{
		_putchar(hex[tg]);
		count++;
	}
	return (count);
}
