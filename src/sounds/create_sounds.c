/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_sounds
*/

#include "stdlib.h"
#include "game.h"
#include "main.h"

static const char *fp_music[] = {
    "music/menu.ogg",
    "music/battle.ogg",
    "music/dead.ogg",
    "music/game.ogg",
    NULL
};

static int len_fp_music(void)
{
    int len = 0;

    for (; fp_music[len] != NULL; len++);
    return (len);
}

bool create_music(game_t *game)
{
    int nb_sound = len_fp_music();

    game->musics = malloc(sizeof(sfMusic *) *(nb_sound));
    if (!game->musics)
        return (false);
    for (int i = 0; i < nb_sound; i++) {
        game->musics[i] = sfMusic_createFromFile(fp_music[i]);
        if (!game->musics[i])
            return (false);
        sfMusic_setLoop(game->musics[i], sfTrue);
    }
    return (true);
}