/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** color_cursor
*/

#include <stdlib.h>
#include "game.h"
#include "main.h"

static void change_color_cursor(sfClock **clock, object_t *cursor)
{
    sfTime time;
    float seconds;
    sfUint8 r = rand() % 255;
    sfUint8 g = rand() % 255;
    sfUint8 b = rand() % 255;

    time = sfClock_getElapsedTime(*clock);
    seconds = time.microseconds / 100000.0;
    if (seconds > 5) {
        sfSprite_setColor(cursor->sprite, (sfColor) {r, g, b, 255});
        sfClock_restart(*clock);
    }
}

void manage_cursor(sfRenderWindow *window, sfClock **clock,
    object_t *cursor, sfEvent event)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    if (event.type == sfEvtMouseButtonPressed)
        change_color_cursor(clock, cursor);
    if (event.type == sfEvtMouseButtonReleased)
        sfSprite_setColor(cursor->sprite, sfWhite);
    sfSprite_setPosition(cursor->sprite,
    (sfVector2f) {(float) mouse_pos.x, (float) mouse_pos.y});
    sfRenderWindow_drawSprite(window, cursor->sprite, NULL);
}