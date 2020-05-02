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
    sfVector2f position = {5, 750};

    for (int i = 0; i != nb_texts; i++) {
        sfText_setPosition(texts[i], position);
        position.y += 30;
    }
}

static void set_char_size_to_all(sfText **texts, int nb_texts)
{
    for (int i = 0; i != nb_texts; i++)
        sfText_setCharacterSize(texts[i], 30);
}

void apply_stats(sfText **stats, game_t *game)
{
    char *health =  my_strcat("health : ", my_itoa(game->player.stat[HEALTH]));
    char *attack = my_strcat("attack : ",
                                my_itoa(game->player.stat[ATK_PLAYER]));
    char *defense = my_strcat("defense : ",
                        my_itoa(game->player.stat[DEF_PLAYER]));

    sfText_setString(stats[0], health);
    sfText_setString(stats[1], attack);
    sfText_setString(stats[2], defense);
    free(health);
    free(attack);
    free(defense);
    sfRenderWindow_drawText(game->window, stats[0], NULL);
    sfRenderWindow_drawText(game->window, stats[1], NULL);
    sfRenderWindow_drawText(game->window, stats[2], NULL);
}

int create_hud(game_t *game)
{
    sfText *health = sfText_create();
    sfText *attack = sfText_create();
    sfText *defense = sfText_create();
    game->player.stat_txt[0] = health;
    game->player.stat_txt[1] = attack;
    game->player.stat_txt[2] = defense;
    sfFont *font = sfFont_createFromFile("assets/old_london.ttf");

    if (!health || !attack || !defense)
        return (84);
    set_font_to_all(game->player.stat_txt, font, 3);
    set_position_to_all(game->player.stat_txt, 3);
    set_char_size_to_all(game->player.stat_txt, 3);
    return (0);
}