#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct randy - Defs a structure for symbols and functions
 * @tg: format
 * @fxn: associated function
 */
struct randy
{
	char *tg;
	int (*fxn)(va_list);
};

typedef struct randy randy_t;


int _putchar(char c);
int _printf(const char *format, ...);
int checker(const char *format, randy_t fxn_list[], va_list arg_list);
int print_char(va_list);
int print_percent(va_list);
int print_string(va_list);
int print_number(va_list );
int print_integer(va_list);
int print_binary(va_list);
int unsigned_integer(va_list);
int print_octal(va_list list);
int print_hex(va_list list);
int print_heX(va_list list);
int print_String(va_list);
int print_reversed(va_list arg);
int rot13(va_list);

unsigned int base_len(unsigned int, int);
char *rev_string(char *);
void put_base(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);
int print_unsigned_number(unsigned int);

#endif /* MAIN_H */
