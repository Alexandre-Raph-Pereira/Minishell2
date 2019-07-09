/*
** EPITECH PROJECT, 2019
** setenv.c
** File description:
** setenv
*/

#include "my.h"

char **setenv_not_disp(char *str, char *new_env[])
{
    char **arr = my_str_to_word_array(str);
    int t = env_length(arr);

    if (t == 1 || t > 3 || check_arg(arr) == 0) {
        return (new_env);
    }
    if (t == 2)
        new_env = find_or_add_env(arr, new_env);
    if (t == 3)
        new_env = add_second_env(arr, new_env);
    free_arr(arr, t);
    if (new_env == NULL)
        return (NULL);
    return (new_env);
}
