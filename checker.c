#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: Format string
 *
 * Return: Number of printed characters
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			if (format[i] == 'b')
			{
				unsigned int num = va_arg(list, unsigned int);
				char binary[BUFF_SIZE];
				int binary_len = 0;

				if (num == 0)
					binary[binary_len++] = '0';
				else
				{
					while (num > 0)
					{
						binary[binary_len++] = (num % 2) + '0';
						num /= 2;
					}
				}

				while (binary_len--)
				{
					buffer[buff_ind++] = binary[binary_len];
					if (buff_ind == BUFF_SIZE)
						print_buffer(buffer, &buff_ind);
				}

				printed_chars += binary_len;
			}
			else
			{
				printed = handle_print(format, &i, list, buffer,
						       flags, width, precision, size);
				if (printed == -1)
					return (-1);
				printed_chars += printed;
			}
		}
	}

	print_buffer(buffer, &buff_ind);
	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer
 * @buffer: Array of characters
 * @buff_ind: Index at which to add the next character
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
