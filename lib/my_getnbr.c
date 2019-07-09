/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** my_getnbr
*/

int my_getnbr(char const *str)
{
    int i = 0;
    long nb = 0;
    int signe = 1;

    while (str[i] == '+' || str[i] == '-') {
        signe = str[i];
        i++;
    }
    if (signe == '-')
        signe = -1;
    else
        signe = 1;
    while (str[i] && str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10 + (str[i] - 48);
        if ((signe == -1 && nb > 2147483648) || (signe == 1 && nb > 2147483647))
            return (0);
        i++;
    }
    return (nb * signe);
}
