/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_menu_pause
*/

#include "textures.h"
#include "game.h"
#include "particule.h"

void display_menu_pause(sfRenderWindow *window, button_display_t *buttons,
    object_t back_ground, game_t *game)
{
    sfRenderWindow_drawSprite(window, back_ground.sprite, NULL);
    for (unsigned int i = P_RESUME; i <= P_QUIT; i++) {
        sfRenderWindow_drawRectangleShape(window,
        buttons[i].shape, NULL);
        sfRenderWindow_drawText(window, buttons[i].text, NULL);
    }
    rain(game->fight.part, game, (color_t) {sfBlack, sfBlack});
}