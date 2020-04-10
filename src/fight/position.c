/*
** EPITECH PROJECT, 2020
** position
** File description:
** ennemie
*/

#include <stdlib.h>
#include "main.h"
#include "game.h"
#include "textures.h"
#include "fight.h"

static const sfIntRect rect[] = {{500, 400, 250, 250},
                                 {850, 400, 250, 250},
                                 {1200, 400, 250, 250},
};

void get_mainposition(sfSprite *sprite, int x, int y)
{
    sfVector2f position;

    position = sfSprite_getPosition(sprite);
    position.x = x;
    position.y = y;
    sfSprite_setPosition(sprite, position);
}

sfRectangleShape *create_fight_rect_shape(sfVector2f pos, sfVector2f size,
sfColor color_outline, sfColor color_fill)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setOrigin(shape, (sfVector2f) {0, 0});
    sfRectangleShape_setPosition(shape, pos);
    sfRectangleShape_setSize(shape, size);
    sfRectangleShape_setOutlineColor(shape, color_outline);
    sfRectangleShape_setFillColor(shape, color_fill);
    sfRectangleShape_setOutlineThickness(shape, 7);
    return (shape);
}

static void touch(rectangle_t *rec, sfRenderWindow *window)
{
    sfVector2i posi = sfMouse_getPositionRenderWindow(fenetre->window);

    if (sfIntRect_contains(&rect[0], posi.x, posi.y) == sfTrue)
        sfRectangleShape_setScale(rec->fight_rects[0], (sfVector2f) {1.1, 1.1});
    else
        sfRectangleShape_setScale(rec->fight_rects[0], (sfVector2f) {1, 1});
    if (sfIntRect_contains(&rect[1], posi.x, posi.y) == sfTrue)
        sfRectangleShape_setScale(rec->fight_rects[1], (sfVector2f) {1.1, 1.1});
    else
        sfRectangleShape_setScale(rec->fight_rects[1], (sfVector2f) {1, 1});
    if (sfIntRect_contains(&rect[2], posi.x, posi.y) == sfTrue)
        sfRectangleShape_setScale(rec->fight_rects[2], (sfVector2f) {1.1, 1.1});
    else
        sfRectangleShape_setScale(rec->fight_rects[2], (sfVector2f) {1, 1});
}

int init_rectangle(rectangle_t *rects)
{
    rects->fight_rects = malloc(sizeof(sfRectangleShape *) * 4);
    if (rects->fight_rects == NULL)
        return 84;
    rects->fight_rects[0] = create_fight_rect_shape((sfVector2f) {500, 400},
    (sfVector2f) {250, 250}, (sfColor) {255, 0, 0, 100},
    (sfColor) {255, 0, 0, 80} );
    rects->fight_rects[1] = create_fight_rect_shape((sfVector2f) {850, 400},
    (sfVector2f) {250, 250}, (sfColor) {53, 76, 231, 100},
    (sfColor) {53, 76, 231, 80});
    rects->fight_rects[2] = create_fight_rect_shape((sfVector2f) {1200, 400},
    (sfVector2f) {250, 250}, (sfColor) {53, 237, 130, 100},
    (sfColor) {53, 237, 130, 80});
    rects->fight_rects[3] = create_fight_rect_shape((sfVector2f) {1500, 100},
    (sfVector2f) {400,100}, (sfColor) {53, 237, 130, 100},
    (sfColor) {53, 237, 130, 80});
    return 0;
}

int try(game_t *png, rectangle_t *rects)
{
    get_mainposition(png->objects[PLAYER][MARIO].sprite, 800, 800);
    touch(rects, png->);
    sfRenderWindow_drawRectangleShape(png->window, rects->fight_rects[0], NULL);
    sfRenderWindow_drawRectangleShape(png->window, rects->fight_rects[1], NULL);
    sfRenderWindow_drawRectangleShape(png->window, rects->fight_rects[2], NULL);
    sfRenderWindow_drawRectangleShape(png->window, rects->fight_rects[3], NULL);
    return 0;
}
