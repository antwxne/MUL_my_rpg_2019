/*
** EPITECH PROJECT, 2020
** rectangle
** File description:
** rectangle
*/

#include <stdlib.h>
#include "game.h"
#include "dialogue.h"
#include "fight.h"

static const sfVector2f place [] = {
    {400, 300},
    {700, 500},
};
static const sfVector2f sizes [] = {
    {200, 50},
    {500, 300},
};

static const sfColor color_out [] = {
    {20, 20, 20, 100},
    {199, 207, 0, 100},
};

static const sfColor color_fil [] = {
    {20, 20, 20, 90},
    {199, 207, 0, 90},
};

static const int nbr_rect = 2;

static const int nbr_text = 5;

sfVector2f position_xy(int x, int y)
{
    sfVector2f position;

    position.x = x;
    position.y = y;
    return position;
}

static void init_text(dialogue_t *dialogue, char *texte)
{
    dialogue->police = sfFont_createFromFile("assets/font_medieval.ttf");
    dialogue->texte = sfText_create();
    sfText_setFont(dialogue->texte, dialogue->police);
    sfText_setColor(dialogue->texte, sfWhite);
    sfText_setPosition(dialogue->texte, (position_xy(400, 300)));
    sfText_setString(dialogue->texte, texte);
}

static void fill(dialogue_t *dialogue)
{
    dialogue->dia[0] = "Click here\nLALALA";
    dialogue->dia[1] = "ALED, je suis en danger !!!";
    dialogue->dia[2] = "aider moi je vous en prie !!!";
    dialogue->dia[3] = "une récompense vous severez !!";
    dialogue->dia[4] = "ACCEPTEZ LA QUÊTE!";
}

int rectangle(dialogue_t *dialogue)
{
    dialogue->dia_rects = malloc(sizeof(sfRectangleShape *) * nbr_rect);
    if (dialogue->dia_rects == NULL)
        return -1;
    for (int i = 0; i != nbr_rect; i++)
        dialogue->dia_rects[i] = create_fight_rect_shape(place[i], sizes[i],
        color_out[i], color_fil[i]);
    dialogue->dia = malloc(sizeof(char *) * nbr_text);
    fill(dialogue);
    init_text(dialogue, dialogue->dia[0]);
    return 0;
}
