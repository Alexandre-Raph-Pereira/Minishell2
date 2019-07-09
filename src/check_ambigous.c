/*
** EPITECH PROJECT, 2019
** boostrap
** File description:
** check_ambigous
*/

#include "my.h"

int condition_str(char *str)
{
    char **arr = my_str_to_word_array(str);

    if ((my_strcmp(arr[0], "env") != 0 || my_strlen(arr[0]) != 3) &&
        (my_strcmp(arr[0], "setenv") != 0 || my_strlen(arr[0]) != 6) &&
        (my_strcmp(arr[0], "unsetenv") != 0 || my_strlen(arr[0]) != 8) &&
        (my_strcmp(arr[0], "exit") != 0 || my_strlen(arr[0]) != 5) &&
        (my_strcmp(arr[0], "cd") != 0 || my_strlen(arr[0]) != 2)) {
        return (0);
    }
    return (1);
}

char *decoupe_str(char *str)
{
    int i = 0;
    char *str2 = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (str2 == NULL)
        exit(84);
    while (str[i] != '\0' && str[i] != ';') {
        str2[i] = str[i];
        i++;
    }
    str2[i] = '\0';
    return (str2);
}

char *recopy_str(char *str)
{
    int i = 0;
    int j = 0;
    char *str3 = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (str3 == NULL)
        exit(84);
    while (str[i] != '\0' && str[i] != ';') 
        i++;
    if (str[i] != '\0')
        i++;
    while (str[i] != '\0') {
        str3[j] = str[i];
        i++;
        j++;
    }
    str3[j] = '\0';
    return (str3);
}

void check_pipe(char *str, int i, int *pipe)
{
    while (str[i] != '\0') {
        if (str[i] == '|')
            (*pipe)++;
        i++;
    }
}

int check_ambigous(char *str)
{
    int pipe = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '>' || str[i] == '<')
            check_pipe(str, i, &pipe);
        if (pipe != 0)
            return (84);
        i++;
    }
    return (0);
}