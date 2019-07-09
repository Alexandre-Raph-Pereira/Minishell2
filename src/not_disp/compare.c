/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** compare
*/

#include "my.h"

int condition_not_disp(char *str, node *tree)
{
    char **arr = my_str_to_word_array(str);

    if ((my_strcmp(arr[0], "setenv") == 0 && my_strlen(arr[0]) == 6) ||
        (my_strcmp(arr[0], "unsetenv") == 0 && my_strlen(arr[0]) == 8) ||
        (my_strcmp(arr[0], "cd") == 0 && my_strlen(arr[0]) == 2) ||
        (my_strcmp(arr[0], "exit") == 0 && my_strlen(arr[0]) == 4)) {
        return (1);
    }
    return (0);
}

void exit_gestion(char **arr)
{
    if (arr[1] == NULL)
        exit(0);
    if (my_str_isalpha(arr[1]) == 1)
        exit(my_getnbr(arr[1]));
    else
        my_printf("exit: Expression Syntax\n");
}

char **compare_not_disp(char *str, char *new_env[])
{
    char **arr = my_str_to_word_array(str);

    if (my_strcmp(arr[0], "setenv") == 0 && my_strlen(arr[0]) == 6)
        return (setenv_not_disp(str, new_env));
    if (my_strcmp(arr[0], "unsetenv") == 0 && my_strlen(arr[0]) == 8)
        return (remove_env_nd(str, new_env));
    if (my_strcmp(arr[0], "cd") == 0 && my_strlen(arr[0]) == 2)
        return (cd_not_disp(str, new_env));
    if (my_strcmp(arr[0], "exit") == 0 && my_strlen(arr[0]) == 4) {
        exit_gestion(arr);
    }
    return (new_env);
}