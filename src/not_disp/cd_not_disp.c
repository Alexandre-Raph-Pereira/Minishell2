/*
** EPITECH PROJECT, 2019
** cd_function.c
** File description:
** cd_function
*/

#include "my.h"

int check_filepath_nd(char **arr)
{
    struct stat sb;

    if (stat(arr[1], &sb) == -1) {
        return (0);
    }
    if (S_ISDIR(sb.st_mode) == 0) {
        return (0);
    }
    else if ((sb.st_mode & S_IXUSR) == 0) {
        return (0);
    }
    return (1);
}

char **cd_not_disp(char *str, char *new_env[])
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
        if (check_filepath_nd(arr) == 1)
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
