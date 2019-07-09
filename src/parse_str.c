/*
** EPITECH PROJECT, 2019
** boostrap
** File description:
** parse_str
*/

#include "my.h"

char *find_left(char *str, char *token)
{
    int i = 0;
    char *str2 = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (str2 == NULL)
        exit(84);
    while (str[i] != token[0]) {
        str2[i] = str[i];
        i++;
    }
    str2[i] = '\0';
    return (str2);
}

char *find_right(char *str, char *token)
{
    int i = 0;
    int u = 0;
    char *str2 = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (str2 == NULL)
        exit(84);
    while (str[i] != token[0])
        i++;
    i++;
    while (str[i] != '\0') {
        str2[u] = str[i];
        i++;
        u++;
    }
    str2[u] = '\0';
    return (str2);
}