/*
** EPITECH PROJECT, 2019
** boostrap
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct in_out
{
    int fd_in;
    int fd_out;
} in_out;

typedef struct node
{
    char *str;
    char **arg;
    struct node *left;
    struct node *right;
} node;

#endif /* !STRUCT_H_ */
