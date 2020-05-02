/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** hud
*/

#include "game.h"
#include "my.h"

static void set_font_to_all(sfText **texts, sfFont *font, int nb_texts)
{
    for (int i = 0; i != nb_texts; i++)
        sfText_setFont(texts[i], font);
}

static void set_position_to_all(sfText **texts, int nb_texts)
{
    sfVector2f position = {5, 780};

    for (int i = 0; i != nb_texts; i++) {
        sfText_setPosition(texts[i], position);
        position.y += 10;
    }
}

static void set_char_size_to_all(sfText **texts, int nb_texts)
{
    for (int i = 0; i != nb_texts; i++)
        sfText_setCharacterSize(texts[i], 10);
}

void apply_stats(sfText **stats, game_t *game)
{
    sfText_setString(stats[0], my_strcat("health : ",
                        my_itoa(game->player.stat[HEALTH])));
    sfText_setString(stats[1], my_strcat("attack : ",
                        my_itoa(game->player.stat[ATK_PLAYER])));
    sfText_setString(stats[2], my_strcat("defense : ",
                        my_itoa(game->player.stat[DEF_PLAYER])));
    sfRenderWindow_drawText(game->window, stats[0], NULL);
    sfRenderWindow_drawText(game->window, stats[0], NULL);
    sfRenderWindow_drawText(game->window, stats[3], NULL);
}

int create_hud(game_t *game)
{
    sfText *health = sfText_create();
    sfText *attack = sfText_create();
    sfText *defense = sfText_create();
    game->player.stat_txt[0] = health;
    game->player.stat_txt[1] = attack;
    game->player.stat_txt[2] = defense;
    sfFont *font = sfFont_createFromFile("assets/font_medieval.ttf");

    if (!health || !attack || !defense)
        return (84);
    set_font_to_all(game->player.stat_txt, font, 3);
    set_position_to_all(game->player.stat_txt, 3);
    set_char_size_to_all(game->player.stat_txt, 3);
    return (0);
}