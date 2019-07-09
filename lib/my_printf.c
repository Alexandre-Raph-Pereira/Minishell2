/*
** EPITECH PROJECT, 2018
** printf.c
** File description:
** printf.c
*/

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "my_printf.h"

void disp_particulare(char *str, int *i, va_list ap)
{
    if (str[(*i) + 1] == 'l') {
        (*i)++;
        if (str[(*i) + 1] == 'd')
            disp_long(va_arg(ap, long int));
    }
    if (str[(*i) + 1] == 'u')
            disp_unsigned_int(va_arg(ap, unsigned int));
    if (str[(*i) + 1] == 't')
        disp_double_tab_char(va_arg(ap, char **));
    if (str[(*i) + 1] == '+') {
        my_put_nbr(va_arg(ap, int), 1);
        (*i)++;
    }
    if (str[(*i) + 1] == '-') {
        my_put_nbr(va_arg(ap, int), 0);
        (*i)++;
    }
}

void disp_base(char *str, int *i, va_list ap)
{
    if (str[(*i) + 1] == '#') {
        (*i)++;
        switch_format_hash(str, i);
    }
    if (str[(*i) + 1] == 'X')
        my_putstr(my_put_hex_maj_in_string(va_arg(ap, unsigned int)));
    if (str[(*i) + 1] == 'x')
        my_putstr(my_put_hex_min_in_string(va_arg(ap, unsigned int)));
    if (str[(*i) + 1] == 'o')
        my_putstr(my_put_nbr_oct_in_string(va_arg(ap, unsigned int)));
    if (str[(*i) + 1] == 'b')
        my_putstr(my_put_nbr_bin_in_string(va_arg(ap, unsigned int)));
    if (str[(*i) + 1] == 'S')
        disp_non_printable_string(va_arg(ap, char *));
    if (str[(*i) + 1] == '%')
        my_putstr("%");
    if (str[(*i) + 1] != 'X' && str[(*i) + 1] != 'x' && str[(*i) + 1] != 'o'
        && str[(*i) + 1] != 'b' && str[(*i) + 1] != 'S' && str[(*i) + 1] != '%')
        disp_particulare(str, i, ap);
}

void disp_argv(char *str, int i, va_list ap)
{
    while (str[i]) {
        if (str[i + 1] == 's')
            my_putstr(va_arg(ap, char *));
        if (str[i + 1] == 'c')
            my_putchar(va_arg(ap, int));
        if (str[i + 1] == 'd' || str[i + 1] == 'i')
            my_put_nbr(va_arg(ap, int), 0);
        if (str[i + 1] == 'p') {
            my_putstr("0x");
            my_putstr(my_put_hex_min_in_string(va_arg(ap, unsigned int)));
        }
        if (str[i + 1] != 's' && str[i + 1] != 'c' && str[i + 1] != 'p'
            && str[i + 1] != 'd' && str[i + 1] != 'i')
            disp_base(str, &i, ap);
        i = i + 2;
        while (str[i] != '%' && str[i]) {
            my_putchar(str[i]);
            i++;
        }
    }
}

int my_printf(char *str, ...)
{
    va_list ap;
    int i = 0;

    va_start(ap, str);
    if (my_strstr(str, "%") == 0)
        write(1, str, my_strlen(str));
    else {
        while (str[i] != '%') {
            my_putchar(str[i]);
            i++;
        }
        if (str[i + 1] == ' ')
            switch_format_space(str, &i);
        disp_argv(str, i, ap);
    }
    return (0);
}
