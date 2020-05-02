/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_map
*/

#include "textures.h"
#include "game.h"
#include "inventory.h"
<<<<<<< HEAD
#include "dialogue.h"
=======
#include "hud.h"
>>>>>>> hud

void display_sprite(sfRenderWindow *window, object_t *obj)
{
    for (unsigned int i = 0; i < number_objects; i++)
        if (obj[i].position.x > -100 && obj[i].position.x < window_size_x + 100
        && obj[i].position.y > -100
        && obj[i].position.y < window_size_y + 100)
            sfRenderWindow_drawSprite(window, obj[i].sprite, NULL);
}

static void display_dialogue(game_t *game, dialogue_t *dialogue)
{
    if (game->view == DIALOGUE) {
        sfRenderWindow_drawRectangleShape(game->window,
        dialogue->dia_rects[1], NULL);
        sfRenderWindow_drawText(game->window, dialogue->texte, NULL);
    }
}

void display_map(game_t *game, int map, sfRectangleShape *shape)
{
    if (map == 0)
        sfRenderWindow_drawSprite(game->window,
        game->objects[FIRST_MAP][0].sprite, NULL);
    if (map > 0)
        sfRenderWindow_drawSprite(game->window,
        game->objects[SECOND_MAP][0].sprite, NULL);
    sfRenderWindow_drawRectangleShape(game->window, shape, NULL);
    display_sprite(game->window, game->objects[PLAYER]);
    display_sprite(game->window, game->objects[PNJ_1]);
    display_sprite(game->window, game->objects[HOUSE]);
    display_sprite(game->window, game->objects[HOUSE_2]);
    display_sprite(game->window, game->objects[ENNEMI_1]);
    display_sprite(game->window, game->objects[ENNEMI_2]);
    display_sprite(game->window, game->objects[ENNEMI_3]);
    set_inventory(game);
<<<<<<< HEAD
    display_dialogue(game, &game->dialogue);
=======
    apply_stats(game->player.stat_txt, game);
>>>>>>> hud
}
