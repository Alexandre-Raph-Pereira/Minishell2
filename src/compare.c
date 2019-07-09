/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** compare
*/

#include "my.h"

char **compare_str(char *str, char *new_env[])
{
    char **arr = my_str_to_word_array(str);

    if (my_strcmp(arr[0], "env") == 0 && my_strlen(arr[0]) == 3)
        return (printf_env(new_env));
    if (my_strcmp(arr[0], "setenv") == 0 && my_strlen(arr[0]) == 6)
        return (setenv_function(str, new_env));
    if (my_strcmp(arr[0], "unsetenv") == 0 && my_strlen(arr[0]) == 8)
        return (remove_env(str, new_env));
    if (my_strcmp(arr[0], "cd") == 0 && my_strlen(arr[0]) == 2)
        return (cd_function(str, new_env));
    if (my_strcmp(arr[0], "exit") == 0 && my_strlen(arr[0]) == 4) {
        my_printf("exit\n");
        return(new_env);
    }
    if (my_exec(str, new_env) == 1)
        return (new_env);
    if (condition_str(str) == 0) {
        my_printf("%s: Command not found.\n", arr[0]);
        return (new_env);
    }
    return (new_env);
}
