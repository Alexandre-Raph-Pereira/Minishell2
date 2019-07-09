/*
** EPITECH PROJECT, 2019
** boostrap
** File description:
** symbole
*/

#include "my.h"

void add_redirection_node(node **elem, char *str, int *j)
{
    int u = 0;

    (*j)++;
    while (str[*j] && str[*j] != '|' && str[*j] != '<' && str[*j] != '>') {
        (*elem)->str[u] = str[*j];
        u++;
        (*j)++;
    }
    (*elem)->str[u] = '\0';
}

void add_symbole_node(node **elem, char *str)
{
    int u = 0;
    int i = 0;

    while (str[i] && str[i] != '|' && str[i] != '<' && str[i] != '>')
        i++; 
    while (str[i] && (str[i] == '|' || str[i] == '<' || str[i] == '>')) {
        (*elem)->str[u] = str[i];
        u++;
        i++;
    }
    (*elem)->str[u] = '\0';
}
