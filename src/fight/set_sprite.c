/*
** EPITECH PROJECT, 2020
** sprite
** File description:
** sprite
*/

#include "textures.h"
#include "game.h"
#include "fight.h"

void position_sprite(game_t *png)
{
    set_position(0, 0, png->objects[PEGY][0].sprite);
    set_position(500, 710, png->objects[ROCK][0].sprite);
    set_position(850, 710, png->objects[PAPYRUS][0].sprite);
    set_position(1200, 710, png->objects[CUTER][0].sprite);
    set_position(650, 0, png->objects[EN_1][0].sprite);
    set_position(840, 500, png->objects[DEAFET][0].sprite);
    set_position(810, 500, png->objects[VICTORY][0].sprite);
    set_position(810, 500, png->objects[EQUALITY][0].sprite);
    set_position(750, 0, png->objects[SHEEP][0].sprite);
    set_position(750, 0, png->objects[MERMS][0].sprite);
}

void draw_sprite(sfRenderWindow *window, sfRectangleShape **fight_rects,
                object_t **objects)
{
    for (int i = 0; i <= 3; i++)
        sfRenderWindow_drawRectangleShape(window, fight_rects[i], NULL);
    sfRenderWindow_drawRectangleShape(window, fight_rects[6], NULL);
    sfRenderWindow_drawSprite(window, objects[ROCK][0].sprite, NULL);
    sfRenderWindow_drawSprite(window, objects[PAPYRUS][0].sprite, NULL);
    sfRenderWindow_drawSprite(window, objects[CUTER][0].sprite, NULL);

}
