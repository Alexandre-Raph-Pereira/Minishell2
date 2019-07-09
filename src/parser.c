/*
** EPITECH PROJECT, 2019
** boostrap
** File description:
** parser
*/

#include "my.h"

node *add_left_node(char *str)
{
    int u = 0;
    int j = 0;
    node *elem = malloc(sizeof(node));

    elem->str = malloc(sizeof(char) * (my_strlen(str) + 1));
    if (elem == NULL || elem->str == NULL)
        exit (84);
    while (str[j] != '\0' &&str[j] != '|' && str[j] != '<' && str[j] != '>') {
        elem->str[u] = str[j];
        u++;
        j++;
    }
    elem->str[u] = '\0';
    elem->left = NULL;
    elem->right = NULL;
    return (elem);
}

node *add_right_node(char *str, char *str2, int *j)
{
    int i = *j;
    node *elem = malloc(sizeof(node));

    elem->left = NULL;
    elem->right = NULL;
    elem->str = malloc(sizeof(char) * (my_strlen(str) + 1));
    if (elem->str == NULL)
        exit(84);
    if (str2[0] == '|') {
        add_symbole_node(&elem, str);
        return (elem);
    }
    if (str2[0] == '>' || str2[0] == '<') {
        add_redirection_node(&elem, str, &i);
        return (elem);
    }
    elem->left = add_left_node(find_right(str, str2));
    return (elem);
}

char *get_token(char **str, int *j)
{
    int i = 0;
    int u = 0;
    char *token = malloc(sizeof(char) * (my_strlen(*str) + 1));

    if (token == NULL)
        exit(84);
    while ((*str)[i] != '\0' && (*str)[i] != '|' 
           && (*str)[i] != '<' && (*str)[i] != '>') {
        i++;
    }
    *j = i; 
    while ((*str)[i] == '|' || (*str)[i] == '<' || (*str)[i] == '>') {
        token[u] = (*str)[i];
        u++;
        i++;
    }
    token[u] = '\0';
    (*j)++;
    return (token);
}

int rewrite(char **str, char *token, char *right)
{
    int i = 0;

    if (token[0] == '>' || token[0] == '<') {
        (*str)[0] = '\0';
        return (0);
    }
    if (right[0] == '|') {
        while ((*str)[i] != token[0])
            i++;
        i++;
        my_strncpy(*str, *str, i, my_strlen(*str));
        return (0);
    }
    else {
        i = my_str(*str, token);
        i++;
        my_strncpy(*str, *str, i, my_strlen(*str));
        return (1);
    }
}

node *make_tree(char **str, node **tree) 
{
    int i = 0;
    int u = 0;
    char *token = get_token(str, &i);

    *tree = malloc(sizeof(node));
    (*tree)->str = malloc(sizeof(char) * (my_strlen(token) + 1));
    my_strcpy((*tree)->str, token);
    (*tree)->left = add_left_node(find_left(*str, token));
    (*tree)->right = NULL;
    if (token[0] != '\0')
        (*tree)->right = add_right_node(*str, token, &i);
    if (token[0] == '\0')
        return (*tree);
    u = rewrite(str, token, (*tree)->right->str);
    if ((*str)[0] != '\0') {
        if (u == 0)
            make_tree(str, &(*tree)->right);
        if (u == 1)
            make_tree(str, &(*tree)->right->right);
    }
    return (*tree);
}