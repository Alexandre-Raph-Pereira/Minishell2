/*
** EPITECH PROJECT, 2019
** pwd_gestion.c
** File description:
** pwd_gestion
*/

#include "my.h"

char *my_getenv(char *new_env[], char *str)
{
    char *str2 = NULL;
    int t = 0;
    int i = 0;
    int j = 0;

    while (new_env[t] != NULL && my_strcmp(new_env[t], str) != 0)
        t++;
    if (new_env[t] == NULL)
        return (NULL);
    str2 = malloc(sizeof(char) * (my_strlen(new_env[t]) + 1));
    while (new_env[t][j] != '=')
        j++;
    j++;
    while (new_env[t][j] != '\0') {
        str2[i] = new_env[t][j];
        i++;
        j++;
    }
    str2[i] = '\0';
    return (str2);
}

char **modif_arr(char **arr, char *new_env[])
{
    char *str = my_getenv(new_env, "OLDPWD=");

    arr[1] = malloc(sizeof(char) * (my_strlen(str) + 1));
    my_strcpy(arr[1], str);
    return (arr);
}

char *find_pwd(char *new_env[])
{
    char *str = NULL;
    int t = 0;
    int i = 0;
    int j = 0;

    while (my_strcmp(new_env[t], "PWD=") != 0 && new_env[t] + 1)
        t++;
    str = malloc(sizeof(char) * (my_strlen(new_env[t]) + 1));
    if (str == NULL)
        exit(84);
    while (new_env[t][j] != '=')
        j++;
    j++;
    while (new_env[t][j] != '\0') {
        str[i] = new_env[t][j];
        i++;
        j++;
    }
    str[i] = '\0';
    return (str);
}

char **find_old_pwd(char *str, char *new_env[])
{
    int t = 0;

    while (new_env[t] && my_strcmp(new_env[t], "OLDPWD=") != 0)
        t++;
    free(new_env[t]);
    new_env[t] = malloc(sizeof(char) * (my_strlen(str) + 8));
    my_strcpy(new_env[t], "OLDPWD=");
    my_strcat(new_env[t], str);
    return (new_env);
}
