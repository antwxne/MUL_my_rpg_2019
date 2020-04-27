/*
** EPITECH PROJECT, 2020
** 42
** File description:
** 42
*/

#include "particule.h"

void my_put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y,
                sfColor color)
{
    int width = framebuffer->width;
    framebuffer->pixels[((x * width) + y) * 4 + 0] = color.r;
    framebuffer->pixels[((x * width) + y) * 4 + 1] = color.g;
    framebuffer->pixels[((x * width) + y) * 4 + 2] = color.b;
    framebuffer->pixels[((x * width) + y) * 4 + 3] = color.a;
}

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *framebuffer = malloc(sizeof(framebuffer_t));
    if (!framebuffer)
        return (NULL);
    framebuffer->width = width;
    framebuffer->height = height;
    framebuffer->pixels = malloc(width * height * 8);
    return (framebuffer);
}

void particule_red(int x, int y, int nb_repetition)
{
    sfColor color;
    int n = 0;
    framebuffer_t *frame = framebuffer_create(30, 30);

    color.a = 100;
    color.b = 0;
    color.g = 0;
    color.r = 255;
    while (n != nb_repetition) {
        my_put_pixel(frame, x, y, color);
        y = y + frame->height;
        color.a = color.a - 10 * n;
        n++;
    }
}