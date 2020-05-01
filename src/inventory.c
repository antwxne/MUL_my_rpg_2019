/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inventory
*/

#include "inventory.h"
#include "textures.h"

static void set_pos(float x, float y, object_t *object)
{
    object[0].position.x = x;
    object[0].position.y = y;
    sfSprite_setPosition(object[0].sprite, object[0].position);
}

static void equip_weapon(game_t *game, sfVector2i pos)
{
    if (pos.x < 69 && pos.x > 37 && pos.y < 922 && pos.y > 890
    && (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)) {
        if (game->player.weapon == 2)
            game->player.weapon = 1;
        else
            game->player.weapon = 2;
    }
    if (game->player.weapon == 2)
        display_sprite(game->window, game->objects[SPEAR]);
    else
        display_sprite(game->window, game->objects[SWORD]);
}

static void equip_armor(game_t *game, sfVector2i pos)
{
    if (pos.x < 112 && pos.x > 80 && pos.y < 922 && pos.y > 890
    && (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)) {
        if (game->player.armor == 2)
            game->player.armor = 1;
        else
            game->player.armor = 2;
    }
    if (game->player.armor == 2)
        display_sprite(game->window, game->objects[ARMOR_1]);
    else
        display_sprite(game->window, game->objects[ARMOR_2]);
}

void set_inventory(game_t *game)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);

    set_pos(5.0, 850.0, game->objects[INVENTORY_]);
    display_sprite(game->window, game->objects[INVENTORY_]);
    set_pos(37, 890, game->objects[SPEAR]);
    set_pos(37, 890, game->objects[SWORD]);
    set_pos(80, 890, game->objects[ARMOR_1]);
    set_pos(80, 890, game->objects[ARMOR_2]);
    set_pos(105.0, 875.0, game->objects[POTION]);
    equip_weapon(game, pos);
    equip_armor(game, pos);
    display_sprite(game->window, game->objects[POTION]);
}
