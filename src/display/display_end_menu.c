/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_end_menu
*/

#include "textures.h"
#include "game.h"
#include "particule.h"
#include "button.h"

void display_menu_end(sfRenderWindow *window,
    button_display_t *buttons, object_t back_ground[], game_t *game)
{

    sfRenderWindow_drawSprite(window,
        back_ground[game->view == END_WIN ? 1 : 0].sprite, NULL);
    for (unsigned int i = D_RESTART; i <= D_QUIT; i++) {
        sfRenderWindow_drawRectangleShape(window,
        buttons[i].shape, NULL);
        sfRenderWindow_drawText(window, buttons[i].text, NULL);
    }
    rain(game->fight.part, game,  game->view == END_WIN ?\
    (color_t) {sfYellow, sfYellow} : (color_t) {sfRed, sfRed});
}