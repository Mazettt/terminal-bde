/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** utils.c
*/

#include "../../include/bde.h"

sfUint8 *my_framebuffer_create(void)
{
    sfUint8 *framebuffer = malloc(sizeof(sfUint8) * (WIDTH * HEIGHT * 4));
    return (framebuffer);
}

void init_csfml(beginning_t *begin)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    if (RPI)
        begin->window = sfRenderWindow_create(mode, "Paiement",
        sfClose | sfFullscreen, NULL);
    else
        begin->window = sfRenderWindow_create(mode, "Paiement",
        sfClose, NULL);
    begin->framebuffer = my_framebuffer_create();
    begin->texture = sfTexture_create(WIDTH, HEIGHT);
    begin->sprite = sfSprite_create();
}

int my_rand(int min, int max)
{
    return (min + rand() % ((max + 1) - min));
}

bool check_mouse_on_one_button(sfVector2i pos, sfFloatRect collision)
{
    if (pos.x > collision.left &&
    pos.x < collision.left + collision.width &&
    pos.y > collision.top &&
    pos.y < collision.top + collision.height)
        return (true);
    else
        return (false);
}
