/*
** EPITECH PROJECT, 2020
** fight
** File description:
** init
*/

#include "fight.h"

int initia_fight(rectangle_t *rect)
{
    if (init_rectangle(rect) == 84)
        return 84;
    return 0;
}
