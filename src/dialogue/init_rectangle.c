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

static const int nbr_text = 6;

sfVector2f position_xy(int x, int y)
{
    sfVector2f position;

    position.x = x;
    position.y = y;
    return position;
}

static void init_text(dialogue_t *dialogue)
{
    dialogue->police = sfFont_createFromFile("assets/font_medieval.ttf");
    dialogue->texte = sfText_create();
    sfText_setFont(dialogue->texte, dialogue->police);
    sfText_setColor(dialogue->texte, sfRed);
}

static void fill(dialogue_t *dialogue)
{
    dialogue->dia[HTP][0] = "Press E pour allez a la slide suivante";
    dialogue->dia[HTP][1] = "Bienvenue dans le monde fantasique de MOLETTE";
    dialogue->dia[HTP][2] = "les commandes sont a savoir : ";
    dialogue->dia[HTP][3] = "G pour le God mode (combat), et Echap pour le menu";
    dialogue->dia[HTP][4] = "Il faut cliquer sur les pnjs pour lancer des quetes";
    dialogue->dia[HTP][5] = "et aussi faire des combats , ducous Bon jeux";
    dialogue->dia[PNJ_FIRST][0] = "j ai une quete pour toi !!!";
    dialogue->dia[PNJ_FIRST][1] = "aled je suis en danger !!!";
    dialogue->dia[PNJ_FIRST][2] = "aider moi je vous en prie !!!";
    dialogue->dia[PNJ_FIRST][3] = "une récompense vous severez !!";
    dialogue->dia[PNJ_FIRST][4] = "vous devez tuez l ennemie patate";
    dialogue->dia[PNJ_FIRST][5] = "acceptez la quete!";
    dialogue->dia[PNJ_SECOND][0] = "ZIZI";
    dialogue->dia[PNJ_SECOND][1] = "LOL";
}

int rectangle(dialogue_t *dialogue)
{
    dialogue->dia_rects = malloc(sizeof(sfRectangleShape *) * nbr_rect);
    if (dialogue->dia_rects == NULL)
        return -1;
    for (int i = 0; i != nbr_rect; i++)
        dialogue->dia_rects[i] = create_fight_rect_shape(place[i], sizes[i],
        color_out[i], color_fil[i]);
    dialogue->dia = malloc(sizeof(char **) * nbr_text);
    if (dialogue->dia == NULL)
        return 84;
    for (int i = 0; i < nbr_text; i++) {
        dialogue->dia[i] = malloc(sizeof(char *) * (nbr_text + 1));
        if (dialogue->dia == NULL)
            return 84;
    }
    fill(dialogue);
    init_text(dialogue);
    return 0;
}
