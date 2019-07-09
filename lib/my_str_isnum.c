/*
** EPITECH PROJECT, 2018
** my_str_islower.c
** File description:
** return 1 si les charatères sont des minuscules
*/

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1); 
}
