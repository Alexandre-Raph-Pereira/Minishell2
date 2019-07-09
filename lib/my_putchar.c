/*
** EPITECH PROJECT, 2018
** my_putchar.c
** File description:
** affiche un charactere
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
