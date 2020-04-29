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
    {500, 710},
    {850, 710},
    {1200, 710},
    {1500, 100},
    {800, 450},
    {200, 200},
    {1500, 800},
    {800, 450},
    {800, 450},
};

static const sfVector2f sizes[] = {
    {250, 250},
    {250, 250},
    {250, 250},
    {400, 100},
    {300, 150},
    {50, 50},
    {400, 100},
    {300, 150},
    {300, 150},
};

static const sfColor color_out[] = {
    {255, 0, 0, 100},
    {53, 76, 231, 100},
    {53, 237, 130, 100},
    {53, 237, 130, 100},
    {180, 180, 189, 100},
    {53, 150, 9, 100},
    {90, 100, 150, 100},
    {200, 100, 150, 100},
    {230, 200, 200, 100 },
};

static const sfColor color_fil[] = {
    {255, 0, 0, 80},
    {53, 76, 231, 80},
    {53, 237, 130, 80},
    {53, 237, 130, 80},
    {180, 180, 189, 100},
    {53, 20, 9, 80},
    {90, 100, 150, 80},
    {100, 250, 150, 80},
    {200, 100, 100, 80},
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

void set_position(int x, int y, sfSprite *sprite)
{
    sfVector2f position = sfSprite_getPosition(sprite);
    position.x = x;
    position.y = y;
    sfSprite_setPosition(sprite, position);

}

int try(game_t *png, rectangle_t *rects, int name_ennemies, int ennemies_damage)
{
    int status = get_status(rects, png->event, png->window);

    position_sprite(png);
    sfRenderWindow_drawSprite(png->window, png->objects[PEGY][0].sprite, NULL);
    touch(rects, png);
    sfRenderWindow_drawSprite(png->window, png->objects[EN_1][0].sprite, NULL);
    if (rects->etat == false) {
        life_time(rects);
        battle_prin(rects, png->window, png->objects);
    }
    state_effect(rects, status, name_ennemies, ennemies_damage);
    if (rects->etat == true)
        change_color(rects);
    for (int i = 0; i <= 3; i++)
    sfRenderWindow_drawRectangleShape(png->window, rects->fight_rects[i], NULL);
    sfRenderWindow_drawRectangleShape(png->window, rects->fight_rects[6], NULL);
    sfRenderWindow_drawSprite(png->window, png->objects[ROCK][0].sprite, NULL);
    sfRenderWindow_drawSprite(png->window, png->objects[PAPYRUS][0].sprite, NULL);
    sfRenderWindow_drawSprite(png->window, png->objects[CUTER][0].sprite, NULL);
    get_echap(png, rects);
    if (rects->god == false)
        sfRenderWindow_drawRectangleShape(png->window,
        rects->fight_rects[5], NULL);
    return 0;
}
