/*
** EPITECH PROJECT, 2020
** how to
** File description:
** play
*/

#include "dialogue.h"
#include "game.h"

static const sfIntRect rect[] = {
    {800, 584, 300, 60},
};

static int wait_htp(game_t *game)
{
    static int status = 0;
    sfVector2i posi = sfMouse_getPositionRenderWindow(game->window);

    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        status = 1;
    if (game->event.type == sfEvtMouseButtonReleased && status == 1) {
        if (sfIntRect_contains(&rect[0], posi.x, posi.y) == sfTrue) {
            return 1;
        }
    }
    return 0;
}

int how_to_play(dialogue_t *dialogue, game_t *game)
{
    static int step = 0;
    static int i = 0;

    i += wait_htp(game);
    if ( i > 0) {
        step += wait_press_e(game);
        if (dialogue->dia[0][step] == NULL) {
            i = 0;
            step = 0;
            return 1;
        }
        sfRenderWindow_drawRectangleShape(game->window,
        dialogue->dia_rects[0], NULL);
        pos_dia(400, 200, dialogue, dialogue->dia[0][step]);
        sfRenderWindow_drawText(game->window, dialogue->texte, NULL);
    }
    return 0;
}
