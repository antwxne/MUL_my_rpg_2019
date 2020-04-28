/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** key_move
*/

#include "game.h"
#include "main.h"

static const sfIntRect dir_rect[] = {
    {32, 96, 32, 32},
    {32, 0, 32, 32},
    {32, 32, 32, 32},
    {32, 64, 32, 32},
};

static void key_up(player_t *player, int ***ptr_map)
{
    ptr_map[0][player->pos_arr.y][player->pos_arr.x] = 0;
    player->reach.y -= (float) rect_size;
    player->dir = UP;
    player->pos_arr.y -= 1;
    ptr_map[0][player->pos_arr.y][player->pos_arr.x] = 1;
}

static void key_down(player_t *player, int ***ptr_map)
{
    ptr_map[0][player->pos_arr.y][player->pos_arr.x] = 0;
    player->reach.y += rect_size;
    player->dir = DOWN;
    player->pos_arr.y += 1;
    ptr_map[0][player->pos_arr.y][player->pos_arr.x] = 1;
}

static void key_left(player_t *player, int ***ptr_map)
{
    ptr_map[0][player->pos_arr.y][player->pos_arr.x] = 0;
    player->reach.x -= rect_size;
    player->dir = LEFT;
    player->pos_arr.x -= 1;
    ptr_map[0][player->pos_arr.y][player->pos_arr.x] = 1;
}

static void key_right(player_t *player, int ***ptr_map)
{
    ptr_map[0][player->pos_arr.y][player->pos_arr.x] = 0;
    player->reach.x += rect_size;
    player->dir = RIGHT;
    player->pos_arr.x += 1;
    ptr_map[0][player->pos_arr.y][player->pos_arr.x] = 1;
}

void manage_key_player(player_t *player, int ***ptr_map)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) && player->dir == NONE) {
        sfSprite_setTextureRect(player->obj.sprite, dir_rect[UP]);
        if (check_move(*ptr_map, player->pos_arr, UP))
            key_up(player, ptr_map);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) && player->dir == NONE) {
        sfSprite_setTextureRect(player->obj.sprite, dir_rect[DOWN]);
        if (check_move(*ptr_map, player->pos_arr, DOWN))
            key_down(player, ptr_map);
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && player->dir == NONE) {
        sfSprite_setTextureRect(player->obj.sprite, dir_rect[LEFT]);
        if (check_move(*ptr_map, player->pos_arr, LEFT))
            key_left(player, ptr_map);
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) && player->dir == NONE) {
        sfSprite_setTextureRect(player->obj.sprite, dir_rect[RIGHT]);
        if (check_move(*ptr_map, player->pos_arr, RIGHT))
            key_right(player, ptr_map);
    }
}