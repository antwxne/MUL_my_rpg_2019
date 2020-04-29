/*
** EPITECH PROJECT, 2020
** key
** File description:
** press
*/

#include "game.h"
#include "fight.h"

static const sfIntRect rect[] = {
    {500, 710, 250, 250},
    {850, 710, 250, 250},
    {1200, 710, 250, 250},
};

void touch(rectangle_t *rec, game_t *game)
{
    sfVector2i posi = sfMouse_getPositionRenderWindow(game->window);

    for (int i = 0; i < 3; i++)
        if (sfIntRect_contains(&rect[i], posi.x, posi.y) == sfTrue)
            sfRectangleShape_setScale(rec->fight_rects[i],
            (sfVector2f) {1.1, 1.1});
        else
            sfRectangleShape_setScale(rec->fight_rects[i], (sfVector2f) {1, 1});
}

int get_status(rectangle_t *rec, sfEvent event, sfRenderWindow *window)
{
    static int status = 0;
    sfVector2i posi = sfMouse_getPositionRenderWindow(window);

    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && rec->etat == true) {
        status = 1;
    }
    if (event.type == sfEvtMouseButtonReleased && status == 1) {
        status = 0;
        for (int i = 0; i < 3; i++)
            if (sfIntRect_contains(&rect[i], posi.x, posi.y) == sfTrue) {
                sfRectangleShape_setFillColor(rec->fight_rects[i], sfBlue);
                sfClock_restart(rec->life_clock);
                rec->etat = false;
                rec->consequence = false;
                return i;
            }
    }
    return -1;
}
