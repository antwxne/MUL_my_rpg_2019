/*
** EPITECH PROJECT, 2019
** my_params_to_list
** File description:
** create a new list from the command line argument
*/
#include "my.h"

linked_t *add_list(long long int data, linked_t *list)
{
    linked_t *first_case;

    first_case = malloc(sizeof(linked_t));
    first_case -> data = data;
    first_case -> next = list;
    return (first_case);
}

linked_t *my_create_list(void)
{
    linked_t *list;

    list = NULL;
    return (list);
}

linked_t *my_params_to_list(int ac, char **av)
{
    int cmp = 0;
    linked_t *list;

    list = NULL;
    cmp = ac-1;
    while (cmp != 0) {
        list = add_list(my_getnbr(av[cmp]), list);
        cmp--;
    }
    return (list);
}
