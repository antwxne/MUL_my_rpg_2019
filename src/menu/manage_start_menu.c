/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** manage_start_menu
*/

#include "game.h"
#include "main.h"
#include "start_menu.h"

static const sfColor transparent_grey = {255, 255, 255, 60};

static void change_action(game_t *game, int action)
{
    if (action == S_START)
        game->view = MAP;
    if (action == S_QUIT)
        sfRenderWindow_close(game->window);
    // if (action == S_HTP)
    //     display how to play
}

static void overlay_button(button_display_t *ptr_button, game_t *game,
    int action)
{
    static bool clic = false;

    sfRectangleShape_setOutlineColor(ptr_button->shape, sfRed);
    if (game->event.type == sfEvtMouseButtonPressed) {
        clic = true;
        sfRectangleShape_setFillColor(ptr_button->shape, transparent_grey);
    }
    if (game->event.type == sfEvtMouseButtonReleased && clic == true)
        change_action(game, action);
}

static void reset_overlay(button_display_t *ptr_button)
{
    sfRectangleShape_setOutlineColor(ptr_button->shape, sfTransparent);
    sfRectangleShape_setFillColor(ptr_button->shape, sfTransparent);
}

void manage_start_menu(game_t *game)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);

    for (unsigned int i = S_START; i <= S_QUIT; i++) {
        if (sfIntRect_contains(&game->buttons[i].rect,
            pos.x, pos.y))
            overlay_button(&game->buttons[i], game, i);
        else
            reset_overlay(&game->buttons[i]);
    }
}