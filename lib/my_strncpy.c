/*
** EPITECH PROJECT, 2018
** my_strncpy.c
** File description:
** copy n charactere d'une chaine
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n, int e)
{
    int i = 0;
    int t = 0;

    t = my_strlen(src);
    while (n != e && src[n]) {
        dest[i] = src[n];
        i++;
        n++;
    }
    dest[i] = '\0';
    return (dest);
}
