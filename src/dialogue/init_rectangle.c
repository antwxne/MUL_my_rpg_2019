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
    {500, 100},
};

static const sfColor color_out [] = {
    {20, 20, 20, 100},
    {250, 250, 0, 255},
};

static const sfColor color_fil [] = {
    {20, 20, 20, 90},
    {230, 230, 0, 255},
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
    dialogue->police = sfFont_createFromFile("assets/quanto.ttf");
    dialogue->texte = sfText_create();
    sfText_setFont(dialogue->texte, dialogue->police);
    sfText_setColor(dialogue->texte, sfRed);
}

static void fill(dialogue_t *dialogue)
{
    dialogue->dia[HTP][0] = "Welcome, press E to go to the next slide";
    dialogue->dia[HTP][1] = "Welcome to the fantastic world of Maulette";
    dialogue->dia[HTP][2] = "The game keys are :";
    dialogue->dia[0][3] = "G for the God mode (fight), and Esc for the menu";
    dialogue->dia[0][4] = "you've click on the pnj to launch quest or fight";
    dialogue->dia[HTP][5] = "you can equip yourself with stuff, Good Game";
    dialogue->dia[HTP][6] = NULL;
    dialogue->dia[PNJ_FIRST][0] = "Hello, I have a quest fort you";
    dialogue->dia[PNJ_FIRST][1] = "Help me please\nA wizard want to kill me";
    dialogue->dia[PNJ_FIRST][2] = "You will receive my eternal gratitude";
    dialogue->dia[PNJ_FIRST][3] = "Can you kill the first wizard please !";
    dialogue->dia[PNJ_FIRST][4] = "He is at the end of the path";
    dialogue->dia[PNJ_FIRST][5] = "Accept quest\nPlease !";
    dialogue->dia[PNJ_FIRST][6] = NULL;
}
static void fill2(dialogue_t *dialogue)
{
    dialogue->dia[PNJ_SECOND][0] = "Thanks\nBut i have yet another request";
    dialogue->dia[2][1] = "Another wizard want my death";
    dialogue->dia[2][2] = "he belongs to the same group as\nthe other wizard";
    dialogue->dia[2][3] = "Care he is stronger thant the other !";
    dialogue->dia[2][4] = "It can also turn into a ferocious beast";
    dialogue->dia[2][5] = "Accept quest \nPlease !";
    dialogue->dia[2][6] = NULL;
    dialogue->dia[3][0] = "The last time and after it's over";
    dialogue->dia[3][1] = "The group leader also wants to kill me";
    dialogue->dia[3][2] = "He has the same powers as them";
    dialogue->dia[3][3] = "It's the last person who wants to kill me";
    dialogue->dia[3][4] = "Kill him\nAnd I won't ask you anything anymore";
    dialogue->dia[3][5] = "Accept quest\n and I will say thank you!";
    dialogue->dia[3][6] = NULL;
    dialogue->dia[4][0] = "Thanks a lot.";
    dialogue->dia[4][1] = "you've just finish the game";
    dialogue->dia[4][2] = NULL;
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
