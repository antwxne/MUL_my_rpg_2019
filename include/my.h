/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/* lib */

int my_strlen(char const *str);
void my_putstr(char *str);
void my_putchar(char c);
int my_strlen(char const *str);
void my_swap(char *a, char *b);
int my_str_isnum(char const *str);
char *my_revstr(char *str);
int my_getnbr(char const *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(char const *src);
void my_putnbr(int nbr);
char *my_strcpy(char *dest, char const *src);
int *my_strcat_int(int *dest, int const *src, int size_dest, int size_src);
char *convert_in_bit(char str);
int my_putnbr_base(int nbr, char const *base);
char *my_realloc(char *str, int size);
char *get_next_line(int fd);
int *my_revstrint(int *str, int len);
int *decToBinary(int n);
int my_intlen(int o);
char *my_itoa(int o);
int *dec_to_binary(int n);
char **my_split(char *str, char c);
unsigned int my_strlen_c(char const *str, char const c);
void free_char_arr(char **arr, unsigned int start);

/* linked list */

typedef struct list_t
{
    long long int data;
    struct list_t *next;
}linked;

linked *my_params_to_list(int ac, char **av);
linked *my_create_list();
void print_link(linked *head);
linked *add_list(long long int data, linked *list);
int count_link(linked *head);

#endif /* !MY_H_ */
