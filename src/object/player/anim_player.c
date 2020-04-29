/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** anim_player
*/

#include "game.h"
#include "main.h"

static const sfIntRect dir_rect[] = {
    {32, 96, 32, 32},
    {32, 0, 32, 32},
    {32, 32, 32, 32},
    {32, 64, 32, 32},
};

void set_rect_player(player_t *player, int dir)
{
    player->obj.rect = dir_rect[dir];
    sfSprite_setTextureRect(player->obj.sprite, player->obj.rect);
}

void anim_player(player_t *player)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(player->clock[1]);
    seconds = time.microseconds / 100000.0;
    if (player->dir == NONE) {
        player->obj.rect.left = 32;
        sfSprite_setTextureRect(player->obj.sprite, player->obj.rect);
    } else if (seconds > 0.8) {
        move_left_rect_l(&player->obj, 32, 64);
        sfClock_restart(player->clock[1]);
    } else
        return;
}