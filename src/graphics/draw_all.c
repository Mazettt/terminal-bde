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
    sfVector2f pos = {WIDTH / 2, 50};

    if (csfml_all->screens[SC_ADD_CREDITS] || csfml_all->screens[SC_BUY]) {
        if (strlen(csfml_all->text_numpad) == 2)
            pos.x -= 25;
        else if (strlen(csfml_all->text_numpad) == 1)
            pos.x -= 10;
        write_text(&csfml_all->begin, (init_text_t){csfml_all->text_numpad, 50, pos, sfBlack});
    }
    if (csfml_all->screens[SC_MENU]) {
        sprintf(buff, "You have %d credits.", csfml_all->current_d.credits);
        write_text(&csfml_all->begin, (init_text_t){buff, 25, (sfVector2f){20, HEIGHT - 40}, sfBlack});
    }
    if (csfml_all->screens[SC_DEBITED]) {
        if (csfml_all->text_numpad[0] == '\0')
            sprintf(buff, "with 0 credits.");
        else
            sprintf(buff, "with %s credits.", csfml_all->text_numpad);
        write_text(&csfml_all->begin, (init_text_t){"You have been debited", 30, (sfVector2f){WIDTH / 2 - 160, HEIGHT / 4 - 40}, sfBlack});
        write_text(&csfml_all->begin, (init_text_t){buff, 30, (sfVector2f){WIDTH / 2 - 100, HEIGHT / 4}, sfBlack});
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
