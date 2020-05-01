/*
** EPITECH PROJECT, 2020
** how to
** File description:
** play
*/

#include "dialogue.h"
#include "game.h"

int how_to_play(dialogue_t *dialogue, game_t *game)
{
    static int step = 0;
    
    step += wait_press_e(game);
    if (dialogue->dia[0][step] == NULL) {
        step = 0;
        return 1;
    }
    pos_dia(400, 200, dialogue, dialogue->dia[0][step]);
    sfRenderWindow_drawText(game->window, dialogue->texte, NULL);
    return 0;
}
