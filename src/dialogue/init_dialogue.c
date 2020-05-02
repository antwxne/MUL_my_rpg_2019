/*
** EPITECH PROJECT, 2020
** dialogue
** File description:
** dialogue
*/

#include "game.h"
#include "dialogue.h"

static const sfIntRect rect[] = {
    {400, 300, 200, 50}
};

int wait_press_e(game_t *game)
{
    static int a = 0;

    if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue)
        a = 1;
    else if ((game->event.type == sfEvtKeyReleased) && (a == 1)) {
        a = 0;
        return 1;
    }
    return 0;
}

static sfVector2f posi_xy(int x, int y)
{
    sfVector2f position;

    position.x = x;
    position.y = y;
    return position;
}

void pos_dia(int x , int y, dialogue_t *dialogue, char *texte)
{
    sfText_setPosition(dialogue->texte, (posi_xy(x, y)));
    sfText_setString(dialogue->texte, texte);
}

int main_dialogue(dialogue_t *dialogue, game_t *game, int types)
{
    static int i = 0;
    static int step = 0;

    step += wait_press_e(game);
    if (dialogue->dia[types][step] == NULL) {
        i = 0;
        step = 0;
        return 1;
    }
    pos_dia(700, 600, dialogue, dialogue->dia[types][step]);
    return 0;
}
