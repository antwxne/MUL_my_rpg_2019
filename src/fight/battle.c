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

void damage(game_t *game, int ennemies, int deg_ennemies)
{
    if (game->fight.message == 0)
        game->fight.battle_status = 1;
    if (game->fight.message == 1) {
        game->player.stat[0] -= (deg_ennemies - (game->player.stat[1] / 5));
        game->fight.battle_status = 2;
        sfRectangleShape_setSize(game->fight.fight_rects[6],
        (sfVector2f) {game->player.stat[0], 100});
    }
    if (game->fight.message == 2) {
        game->fight.life_ennemie[ennemies] -= (game->player.stat[2] -
        (game->fight.def_ennemie[ennemies] / 5));
        sfRectangleShape_setSize(game->fight.fight_rects[3],
        (sfVector2f) {game->fight.life_ennemie[ennemies], 100});
        game->fight.battle_status = 3;
        reset_part(game->fight.part, (sfVector2f) {650, 300}, 0, (color_t) {sfRed, sfRed});
    }
}

int life_time(rectangle_t *rects, int ennemies)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(rects->life_clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 5) {
        rects->etat = true;
        rects->battle_status = 0;
        sfClock_restart(rects->life_clock);
        if (rects->life_ennemie[ennemies] <= 0)
            return 1;
    }
    return 0;
}
