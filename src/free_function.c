/*
** EPITECH PROJECT, 2019
** free_function.c
** File description:
** free_function
*/

#include "my.h"

int taille_arr(char **str)
{
    int i = 0;

    while (str[i] != NULL)
        i++;
    return (i);
}

void free_arr(char **arr, int t)
{
    int i = 0;

    while (i < t) {
        free(arr[i]);
        i++;
    }
    free(arr);
}

void free_tab(char **arg)
{
    for (int i = 0; arg[i] != NULL; i++)
        free(arg[i]);
    free(arg);
}