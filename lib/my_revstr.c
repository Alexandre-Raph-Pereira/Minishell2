/*
** EPITECH PROJECT, 2018
** my_revstr.c
** File description:
** inversement d'une chaine
*/

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    int c = 0;

    while (str[i] != '\0') {
        i++;
    }
    i--;
    while (j < i) {
        c = str[j];
        str[j] = str[i];
        str[i] = c;
        i--;
        j++;
    }
    return (str);
}
