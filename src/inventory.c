/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inventory
*/

#include "inventory.h"
#include "textures.h"

static void display_sprite(sfRenderWindow *window, object_t *obj)
{
    for (unsigned int i = 0; i < number_objects; i++)
        if (obj[i].position.x > -100 && obj[i].position.x < window_size_x + 100
        && obj[i].position.y > -100 && obj[i].position.y < window_size_y + 100)
            sfRenderWindow_drawSprite(window, obj[i].sprite, NULL);
}

static void set_pos(float x, float y, object_t *object)
{
    object[0].position.x = x;
    object[0].position.y = y;
    sfSprite_setPosition(object[0].sprite, object[0].position);
}

void set_inventory(sfRenderWindow *window, object_t **objects, sfEvent event)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);

    set_pos(5.0, 850.0, objects[INVENTORY_]);
    if (pos.x < 69 && pos.x > 37 && pos.y < 922 && pos.y > 890)
        set_pos(37.0, 890.0, objects[SPEAR]);
    else
        set_pos(37.0, 890.0, objects[SWORD]);
    if (pos.x < 112 && pos.x > 80 && pos.y < 922 && pos.y > 890)
        set_pos(80.0, 890.0, objects[ARMOR_1]);
    else
        set_pos(80.0, 890.0, objects[ARMOR_2]);
    set_pos(105.0, 875.0, objects[POTION]);
    display_sprite(window, objects[INVENTORY_]);
    if (pos.x < 69 && pos.x > 37 && pos.y < 922 && pos.y > 890)
        display_sprite(window, objects[SPEAR]);
    else
        display_sprite(window, objects[SWORD]);
    if (pos.x < 112 && pos.x > 80 && pos.y < 922 && pos.y > 890)
        display_sprite(window, objects[ARMOR_1]);
    else
        display_sprite(window, objects[ARMOR_2]);
    display_sprite(window, objects[POTION]);
}
