/*
** EPITECH PROJECT, 2020
** battle
** File description:
** battle
*/

#include "game.h"
#include "fight.h"

void state_effect(rectangle_t *rects, int status)
{
    if (rects->consequence == false) {
        battle(status, rects);
        damage(rects, tarentula, 50);
        rects->consequence = true;
    }
}

void battle_prin(rectangle_t *rects, sfRenderWindow *window)
{
//    life_time(rects);
    if (rects->battle_status == 1)
        sfRenderWindow_drawRectangleShape(window, rects->fight_rects[4], NULL);
    if (rects->battle_status == 2)
        sfRenderWindow_drawRectangleShape(window, rects->fight_rects[7], NULL);
    if (rects->battle_status == 3)
        sfRenderWindow_drawRectangleShape(window, rects->fight_rects[8], NULL);
}
