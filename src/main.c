/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include "my.h"

char **exec_pipe(node *tree, char *new_env[], in_out fd)
{
    int pipefd[2];
    pid_t pid = getpid();
    int status = 0;
    char **arr = NULL;

    while (tree != NULL) {
        if (tree->right != NULL && 
            error_gestion(tree, &arr, &(fd).fd_in, &(fd.fd_out)) == 84)
            return (new_env);
        pipe(pipefd);
        pid = fork();
        if (pid == -1)
            exit(84);
        if (pid == 0) {
            exec_inf(pipefd, fd.fd_in, tree->str);
            exec_sup(pipefd, fd.fd_out, arr, tree->str);
            new_env = exec_redirect(tree, fd.fd_in, pipefd, new_env);
            exit(0);
        }
        if (pid > 0) {
            father_gestion(pid, &status, pipefd, &fd.fd_in);
            if (tree->left != NULL && 
                condition_not_disp(tree->left->str, tree) == 1)
                new_env = compare_not_disp(tree->left->str, new_env);
            tree = tree->right;
        }
    }
    return (new_env);
}

char **check_str(char *str, node *tree, char *new_env[])
{
    char *str2 = NULL;
    in_out fd;

    fd.fd_in = 0;
    fd.fd_out = 1;
    while (str[0] != '\0') {
        str2 = decoupe_str(str);
        if (check_ambigous(str2) == 84)
            return (new_env);
        tree = make_tree(&str2, &tree);
        new_env = exec_pipe(tree, new_env, fd);
        str = recopy_str(str);
        free_tree(tree);
    }
    return (new_env);
}

int main(int argc, char **argv, char *env[])
{
    char *str = NULL;
    char **new_env = NULL;
    node *tree = malloc(sizeof(node));
    size_t n = 0;

    new_env = copy_env(env);
    if (new_env == NULL || tree == NULL) 
        return (84);
    if (isatty(0) == 1)
        my_printf("$> ");
    while (getline(&str, &n, stdin) != -1) {
        if (str[0] != '\n' && error_str(str) == 1)
            new_env = check_str(str, tree, new_env);
        if (env == NULL)
            return (84);
        if (isatty(0) == 1)
            my_printf("$> ");
    }
    free_tab(new_env);
    return (0);
}