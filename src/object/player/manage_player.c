/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** manage_player
*/

#include "game.h"
#include "main.h"

void manage_player(player_t *player)
{
    anim_player(player);
    move_player(player);
}