/*
** EPITECH PROJECT, 2019
** setenv.c
** File description:
** setenv
*/

#include "my.h"

char **concat_str(char *env[], char **str, int i)
{
    int nb = my_strlen(str[1]) + my_strlen(str[2]);

    env[i] = malloc(sizeof(char) * (nb + 1));
    if (env[i] == NULL)
        return (NULL);
    my_strcpy(env[i], str[1]);
    my_strcat(env[i], "=");
    my_strcat(env[i], str[2]);
    return (env);
}

void not_good_argument(int t, char *new_env[])
{
    if (t == 1)
        printf_env(new_env);
    else if (t > 3)
        my_putstr2("setenv: Too many arguments.\n");
}

char **find_or_add_env(char **str, char *new_env[])
{
    int i = 0;

    for (i = 0; new_env[i] != NULL; i++) {
        if (my_strcmp(new_env[i], str[1]) == 0 &&
            my_strlen(str[1]) == taille_env(new_env[i]))
            return (add_env(new_env, str, i));
    }
    new_env = reallocation(new_env, i + 1);
    new_env[i] = malloc(sizeof(char) * (my_strlen(str[1]) + 3));
    if (new_env[i] == NULL)
        return (NULL);
    my_strcpy(new_env[i], str[1]);
    my_strcat(new_env[i], "=");
    return (new_env);
}

char **add_second_env(char **s, char *new_env[])
{
    int i = 0;

    for (i = 0; new_env[i]; i++) {
        if (my_strcmp(s[1], new_env[i]) == 0 &&
            my_strlen(s[1]) == taille_env(new_env[i]))
            return (concat_str(new_env, s, i));
    }
    new_env = reallocation(new_env, i);
    new_env[i] = malloc(sizeof(char) * my_strlen(s[1]) + my_strlen(s[2]) + 2);
    if (new_env[i] == NULL)
        return (NULL);
    my_strcpy(new_env[i], s[1]);
    my_strcat(new_env[i], "=");
    my_strcat(new_env[i], s[2]);
    return (new_env);
}

char **setenv_function(char *str, char *new_env[])
{
    char **arr = my_str_to_word_array(str);
    int t = env_length(arr);

    if (t == 1 || t > 3 || check_arg(arr) == 0) {
        not_good_argument(t, new_env);
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
