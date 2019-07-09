/*
** EPITECH PROJECT, 2019
** unsetenv.c
** File description:
** unsetenv
*/

#include "my.h"

int check_arg_nd(char **arr)
{
    int t = 1;

    while (arr[t] != NULL) {
        if (my_str_isalpha(arr[t]) == 0) {
            return (0);
        }
        t++;
    }
    return (1);
}

char **remove_env_nd(char *str, char *new_env[])
{
    int i = 0;
    int j = 1;
    int u = 0;
    char **arr = my_str_to_word_array(str);
    int t = taille_arr(arr);

    if (t == 1) {
        return (new_env);
    }
    while (arr[j] != NULL) {
        while (u == 0 && new_env[i] != NULL) {
            new_env = find_remove(arr[j], new_env, i, &u);
            i++;
        }
        i = 0;
        j++;
        u = 0;
    }
    return (new_env);
}
