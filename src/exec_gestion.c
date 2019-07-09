/*
** EPITECH PROJECT, 2019
** exec_gestion.c
** File description:
** exec_gestion
*/

#include "my.h"

int check_exec(char **arr)
{
    if ((arr[0][0] == '.' && arr[0][1] == '/') || arr[0][0] == '/' ||
        (arr[0][1] == '"' && arr[0][1] == '/'))
        return (1);
    return (0);
}

char **decoupe_arr(char **arr)
{
    char **arg = NULL;
    int j = 0;
    int i = 0;

    arg = malloc(sizeof(char *) * (env_length(arr) + 1));
    if (arg == NULL)
        exit(84);
    while (arr[i] != NULL) {
        arg[i] = malloc(sizeof(char) * (my_strlen(arr[j]) + 1));
        if (arg[i] == NULL)
            exit(84);
        my_strcpy(arg[i], arr[j]);
        i++;
        j++;
    }
    arg[i] = NULL;
    return (arg);
}

void status_gestion(int status)
{
    if (WIFSIGNALED(status)) {
        if (my_strcmp(strsignal(WTERMSIG(status)), 
            "Floating point exception") == 0)
            my_printf("Floating exception\n");
        else
            my_printf("%s\n", strsignal(WTERMSIG(status)));
        return;
    }
    if (WCOREDUMP(status)) {
        my_printf("%s\n", strsignal(WTERMSIG(status)));
        return;
    }
}

int check_bin(char *str, char *str2)
{
    struct stat sb;

    if (stat(str, &sb) == -1) {
        write(1, str2, my_strlen(str2));
        write(1, ": Command not found.\n,", 21);
        return (0);
    }
    else if ((sb.st_mode & S_IXUSR) == 0 || S_ISDIR(sb.st_mode) != 0) {
        my_putstr(str2);
        my_putstr(": Permission denied.\n");
        return (0);
    }
    return (1);
}

int my_exec(char *str, char *new_env[])
{
    char **arr = my_str_to_word_array(str);
    char **arg = decoupe_arr(arr);
    char *str2 = NULL;

    str2 = is_a_bin(arr[0], new_env);
    if (check_bin(str2, arr[0]) == 0)
        return (1);
    if (execve(str2, arg, new_env) == -1)
        my_printf("%s: Exec format error. Wrong Architecture.\n");
    return (1);
}
