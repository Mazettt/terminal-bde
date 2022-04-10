/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** myrpg.c
*/

#include "../../include/bde.h"

extern int screen_menu[];
extern int screen_add_credits[];
extern int screen_scan_card[];
extern int screen_remove_credits[];

void draw_spritesheets(beginning_t *begin, spritesheet_t *spritesheet)
{
    for (int i = 0; i < NBR_SP; ++i)
        if (spritesheet[i].active)
            draw_one_sprite(begin, spritesheet[i].sprite, spritesheet[i].rect,
            spritesheet[i].pos);
}

void draw_all(bde_csfml_t *csfml_all)
{
    sfSprite_setTexture(csfml_all->begin.sprite, csfml_all->begin.texture, sfFalse);
    sfTexture_updateFromPixels(csfml_all->begin.texture,
    csfml_all->begin.framebuffer, WIDTH, HEIGHT, 0, 0);
    sfRenderWindow_drawSprite(csfml_all->begin.window,
    csfml_all->begin.sprite, NULL);
    draw_spritesheets(&csfml_all->begin, csfml_all->spritesheet);
    sfRenderWindow_display(csfml_all->begin.window);
}

void big_loop_graphics(bde_csfml_t *csfml_all)
{
    my_events(csfml_all);
    check_click_buttons(csfml_all);
    check_mouse_on_all_buttons(csfml_all);
    draw_all(csfml_all);
}

// void bde_graphics(void)
// {
//     bde_csfml_t *csfml_all = malloc(sizeof(bde_csfml_t));

//     init_all_csfml(csfml_all);
//     if (!csfml_all->begin.window || !csfml_all->begin.framebuffer)
//         return;
//     sfWindow_setFramerateLimit((sfWindow *)csfml_all->begin.window, 60);
//     csfml_all->begin.fps.clock = sfClock_create();
//     while (sfRenderWindow_isOpen(csfml_all->begin.window)) {
//         clean_window(&csfml_all->begin, sfBlack);
//         big_loop_graphics(csfml_all);
//     }
//     destroy_all(csfml_all);
// }
