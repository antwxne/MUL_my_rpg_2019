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
}
