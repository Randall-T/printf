#include "main.h"

/**
 * checker - Receives the main string and parameters to be printed
 * @format: character string
 * fxn_list: Associated function list
 * @arg_list: List of arguments to be passsed
 * Return: Count of characters printed
 */
int checker(const char *format, randy_t fxn_list[], va_list arg_list)
{
        int i, j, ret_val, printf_char;

        printf_char = 0;
        for (i = 0; format[i] != '\0'; i++)
        {
                if (format[i] == '%')
                {
                        for (j = 0; fxn_list[j].tg != NULL; j++)
                        {
                                if (format[i + 1] == fxn_list[j].tg[0])
                                {
                                        ret_val = fxn_list[j].fxn(arg_list);
                                        if (ret_val == -1)
                                                return (-1);
                                        printf_char += ret_val;
                                        break;
                                }
                        }
