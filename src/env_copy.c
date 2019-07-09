/*
** EPITECH PROJECT, 2019
** env_copy.c
** File description:
** env_copy
*/

#include "my.h"

char **recopy_line(char **str, char **str2, int *u, int j)
{
    str[*u] = malloc(sizeof(char) * (my_strlen(str2[j]) + 1));
    if (str == NULL)
        return (NULL);
    if (str2[j][0] != '\0') {
        my_strcpy(str[*u], str2[j]);
        (*u)++;
    }
    free(str2[j]);
    return (str);
}

char **recopy_env(char *old_env[])
{
    char **new_env = NULL;
    int j = 0;
    int i = env_length(old_env);
    int u = 0;

    new_env = malloc(sizeof(char *) * (i + 1));
    if (new_env == NULL)
        return (NULL);
    while (old_env[j]) {
        new_env = recopy_line(new_env, old_env, &u, j);
        j++;
    }
    new_env[u] = NULL;
    free(old_env);
    return (new_env);
}
