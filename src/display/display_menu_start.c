/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_menu_start
*/

#include "textures.h"
#include "game.h"
#include "dialogue.h"
#include "particule.h"

void display_menu_start(sfRenderWindow *window, button_display_t *buttons,
    object_t back_ground, game_t *game)
{
    sfRenderWindow_drawSprite(window, back_ground.sprite, NULL);
    for (unsigned int i = S_START; i <= S_QUIT; i++) {
        sfRenderWindow_drawRectangleShape(window,
        buttons[i].shape, NULL);
        sfRenderWindow_drawText(window, buttons[i].text, NULL);
        how_to_play(&game->dialogue, game);
    }
    rain(game->fight.part, game, (color_t) {sfWhite, sfWhite});
}
