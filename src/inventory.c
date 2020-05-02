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
    static int status = 0;

    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        status = 1;
    else if (game->event.type == sfEvtMouseButtonReleased && status == 1) {
        status = 0;
        if (is_the_mouse_in_x(pos, 37, 69) == 1
        && is_the_mouse_in_y(pos, 890, 922) == 1) {
            if (game->player.weapon == 1) {
                game->player.weapon = 2;
                game->player.stat[2] += 20;
            } else {
                game->player.weapon = 1;
                game->player.stat[2] -= 20;
            }
        }
    }
    display_sprite(game->window,
                    game->objects[(game->player.weapon == 2) ? SPEAR : SWORD]);
}

static void equip_armor(game_t *game, sfVector2i pos)
{
    static int status = 0;

    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        status = 1;
    else if (game->event.type == sfEvtMouseButtonReleased && status == 1) {
        status = 0;
        if (is_the_mouse_in_x(pos, 80, 112) == 1
        && is_the_mouse_in_y(pos, 890, 922) == 1) {
            change_armor(game);
        }
    }
    display_sprite(game->window,
                game->objects[(game->player.armor == 2) ? ARMOR_1 : ARMOR_2]);
}

static void heal(game_t *game, sfVector2i pos)
{
    if (pos.x < 137 && pos.x > 105 && pos.y < 907 && pos.y > 875
    && (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue))
        game->player.stat[0] = game->player.max_health;
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
    heal(game, pos);
    display_sprite(game->window, game->objects[POTION]);
}
