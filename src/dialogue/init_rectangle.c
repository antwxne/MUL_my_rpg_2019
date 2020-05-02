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
    {400, 200},
    {700, 500},
};
static const sfVector2f sizes [] = {
    {850, 50},
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
    dialogue->dia[0][3] = "G pour le God mode (combat), et Echap pour le menu";
    dialogue->dia[0][4] = "Il faut cliquer sur les pnjs pour lancer des quetes";
    dialogue->dia[HTP][5] = "et aussi faire des combats , ducous Bon jeux";
    dialogue->dia[HTP][6] = NULL;
    dialogue->dia[PNJ_FIRST][0] = "j ai une quete pour toi";
    dialogue->dia[PNJ_FIRST][1] = "aider moi je vous en prie !!!";
    dialogue->dia[PNJ_FIRST][2] = "une récompense vous severez !";
    dialogue->dia[PNJ_FIRST][3] = "vous devez tuez l ennemie patate";
    dialogue->dia[PNJ_FIRST][4] = "il se trouve en haut du chemin!";
    dialogue->dia[PNJ_FIRST][5] = "acceptez la quete!";
    dialogue->dia[PNJ_FIRST][6] = NULL;
}
static void fill2(dialogue_t *dialogue)
{
    dialogue->dia[PNJ_SECOND][0] = "encore une quete...";
    dialogue->dia[PNJ_SECOND][1] = "une autre personne veut ma mort";
    dialogue->dia[2][2] = "un sorcier puissant qui peut ce transformer";
    dialogue->dia[2][3] = "comme le précédent, ils sont maléfiques";
    dialogue->dia[PNJ_SECOND][4] = "ducous accepte encore la quete";
    dialogue->dia[PNJ_SECOND][5] = NULL;
    dialogue->dia[3][0] = "derniere fois et apres c est fini";
    dialogue->dia[3][1] = "la derniere personne a tuer c est : ";
    dialogue->dia[3][2] = "une personne horrible et mechante";
    dialogue->dia[3][3] = "le plus féroce des sorciers transformeurs";
    dialogue->dia[3][4] = "tuez le !!!!";
    dialogue->dia[3][5] = "le monde vous dira merci!";
    dialogue->dia[3][6] = NULL;
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
        dialogue->dia[i] = malloc(sizeof(char *) * (6 + 1));
        if (dialogue->dia == NULL)
            return 84;
    }
    fill(dialogue);
    fill2(dialogue);
    init_text(dialogue);
    return 0;
}
