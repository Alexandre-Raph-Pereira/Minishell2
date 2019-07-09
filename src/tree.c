/*
** EPITECH PROJECT, 2019
** boostrap
** File description:
** tree
*/

#include "my.h"

void free_tree(node *tree)
{
    if (tree == NULL){
        return;
    }
    else if (tree != NULL && tree->left != NULL){
        free_tree(tree->left);
    }
    else if (tree != NULL && tree->right != NULL){
        free_tree(tree->right);
    }
    else { 
        free(tree);
    }
}