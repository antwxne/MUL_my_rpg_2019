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

void god_moding(rectangle_t *rects, int ennemies, sfRenderWindow *window,
                object_t **objects)
{
    rects->life_ennemie[ennemies] -= rects->life_ennemie[ennemies];
    sfRectangleShape_setSize(rects->fight_rects[3],
                            (sfVector2f) {rects->life_ennemie[ennemies], 100});
    sfRenderWindow_drawRectangleShape(window, rects->fight_rects[8], NULL);
    sfRenderWindow_drawSprite(window, objects[VICTORY][0].sprite, NULL);

}
