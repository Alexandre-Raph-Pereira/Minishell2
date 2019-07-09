/*
** EPITECH PROJECT, 2018
** my_base2.c
** File description:
** my_base2
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "my_printf.h"

char *my_put_hex_min_in_string(unsigned int nb)
{
    unsigned int n = 1;
    int j = 0;
    unsigned int result;
    char *src = malloc(sizeof(char) * taille_num(nb));

    while (nb >= 1) {
        n = nb % 16;
        if (n < 10)
            src[j] = n + '0';
        else
            src[j] = n / 10 - 1 + 'a';
        nb = nb / 16;
        j++;
        }
    return (my_revstr(src));
}

void disp_unsigned_int(unsigned int nb)
{
    unsigned int n = 1;

    if (nb == 0)
        my_putchar('0');
    while ((nb / 10) / n != 0) {
        n = n * 10;
    }
    while (n > 0) {
        my_putchar(nb/n + '0');
        nb = nb % n;
        n = n / 10;
    }
}

void disp_long(long long nb)
{
    long n = 1;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    else if (nb == 0)
        my_putchar('0');
    while ((nb / 10) / n != 0) {
        n = n * 10;
    }
    while (n > 0) {
        my_putchar(nb/n + '0');
        nb = nb % n;
        n = n / 10;
    }
}
