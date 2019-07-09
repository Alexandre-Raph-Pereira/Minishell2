/*
** EPITECH PROJECT, 2018
** malib.h
** File description:
** malib
*/

#ifndef MY_PRINTF_H
#define MY_PRINTF_H

void disp_non_printable_string(char *src);
void disp_double_tab_char(char **str);
char *my_put_nbr_hex_min_in_string(unsigned int nb);
void disp_unsigned_int(unsigned int nb);
void disp_long(long long nb);
char *my_put_nbr_bin_in_string(unsigned int nb);
char *my_put_hex_maj_in_string(unsigned int nb);
char *my_put_hex_min_in_string(unsigned int nb);
char *my_put_nbr_oct_in_string(unsigned int nb);
void my_putchar (char c);
int my_put_nbr(int nb, int x);
int my_putstr(char const *str);
char *my_strstr(char *str,char const *to_find);
int my_strlen(char const *str);
char *my_revstr(char *str);
int taille_num(int nb);
void switch_format_hash(char *str, int *i);
void switch_format_space(char *str, int *i);
int my_getnbr(char const *str);
char *my_strcpy(char *desp, char const *src);
void my_putstr2(char const *str);
int my_str_isalpha(char const *str);
#endif /* ! MY_PRINTF_H */
