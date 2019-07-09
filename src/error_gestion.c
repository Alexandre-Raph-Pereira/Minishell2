/*
** EPITECH PROJECT, 2019
** boostrap
** File description:
** error_gestion
*/

#include "my.h"

int error_sup(char *arr)
{
    struct stat sb;

    if (stat(arr, &sb) == -1)
        return (0);
    else if ((sb.st_mode & S_IWUSR) == 0) {
        my_putstr2(arr);
        my_putstr2(": Permission denied.\n");
        return (84);
    }
    return (0);
}

int error_inf(char *arr, int *fd_in)
{
    struct stat sb;

    if (stat(arr, &sb) == -1) {
        my_putstr2(arr);
        my_putstr2(": No such file or directory\n");
        return (84);
    }
    else if ((sb.st_mode & S_IRUSR) == 0) {
        my_putstr2(arr);
        my_putstr2(": Permission denied.\n");
        return (84);
    }
    *fd_in = open(arr, O_RDONLY);
    return (0);
}

int error_gestion(node *tree, char ***arr, int *fd_in, int *fd_out)
{
    *arr = my_str_to_word_array(tree->right->str);
    if (tree->str[0] != '>' && tree->str[0] != '<')
        return (0);
    if (tree->str[0] == '>')
        return (error_sup((*arr)[0]));
    if (tree->str[0] == '<')
        return (error_inf((*arr)[0], fd_in));
    return (0);
}