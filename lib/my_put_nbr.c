/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** affiche un nombre
*/

void my_putchar(char c);

int my_put_nbr(int nb, int x)
{
    int n = 1;

    if (nb >= 0 && x == 1)
        my_putchar('+');
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    while ((nb / 10) / n != 0) {
        n = n * 10;
    }
    while (n > 0) {
        my_putchar(nb / n + '0');
        nb = nb % n;
        n = n / 10;
    }
    return (0);
}
