/*
** EPITECH PROJECT, 2020
** fight
** File description:
** init
*/

#include "fight.h"
#include <stdlib.h>

static const int nbr_enn = 1;

void init_ennemies(rectangle_t *rect)
{
    rect->life_ennemie = malloc(sizeof(int) * nbr_enn);
    rect->life_ennemie[tarentula] = 400;
}

int initia_fight(rectangle_t *rect)
{
    if (init_rectangle(rect) == 84)
        return 84;
    rect->etat = true;
    rect->god = true;
    rect->consequence = true;
    rect->life_clock = sfClock_create();
    rect->message = 0;
    rect->battle_status = 0;
    init_ennemies(rect);
    return 0;
}
