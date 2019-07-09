/*
** EPITECH PROJECT, 2019
** exec_function.c
** File description:
** exec_function
*/

#include "my.h"

char *copy_path(char *dest, char *str, int i)
{
    int j = 0;

    while (str[i] != ':' && str[i] != '\0') {
        dest[j] = str[i];
        j++;
        i++;
    }
    dest[j] = '/';
    dest[j + 1] = '\0';
    return (dest);
}

char *find_path(char *new_env[], int t)
{
    char *str2 = my_getenv(new_env, "PATH");
    char *str = NULL;
    int i = 0;
    int u = 0;

    if (str2 == NULL)
        return (NULL);
    str = malloc(sizeof(char) * (my_strlen(str2) + 1));
    while (u < t && str2[i] != '\0') {
        i++;
        if (str2[i] == ':')
            u++;
    }
    if (str2[i] == '\0') {
        free(str2);
        return (NULL);
    }
    i++;
    str = copy_path(str, str2, i);
    free(str2);
    return (str);
}

char *is_a_bin(char *arr, char *new_env[])
{
    char *str = NULL;
    int t = 0;
    int l = 0;
    struct stat sb;

    while (t < 12 && (arr[0] != '.' && arr[1] != '/') && arr[0] != '/') {
        if (find_path(new_env, t) == NULL)
            return (arr);
        l = my_strlen(find_path(new_env, t)) + my_strlen(arr) + 1;
        str = malloc(sizeof(char) * (l + 1));
        if (str == NULL)
            exit(84);
        my_strcpy(str, find_path(new_env, t));
        my_strcat(str, arr);
        if (stat(str, &sb) != -1)
            return (str);
        t++;
    }
    return (arr);
}
