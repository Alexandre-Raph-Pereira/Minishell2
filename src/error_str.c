/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** error_str
*/

#include "my.h"

int error_str(char *str)
{
    if (str[0] == '|') {
        my_printf("Invalid null command.\n");
        return (0);
    }
    if (str[0] == '<' || str[0] == '>') {
        my_printf("Missing name for redirect.\n");
        return (0);
    }
    if (str[0] == ';')
        return (0);
    return (1);
}