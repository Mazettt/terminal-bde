/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** destroy_all.c
*/

#include "../../include/bde.h"

void destroy_begin(bde_csfml_t *csfml_all)
{
    sfRenderWindow_destroy(csfml_all->begin.window);
    free(csfml_all->begin.framebuffer);
    sfTexture_destroy(csfml_all->begin.texture);
    sfSprite_destroy(csfml_all->begin.sprite);
    sfClock_destroy(csfml_all->begin.fps.clock);
}

void destroy_spritesheets(bde_csfml_t *csfml_all)
{
    for (int i = 0; i < NBR_SP; ++i) {
        sfSprite_destroy(csfml_all->spritesheet[i].sprite);
        sfTexture_destroy(csfml_all->spritesheet[i].texture);
        sfClock_destroy(csfml_all->spritesheet[i].c_anim);
        sfClock_destroy(csfml_all->spritesheet[i].c_attack);
    }
    free(csfml_all->spritesheet);
}

void destroy_screens(bde_csfml_t *csfml_all)
{
    free(csfml_all->screens);
}

void destroy_all(bde_csfml_t *csfml_all)
{
    destroy_begin(csfml_all);
    destroy_spritesheets(csfml_all);
    destroy_screens(csfml_all);
    free(csfml_all);
}
