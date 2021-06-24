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
/**
 * @brief len of string
 * @param str
 * @return len of string
 */
int my_strlen(char const *str);
/**
 * @brief print a string
 * @param str
 */
void my_putstr(char *str);
/**
 * @brief print a char
 * @param c
 */
void my_putchar(char c);
/**
 * @brief swap char values
 * @param a
 * @param b
 */
void my_swap(char *a, char *b);
/**
 * @brief string is num
 * @param str
 * @return 0 if true
 */
int my_str_isnum(char const *str);
/**
 * @brief reverse a string
 * @param str
 * @return
 */
char *my_revstr(char *str);
/**
 * @brief convert string to integer
 * @param str
 * @return integer
 */
int my_getnbr(char const *str);
/**
 * @brief concat 2 strings
 * @param dest
 * @param src
 * @return
 */
char *my_strcat(char *dest, char *src);
/**
 * @brief compare 2 strings
 * @param s1
 * @param s2
 * @return
 */
int my_strcmp(char const *s1, char const *s2);
/**
 * @brief duplicate a string
 * @param src
 * @return
 */
char *my_strdup(char const *src);
/**
 * @brief display a number
 * @param nbr
 */
void my_putnbr(int nbr);
/**
 * @brief copy string to another
 * @param dest
 * @param src
 * @return
 */
char *my_strcpy(char *dest, char const *src);
/**
 * @brief concat 2 int arrays
 * @param dest
 * @param src
 * @param size_dest
 * @param size_src
 * @return
 */
int *my_strcat_int(int *dest, int const *src, int size_dest, int size_src);
/**
 * @brief convert 8bits value to bit representation in string
 * @param str
 * @return
 */
char *convert_in_bit(char str);
/**
 * @brief print number in selected base
 * @param nbr
 * @param base
 * @return
 */
int my_putnbr_base(int nbr, char const *base);
/**
 * @brief realloc string
 * @param str
 * @param size
 * @return
 */
char *my_realloc(char *str, int size);
/**
 * @copybrief getline
 * @param fd
 * @return
 */
char *get_next_line(int fd);
/**
 * @brief reverse int
 * @param str
 * @param len
 * @return reversed int
 */
int *my_revstrint(int *str, int len);
/**
 * @brief convert decimal integer to binary
 * @param n
 * @return
 */
int *decToBinary(int n);
/**
 * @brief calc int len
 * @param o
 * @return int len
 */
int my_intlen(int o);
/**
 * @brief convert int to string
 * @param o
 * @return
 */
char *my_itoa(int o);
/**
 * @brief spilt string with delimiter
 * @param str
 * @param c
 * @return array of tokens
 */
char **my_split(char *str, char c);
/**
 * @brief strlen with delimiter
 * @param str
 * @param c
 * @return
 */
unsigned int my_strlen_c(char const *str, char const c);
/**
 * @brief free a string array
 * @param arr
 * @param start
 */
void free_char_arr(char **arr, unsigned int start);

/* linked_t list */

/**
 * @brief linked_t list for ll int
 * @struct list
 * @typedef linked_t
 */
typedef struct list
{
    long long int data;
    struct list *next;
}linked_t;
/**
 * @brief string array to list
 * @param ac
 * @param av
 * @return
 */
linked_t *my_params_to_list(int ac, char **av);
/**
 * @brief create a list
 * @return new list
 */
linked_t *my_create_list();
/**
 * @brief print linked list
 * @param head
 */
void print_link(linked_t *head);
/**
 * @brief add value to list
 * @param data
 * @param list
 * @return
 */
linked_t *add_list(long long int data, linked_t *list);
/**
 * @brief len of linked list
 * @param head
 * @return
 */
int count_link(linked_t *head);

#endif /* !MY_H_ */
