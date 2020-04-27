/*
** EPITECH PROJECT, 2020
** god
** File description:
** mode
*/

#include <stdlib.h>
#include "main.h"
#include "game.h"
#include "textures.h"
#include "fight.h"

void get_echap(game_t *png, rectangle_t *rects)
{
    static int a = 0;
    int status = 0;

    if (sfKeyboard_isKeyPressed(sfKeyG) == sfTrue)
        a = 1;
    if ((png->event.type == sfEvtKeyReleased) && (a == 1) &&
        (rects->god == true) && (status == 0)) {
        rects->god = false;
        a = 0;
        status = 1;
    }
}