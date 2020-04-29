/*
** EPITECH PROJECT, 2020
** battle
** File description:
** battle
*/

#include "textures.h"
#include "game.h"
#include "fight.h"

void state_effect(rectangle_t *rects, int status, int ennemies,
                int ennemies_damage)
{
    if (rects->consequence == false) {
        battle(status, rects);
        damage(rects, ennemies, ennemies_damage);
        rects->consequence = true;
    }
}

void battle_prin(rectangle_t *rects, sfRenderWindow *window, object_t **objects)
{
    if (rects->battle_status == 1) {
        sfRenderWindow_drawRectangleShape(window, rects->fight_rects[4], NULL);
        sfRenderWindow_drawSprite(window, objects[EQUALITY][0].sprite, NULL);
    }
    if (rects->battle_status == 2) {
        sfRenderWindow_drawRectangleShape(window, rects->fight_rects[7], NULL);
        sfRenderWindow_drawSprite(window, objects[DEAFET][0].sprite, NULL);
    }
    if (rects->battle_status == 3) {
        sfRenderWindow_drawRectangleShape(window, rects->fight_rects[8], NULL);
        sfRenderWindow_drawSprite(window, objects[VICTORY][0].sprite, NULL);
    }
}
