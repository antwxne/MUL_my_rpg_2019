/*
** EPITECH PROJECT, 2020
** dialogue
** File description:
** dialogue
*/

#include "game.h"
#include "dialogue.h"

static const sfIntRect rect[] = {
    {400, 300, 100, 100}
};

static int wait_click(game_t *game)
{
    static int status = 0;
    sfVector2i posi = sfMouse_getPositionRenderWindow(game->window);

    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        status = 1;
    if (game->event.type == sfEvtMouseButtonReleased && status == 1) {
          if (sfIntRect_contains(&rect[0], posi.x, posi.y) == sfTrue) {
              return 1;
        }
    }
    return 0;
}

static int wait_press_e(game_t *game)
{
    static int a = 0;

    if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue)
        a = 1;
    else if((game->event.type == sfEvtKeyReleased) && (a == 1)) {
        a = 0;
        return 1;
    }
    return 0;
}

static sfVector2f posi_xy(int x, int y)
{
    sfVector2f position;
    
    position.x = x;
    position.y = y;
    return position;
}

static void pos_dia(int x , int y, dialogue_t *dialogue, char *texte)
{
    sfText_setPosition(dialogue->texte, (posi_xy(x, y)));
    sfText_setString(dialogue->texte, texte);
}

void main_dialogue(dialogue_t *dialogue, game_t *game)
{
    static int i = 0;
    static int step = 1;

    i += wait_click(game);
 
    if (i >= 1) {
        step += wait_press_e(game);
        printf("stape = %d\n", step);
        if (dialogue->dia[0][step] == NULL)
            exit(1);
        sfRenderWindow_drawRectangleShape(game->window, dialogue->dia_rects[1], NULL);
        pos_dia(700, 600, dialogue, dialogue->dia[0][step]);
        sfRenderWindow_drawText(game->window, dialogue->texte, NULL);   
    }
    else if (i == 0) {
        sfRenderWindow_drawRectangleShape(game->window, dialogue->dia_rects[0], NULL);
        sfRenderWindow_drawText(game->window, dialogue->texte, NULL);   
    }
}
