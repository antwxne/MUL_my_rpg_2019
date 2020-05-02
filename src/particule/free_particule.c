/*
** EPITECH PROJECT, 2020
** 42
** File description:
** 42
*/

#include "particule.h"

void free_node_part(part_t **part)
{
    part_t *temp = *part;

    if (temp == NULL)
        return;
    sfRectangleShape_destroy(temp->shape);
    (*part) = temp->next;
    free(temp);
}

void free_part(part_t *part)
{
    while (part != NULL)
        free_node_part(&part);
}