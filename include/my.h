/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <pwd.h>
#include <sys/sysmacros.h>
#include <time.h>
#include <grp.h>
#include <string.h>
#include <errno.h>
#include "my_printf.h"
#include "gnl.h"
#include "struct.h"

int my_printf(char *str, ...);
char **printf_env(char *env[]);
int my_strcmp(char const *s1, char const *s2);
char **my_str_to_word_array(char const *str);
char **reallocation(char **str, int taille);
char *my_strcat(char *dest, char const *str);
char **printf_env(char *env[]);
char **setenv_function(char *str, char *env[]);
char **recopy_env(char *env[]);
char **cd_function(char *str, char *new_env[]);
char *find_pwd(char *new_env[]);
char **find_old_pwd(char *str, char *new_env[]);
char **modif_arr(char **arr, char *new_env[]);
char **remove_env(char *str, char *new_env[]);
int check_exec(char **arr);
int my_exec(char *str, char *new_env[]);
char *is_a_bin(char *arr, char *new_env[]);
int taille_env(char *str);
char *my_getenv(char *new_env[], char *str);
void free_arr(char **arr, int t);
void free_tab(char **arg);
int env_length(char **arr);
char **add_env(char *new_env[], char **str, int i);
char **copy_env(char *old_env[]);
int check_bin(char *str, char *str2);
char **decoupe_arr(char **arr);
node *parse_tree(char *str, node **arbre);
void add_symbole_node(node **tree, char *str);
node *make_tree(char **str, node **tree);
char *find_left(char *str, char *token);
char *find_right(char *str, char *token);
char *recopy_str(char *str);
void check_pipe(char *str, int i, int *pipe);
int check_ambigous(char *str);
char *decoupe_str(char *str);
int my_str(char *str, char const *to_find);
char **exec_binary(node *tree, int pipefd[][2], char *env[]);
char **compare_str(char *str, char *new_env[]);
void add_redirection_node(node **elem, char *str, int *j);
int error_gestion(node *tree, char ***arr, int *fd_in, int *fd_out);
void free_tree(node *tree);
void status_gestion(int status);
char *my_strncpy(char *dest, char const *src, int n, int e);
void exec_inf(int pipefd[2], int fd_in, char *str);
void exec_sup(int pipefd[2], int fd_out, char **arr, char *str);
int taille_arr(char **str);
char **exec_redirect(node *tree, int fd_in, int pipefd[2], char *env[]);
char **exec_builtin(node *tree, in_out fd, int pipefd[2], char **env[]);
void father_gestion(pid_t pid, int *status, int pipefd[2], int *fd_in);
void write_environnement(char **new_env);
char **recup_env(void);
int condition_str(char *str);
char **my_str_to_tab(char const *str, char ch);

char **compare_not_disp(char *str, char *new_env[]);
char **cd_not_disp(char *str, char *new_env[]);
int check_filepath_nd(char **arr);
int condition_not_disp(char *str, node *tree);
char **setenv_not_disp(char *str, char *new_env[]);
int check_arg_nd(char **arr);
char **remove_env_nd(char *str, char *new_env[]);
char **find_filepath(char **arr, char *new_env[]);
char **find_remove(char *arr, char *new_env[], int i, int *u);
char **add_second_env(char **s, char *new_env[]);
char **find_or_add_env(char **str, char *new_env[]);
int check_arg_nd(char **arr);
char **find_home(char *new_env[]);
int check_arg(char **arr);
#endif /* !MY_H_ */
