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
    begin->window = sfRenderWindow_create(mode, "Paiement",
    sfClose/*  | sfFullscreen */, NULL);
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

char *my_itoa(int nb)
{
    int i = 0;
    char *str;
    int tmp = nb;

    while (tmp > 0) {
        tmp /= 10;
        ++i;
    }
    str = malloc(sizeof(str) * (i + 1));
    str[i] = '\0';
    while (i > 0) {
        i--;
        str[i] = nb % 10 + 48;
        nb /= 10;
    }
    return (str);
}
