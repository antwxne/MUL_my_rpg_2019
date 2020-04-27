/*
** EPITECH PROJECT, 2020
** battle
** File description:
** batlle
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "game.h"
#include "fight.h"

static int ennemies_turn(int status)
{
    static int a = 0;

    if (status != -1)
    {
        a = rand() % 3;
        return a;
    }
    return -1;
}

static int first_stape(int status, int ennemies)
{
    if ((ennemies == 0 && status == 0) ||
        (ennemies == 2 && status == 2) ||
        (ennemies == 1 && status == 1))
        return 0;
    if ((ennemies == 0 && status == 1) ||
        (ennemies == 1 && status == 2) ||
        (ennemies == 2 && status == 0))
        return 1;
    if ((ennemies == 0 && status == 2) ||
        (ennemies == 1 && status == 0) ||
        (ennemies == 2 && status == 1))
        return 2;
    return 4;
}

int battle(int status, rectangle_t *rects)
{
    int ennemies = ennemies_turn(status);

    if (ennemies != -1 && status != -1) {
        rects->message = first_stape(status, ennemies);
    }
    return 0;
}

void damage(rectangle_t *rects, int ennemies, int deg_ennemies)
{
    static int life_bibi = 100;
    int defense_bibi = 70;
    int degat_bibi = 50;

    if (rects->message == 0)
        rects->battle_status = 1;
    if (rects->message == 1) {
        life_bibi -= (deg_ennemies - (defense_bibi / 5));
        rects->battle_status = 2;
        sfRectangleShape_setSize(rects->fight_rects[6],
        (sfVector2f) {life_bibi, 100});
    }
    if (rects->message == 2) {
        rects->life_ennemie[ennemies] -= degat_bibi;
        sfRectangleShape_setSize(rects->fight_rects[3],
        (sfVector2f) {rects->life_ennemie[ennemies], 100});
        rects->battle_status = 3;
    }
}

void life_time(rectangle_t *rects)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(rects->life_clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 5) {
        rects->etat = true;
        rects->battle_status = 0;
        sfClock_restart(rects->life_clock);
    }
}
