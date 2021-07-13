/*
** EPITECH PROJECT, 2019
** function
** File description:
** for chained list
*/
#include "my.h"

void print_link(linked_t *head)
{
    linked_t *current_node = head;

    while (current_node != NULL) {
        my_putnbr(current_node->data);
        my_putchar(' ');
        current_node = current_node->next;
    }
    my_putchar('\n');
}

int count_link(linked_t *head)
{
    int cmp = 0;
    linked_t *current_node = head;

    while (current_node != NULL) {
        cmp++;
        current_node = current_node->next;
    }
    return (cmp);
}