/*
** EPITECH PROJECT, 2018
** my_str_isalpha.c
** File description:
** return 1 si la chaine n'a que des lettres
*/

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z')
            && (str[i] < '0' || str[i] > '9') && str[i] != '_') {
            return (0);
            }
        i++;
    }
    return (1);
}
