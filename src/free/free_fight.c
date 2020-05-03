/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** free_fight
*/

#include <stdlib.h>
#include "destroy.h"
#include "game.h"

void free_fight(rectangle_t *fight)
{
    free(fight->life_ennemie);
    free(fight->def_ennemie);
    for (unsigned int i = 0; i < 9; i++)
        sfRectangleShape_destroy(fight->fight_rects[i]);
    free(fight->fight_rects);
    sfClock_destroy(fight->life_clock);
}