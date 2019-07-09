/*
** EPITECH PROJECT, 2018
** my_strcat.c
** File description:
** concatène 2 chaines
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *str)
{
    int i = 0;
    int taille_chaine = my_strlen(dest);

    while (str[i] != '\0') {
        dest[taille_chaine + i] = str[i];
        i++;
    }
    dest[taille_chaine + i] = '\0';
    return (dest);
}
