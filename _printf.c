#include "main.h"

/**
 * _printf - Function prints out based on specified parameters
 * @format: character string
 * Return: Count of characters printed
 */
int _printf(const char *format, ...)
{
	int printf_char;
	randy_t fxn_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_number},
		{"i", print_integer},
		{"b", print_binary},
		{"u", unsigned_integer},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_hex},
		{"S", print_String},
		{"r", print_reversed},
		{"R", rot13},
		{NULL, NULL}
	};
	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);

	printf_char = checker(format, fxn_list, arg_list);
	va_end(arg_list);
	return (printf_char);
}
