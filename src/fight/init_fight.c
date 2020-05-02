/*
** EPITECH PROJECT, 2020
** fight
** File description:
** init
*/
#include <stdlib.h>
#include <stdio.h>
#include "fight.h"
#include "game.h"

static const int nbr_enn = 3;

static const int var_def[] = {
    50,
    40,
    60,
};

int init_ennemies(rectangle_t *rect)
{
    if ((rect->life_ennemie = malloc(sizeof(int) * nbr_enn)) == NULL ||
        (rect->def_ennemie = malloc(sizeof(int) * nbr_enn)) == NULL)
        return 1;
    for (int i = 0; i <= 2; i++) {
        rect->life_ennemie[i] = 400;
        rect->def_ennemie[i] = var_def[i];
    }
    return 0;
}

int initia_fight(rectangle_t *rect)
{
    init_rectangle(rect);
    rect->etat = true;
    rect->god = true;
    rect->consequence = true;
    rect->life_clock = sfClock_create();
    rect->message = 0;
    rect->battle_status = 0;
    init_ennemies(rect);
    rect->part = create_part(100, (sfVector2f) {650, 300}, 0,
    (color_t) {sfRed, sfRed});
    return 0;
}
