/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** crisscross_rect
*/

#include <stdlib.h>
#include "game.h"

static sfIntRect **malloc_rect_arr(void)
{
    sfIntRect **arr = malloc(sizeof(sfIntRect *)*((window_size_y/rect_size)+1));

    if (!arr)
        return (NULL);
    for (unsigned int i = 0; i < ((window_size_y / rect_size)); i++)
    {
        arr[i] = malloc(sizeof(sfIntRect) * ((window_size_x / rect_size)));
        if (!arr[i])
            return (NULL);
    }
    return (arr);
}

sfIntRect **create_rect_arr(void)
{
    sfIntRect **arr = malloc_rect_arr();
    unsigned int y = 0;

    if (!arr)
        return (NULL);
    for (; y < ((window_size_y / rect_size)); y++)
        for ( unsigned int x = 0; x < ((window_size_x / rect_size)); x++)
            arr[y][x] = (sfIntRect) {x*rect_size, y*rect_size,
                rect_size, rect_size};
    arr[y] = NULL;
    return (arr);
}

sfVector2i get_pos_int_rect(sfIntRect const **rect_arr, sfVector2i const m_pos)
{
    for (unsigned int y = 0; y < ((window_size_y / rect_size)); y++)
        for ( unsigned int x = 0; x < ((window_size_x / rect_size)); x++)
            if (sfIntRect_contains(&rect_arr[y][x], m_pos.x, m_pos.y))
                return ((sfVector2i) {rect_arr[y][x].left, rect_arr[y][x].top});
    return ((sfVector2i) {-1000, 0});
}

void move_rect_on_mouse(sfVector2i const pos, sfRectangleShape **shape)
{
    sfRectangleShape_setPosition(*shape, (sfVector2f) {pos.x, pos.y});
}