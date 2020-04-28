/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** move_player
*/

#include "game.h"
#include "main.h"

bool check_move(int **map, sfVector2u pos, int dir);

void move_player(player_t *player, int **map, int dir)
{
    //change_rect(&player->objet, dir);
    if (dir == UP && check_move(map, player->pos_arr, dir)) {
        player->objet.position.y -= 1;
        sfSprite_setPosition(player->objet.sprite, player->objet.position);
    }
    if (dir == DOWN && check_move(map, player->pos_arr, dir)) {
        player->objet.position.y += 1;
        sfSprite_setPosition(player->objet.sprite, player->objet.position);
    }
    if (dir == LEFT && check_move(map, player->pos_arr, dir)) {
        player->objet.position.x -= 1;
        sfSprite_setPosition(player->objet.sprite, player->objet.position);
    }
    if (dir == RIGHT && check_move(map, player->pos_arr, dir)) {
        player->objet.position.y += 1;
        sfSprite_setPosition(player->objet.sprite, player->objet.position);
    }
}
