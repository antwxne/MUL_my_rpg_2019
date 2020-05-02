/*
** EPITECH PROJECT, 2020
** mainfight
** File description:
** fight
*/

#include <stdio.h>
#include <stdlib.h>
#include "textures.h"
#include "game.h"
#include "fight.h"

static void beg_draw(game_t *png, rectangle_t *rects, int ennemie)
{
    position_sprite(png);
    sfRenderWindow_drawSprite(png->window, png->objects[PEGY][0].sprite, NULL);
    touch(rects, png);
    sfRenderWindow_drawSprite(png->window,
    png->objects[ennemie][0].sprite, NULL);
}

static int battle_init(game_t *png, rectangle_t *rects, int name_ennemies,
                    int ennemies_damage)
{
    int status = get_status(rects, png->event, png->window);

    if (rects->etat == false) {
        if (life_time(rects, name_ennemies, png) == 1) {
            rects->life_ennemie[name_ennemies] = 400;
            rects->god = true;
            return 1;
        }
        if (rects->god != false)
            battle_prin(rects, png->window, png->objects);
        else
            god_moding(rects, name_ennemies, png->window, png->objects);
    }
    state_effect(png, status, name_ennemies, ennemies_damage);
    return 0;
}

static int battle_second(game_t *png, rectangle_t *rects)
{
    if (rects->etat == true)
        change_color(rects);
    draw_sprite(png->window, rects->fight_rects, png->objects);
    get_echap(png, rects);
    if (rects->god == false)
        sfRenderWindow_drawRectangleShape(png->window,
        rects->fight_rects[5], NULL);
    return 0;
}

int fight(game_t *png, int ennemie, int name_ennemies, int ennemies_damage)
{
    beg_draw(png, &png->fight, ennemie);
    if (battle_init(png, &png->fight, name_ennemies, ennemies_damage) == 1) {
        sfRectangleShape_setSize(png->fight.fight_rects[3],
                                (sfVector2f) {400, 100});
        return 1;
    }
    if (png->player.stat[0] <= 0)
        return 2;
    battle_second(png, &png->fight);
    return 0;
}
