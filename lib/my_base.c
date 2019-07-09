/*
** EPITECH PROJECT, 2018
** my_base.c
** File description:
** my_base
*/

#include <stdlib.h>
#include "my_printf.h"

int taille_num(int nb)
{
    int t = 0;

    while (nb / 10) {
        t++;
        nb = nb / 10;
    }
    return (t);
}

void disp_non_printable_string(char *src)
{
    int i = 0;

    while (src[i] != '\0') {
        if (src[i] < 27 || src[i] >= 127) {
            my_putchar(92);
            my_putstr("00");
            my_put_nbr(src[i], 0);
        }
        else
            my_putchar(src[i]);
        i++;
    }
}

char *my_put_nbr_oct_in_string(unsigned int nb)
{
    int n = 1;
    int j = 0;
    int result;
    int rest;
    char *src = malloc(sizeof(char) * taille_num(nb));

    while (nb > 0) {
        result = nb % 8;
        nb = nb / 8;
        src[j] = result + '0';
        j++;
    }
    return (my_revstr(src));
}

char *my_put_hex_maj_in_string(unsigned int nb)
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
            src[j] = n / 10 - 1 + 'A';
        nb = nb / 16;
        j++;
    }
    return (my_revstr(src));
}

char *my_put_nbr_bin_in_string(unsigned int nb)
{
    int n = 1;
    int j = 0;
    int result = 0;
    char *src = malloc(sizeof(char) * taille_num(nb));

    while (nb > 0) {
        n = nb % 2;
        src[j] = n + '0';
        nb = nb / 2;
        j++;
    }
    return (my_revstr(src));
}
