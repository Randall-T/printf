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
int print_number(va_list);
