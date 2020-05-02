/*
** EPITECH PROJECT, 2019
** function
** File description:
** for chained list
*/
#include "my.h"

void print_link(linked *head)
{
    linked *current_node = head;

    while (current_node != NULL) {
        my_putnbr(current_node->data);
        my_putchar(' ');
        current_node = current_node->next;
    }
    my_putchar('\n');
}

int count_link(linked *head)
{
    int cmp = 0;
    linked *current_node = head;

    while (current_node != NULL) {
        cmp++;
        current_node = current_node->next;
    }
    return (cmp);
}