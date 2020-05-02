/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** manage_game
*/

#include "main.h"
#include "game.h"

void use_pnj(game_t *game);

void use_enemy(game_t *game);

bool click_on_obj(sfEvent event, sfRenderWindow *window, object_t obj)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);
    sfIntRect cmp = obj.rect;
    static bool clic = false;

    cmp.left = obj.position.x;
    cmp.top = obj.position.y;
    if (sfIntRect_contains(&cmp, pos.x, pos.y) &&
        sfMouse_isButtonPressed(sfMouseLeft))
        clic = true;
    if (sfIntRect_contains(&cmp, pos.x, pos.y) &&
        event.type == sfEvtMouseButtonReleased  && clic) {
            clic = false;
            return (true);
        }
    return (false);
}

void manage_game(game_t *game)
{
    if (game->player.stat[3] % 2 == 0)
        use_pnj(game);
    else
        use_enemy(game);
}