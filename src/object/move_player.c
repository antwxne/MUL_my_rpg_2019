/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** move_player
*/

#include "game.h"
#include "main.h"

bool check_move(int **map, sfVector2u pos, int dir);

static void move(object_t *object, int dir)
{
    if (dir == UP) {
        object->position.y -= 1;
        sfSprite_setPosition(object->sprite, object->position);
    }
    if (dir == DOWN) {
        object->position.y += 1;
        sfSprite_setPosition(object->sprite, object->position);
    }
    if (dir == LEFT) {
        object->position.x -= 1;
        sfSprite_setPosition(object->sprite, object->position);
    }
    if (dir == RIGHT) {
        object->position.x += 1;
        sfSprite_setPosition(object->sprite, object->position);
    }
}

static bool can_move(sfVector2f reach, sfVector2f pos)
{
    return (reach.x == pos.x && reach.y == pos.y ? false : true);
}

void move_player(player_t *player)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(player->clock);
    seconds = time.microseconds / 100000.0;
    if (can_move(player->reach, player->ptr_obj.position) ||
    seconds > 0.1) {
        move(&player->ptr_obj, player->dir);
        sfClock_restart(player->clock);
    }
    if (!can_move(player->reach, player->ptr_obj.position))
        player->dir = NONE;
}
