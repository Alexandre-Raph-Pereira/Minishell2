/*
** EPITECH PROJECT, 2019
** cd_function.c
** File description:
** cd_function
*/

#include "my.h"

int check_filepath(char **arr)
{
    struct stat sb;

    if (stat(arr[1], &sb) == -1) {
        my_putstr2(arr[1]);
        my_putstr2(": No such file or directory.\n");
        return (0);
    }
    if (S_ISDIR(sb.st_mode) == 0) {
        my_putstr2(arr[1]);
        my_putstr2(": Not a directory.\n");
        return (0);
    }
    else if ((sb.st_mode & S_IXUSR) == 0) {
        my_putstr2(arr[1]);
        my_putstr2(": Permission denied.\n");
        return (0);
    }
    return (1);
}

char **change_pwd(char *str, char *new_env[])
{
    int t = 0;

    while (my_strcmp(new_env[t], "PWD=") != 0 && new_env[t])
        t++;
    free(new_env[t]);
    new_env[t] = malloc(sizeof(char) * my_strlen(str) + 5);
    my_strcpy(new_env[t], "PWD=");
    my_strcat(new_env[t], str);
    return (new_env);
}

char **find_home(char *new_env[])
{
    int t = 0;
    int j = 0;
    int i = 0;
    char *str = malloc(sizeof(char) * 100);

    if (str == NULL)
        exit(84);
    while (my_strcmp(new_env[t], "HOME=") != 0 && new_env[t])
        t++;
    while (new_env[t][j] != '/')
        j++;
    while (new_env[t][j] != '\0') {
        str[i] = new_env[t][j];
        i++;
        j++;
    }
    str[i] = '\0';
    chdir(str);
    new_env = change_pwd(str, new_env);
    return (new_env);
}

char **find_filepath(char **arr, char *new_env[])
{
    int t = 0;
    char *str = malloc(sizeof(char) * 4094);
    size_t n = 4094;

    if (str == NULL)
        exit(84);
    while (my_strcmp(new_env[t], "PWD=") != 0 && new_env[t])
        t++;
    free(new_env[t]);
    chdir(arr[1]);
    getcwd(str, n);
    new_env[t] = malloc(sizeof(char) * my_strlen(str) + 5);
    if (new_env[t] == NULL)
        exit(84);
    my_strcpy(new_env[t], "PWD=");
    my_strcat(new_env[t], str);
    free(str);
    return (new_env);
}

char **cd_function(char *str, char *new_env[])
{
    char **arr = my_str_to_word_array(str);
    char *str2 = find_pwd(new_env);
    int t = env_length(arr);

    if (t == 1)
        new_env = find_home(new_env);
    if (t == 2 && my_strcmp(arr[1], "-") == 0 && my_strlen(arr[1]) == 1) {
        arr = modif_arr(arr, new_env);
        new_env = find_filepath(arr, new_env);
    }
    else if (t == 2) {
        if (check_filepath(arr) == 1)
            new_env = find_filepath(arr, new_env);
        else {
            free(str2);
            return (new_env);
        }
    }
    new_env = find_old_pwd(str2, new_env);
    free(str2);
    return (new_env);
}
