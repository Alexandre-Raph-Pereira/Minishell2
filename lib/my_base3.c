/*
** EPITECH PROJECT, 2018
** my_base3.c
** File description:
** my_base3
*/

#include "my_printf.h"

void disp_double_tab_char(char **str)
{
    int i = 0;

    while (str[i] != 0) {
        my_putstr(str[i]);
        my_putchar(' ');
        i++;
    }
}

void switch_format_hash(char *str, int *i)
{
    if (str[(*i) + 1] == 'x')
        my_putstr("0x");
    if (str[(*i) + 1] == 'X')
        my_putstr("0X");
    if (str[(*i) + 1] == 'o')
        my_putchar('0');
}

void switch_format_space(char *str, int *i)
{
    int nb_space = 0;
    int j = (*i);

    while (str[j + 1] == ' ') {
        j++;
        nb_space++;
    }
    if (str[j + 1] == 'd') {
        while ((*i) != j) {
            my_putchar(' ');
            (*i)++;
        }
    }
    else
        (*i) = j;
}
