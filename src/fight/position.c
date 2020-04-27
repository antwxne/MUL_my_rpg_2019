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

static const sfVector2f place[] = {
    {500, 400},
    {850, 400},
    {1200, 400},
    {1500, 100},
    {850, 100},
    {200, 200},
    {1500, 800},
    {850, 100},
    {850, 100},
};

static const sfVector2f sizes[] = {
    {250, 250},
    {250, 250},
    {250, 250},
    {400, 100},
    {150, 150},
    {50, 50},
    {400, 100},
    {150, 150},
    {150, 150},
};

static const sfColor color_out[] = {
    {255, 0, 0, 100},
    {53, 76, 231, 100},
    {53, 237, 130, 100},
    {53, 237, 130, 100},
    {53, 100, 189, 100},
    {53, 150, 9, 100},
    {90, 100, 150, 100},
    {90, 100, 150, 100},
    {100, 100, 100, 100},
};

static const sfColor color_fil[] = {
    {255, 0, 0, 80},
    {53, 76, 231, 80},
    {53, 237, 130, 80},
    {53, 237, 130, 80},
    {53, 100, 189, 100},
    {53, 20, 9, 80},
    {90, 100, 150, 80},
    {90, 100, 150, 80},
    {100, 100, 100, 80},
};

static const int nb_rect = 9;

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

void change_color(rectangle_t *rects)
{
    for (int i = 0; i < 3; i++) {
        sfRectangleShape_setOutlineColor(rects->fight_rects[i], color_out[i]);
        sfRectangleShape_setFillColor(rects->fight_rects[i], color_fil[i]);
    }
}

int init_rectangle(rectangle_t *rects)
{
    rects->fight_rects = malloc(sizeof(sfRectangleShape *) * nb_rect);
    if (rects->fight_rects == NULL)
        return -1;
    for (int i = 0; i != nb_rect; i++)
        rects->fight_rects[i] = create_fight_rect_shape(place[i], sizes[i],
                                color_out[i], color_fil[i]);
    return 0;
}

int try(game_t *png, rectangle_t *rects)
{
    int status = get_status(rects, png->event, png->window);

    get_mainposition(png->objects[PLAYER][MARIO].sprite, 800, 800);
    touch(rects, png);
    if (rects->etat == false) {
        life_time(rects);
        battle_prin(rects, png->window);
    }
    state_effect(rects, status);
    if (rects->etat == true)
        change_color(rects);
    for (int i = 0; i <= 3; i++)
    sfRenderWindow_drawRectangleShape(png->window, rects->fight_rects[i], NULL);
    sfRenderWindow_drawRectangleShape(png->window, rects->fight_rects[6], NULL);
    get_echap(png, rects);

    if (rects->god == false)
        sfRenderWindow_drawRectangleShape(png->window,
        rects->fight_rects[5], NULL);
    return 0;
}
