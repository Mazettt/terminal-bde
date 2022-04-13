/*
** EPITECH PROJECT, 2021
** terminal_bde
** File description:
** draw_all.c
*/

#include "../../include/bde.h"

void draw_spritesheets(beginning_t *begin, spritesheet_t *spritesheet)
{
    for (int i = 0; i < NBR_SP; ++i)
        if (spritesheet[i].active)
            draw_one_sprite(begin, spritesheet[i].sprite, spritesheet[i].rect,
            spritesheet[i].pos);
}

void draw_all_texts(bde_csfml_t *csfml_all)
{
    char buff[50];
    if (csfml_all->screens[SC_ADD_CREDITS] || csfml_all->screens[SC_BUY]) {
        write_text(&csfml_all->begin, (init_text_t){csfml_all->text_numpad, 50, (sfVector2f){WIDTH / 2 - 30, 10}, sfBlack});
    }
    if (csfml_all->screens[SC_MENU]) {
        sprintf(buff, "You have %d credits.", csfml_all->current_d.credits);
        write_text(&csfml_all->begin, (init_text_t){buff, 20, (sfVector2f){10, HEIGHT - 35}, sfBlack});
    }
    if (csfml_all->screens[SC_DEBITED]) {
        sprintf(buff, "with %s credits.", csfml_all->text_numpad);
        write_text(&csfml_all->begin, (init_text_t){"You have been debited", 30, (sfVector2f){WIDTH / 2 - 160, 30}, sfBlack});
        write_text(&csfml_all->begin, (init_text_t){buff, 30, (sfVector2f){WIDTH / 2 - 100, 80}, sfBlack});
    }
}

void draw_all(bde_csfml_t *csfml_all)
{
    sfSprite_setTexture(csfml_all->begin.sprite, csfml_all->begin.texture, sfFalse);
    sfTexture_updateFromPixels(csfml_all->begin.texture,
    csfml_all->begin.framebuffer, WIDTH, HEIGHT, 0, 0);
    sfRenderWindow_drawSprite(csfml_all->begin.window,
    csfml_all->begin.sprite, NULL);
    draw_spritesheets(&csfml_all->begin, csfml_all->spritesheet);
    draw_all_texts(csfml_all);
    sfRenderWindow_display(csfml_all->begin.window);
}
