/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** exec_redirection
*/

#include "my.h"

void exec_sup(int pipefd[2], int fd_out, char **arr, char *str)
{
    if (str[0] != '>')
        return;
    fd_out = open(arr[0] , O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    dup2(fd_out, STDOUT_FILENO);
    close(fd_out);
}

void exec_inf(int pipefd[2], int fd_in, char *str)
{
    if (str[0] != '<')
        return;
    close(pipefd[1]);
    dup2(fd_in, STDIN_FILENO);
    close(fd_in);
}

char **exec_redirect(node *tree, int fd_in, int pipefd[2], char *env[]) 
{
    if (tree->str[0] != '<')
        dup2(fd_in, 0);
    if (tree->str[0] != '>') {
        if (tree->right != NULL) {
            dup2(pipefd[1], 1);
        }
    }
    close(pipefd[0]);
    if (tree->left != NULL)
        env = compare_str(tree->left->str, env);
    return (env);
}

void father_gestion(pid_t pid, int *status, int pipefd[2], int *fd_in)
{
    waitpid(pid, status, 0);
    status_gestion(*status);
    close(pipefd[1]);   
    *fd_in = pipefd[0];
}