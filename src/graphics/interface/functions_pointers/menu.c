/*
** EPITECH PROJECT, 2021
** terminal_bde
** File description:
** menu.c
*/

#include "../../../../include/bde.h"

extern int screen_menu[];
extern int screen_buy[];
extern int screen_display_credits[];
extern int screen_add_credits[];

void button_num_1(bde_csfml_t *csfml_all)
{

}

void button_num_2(bde_csfml_t *csfml_all)
{

}

void button_num_3(bde_csfml_t *csfml_all)
{

}

void button_num_4(bde_csfml_t *csfml_all)
{

}

void button_num_5(bde_csfml_t *csfml_all)
{

}

void button_num_6(bde_csfml_t *csfml_all)
{

}

void button_num_7(bde_csfml_t *csfml_all)
{

}

void button_num_8(bde_csfml_t *csfml_all)
{

}

void button_num_9(bde_csfml_t *csfml_all)
{

}

void button_num_0(bde_csfml_t *csfml_all)
{

}

void button_num_check(bde_csfml_t *csfml_all)
{
    if (csfml_all->screens[SC_ADD_CREDITS])
        toggle_spritesheet_scene(csfml_all, false, screen_add_credits, csfml_all->spritesheet);
    if (csfml_all->screens[SC_BUY])
        toggle_spritesheet_scene(csfml_all, false, screen_buy, csfml_all->spritesheet);
    if (csfml_all->screens[SC_DISPLAY_CREDITS])
        toggle_spritesheet_scene(csfml_all, false, screen_display_credits, csfml_all->spritesheet);
    toggle_spritesheet_scene(csfml_all, true, screen_menu, csfml_all->spritesheet);
    for (int i = 0; i < NBR_SC; ++i)
        csfml_all->screens[i] = false;
    csfml_all->screens[SC_MENU] = true;
}

void button_num_cancel(bde_csfml_t *csfml_all)
{
    if (csfml_all->screens[SC_ADD_CREDITS])
        toggle_spritesheet_scene(csfml_all, false, screen_add_credits, csfml_all->spritesheet);
    if (csfml_all->screens[SC_BUY])
        toggle_spritesheet_scene(csfml_all, false, screen_buy, csfml_all->spritesheet);
    if (csfml_all->screens[SC_DISPLAY_CREDITS])
        toggle_spritesheet_scene(csfml_all, false, screen_display_credits, csfml_all->spritesheet);
    toggle_spritesheet_scene(csfml_all, true, screen_menu, csfml_all->spritesheet);
    for (int i = 0; i < NBR_SC; ++i)
        csfml_all->screens[i] = false;
    csfml_all->screens[SC_MENU] = true;
}

void button_buy(bde_csfml_t *csfml_all)
{
    toggle_spritesheet_scene(csfml_all, false, screen_menu, csfml_all->spritesheet);
    toggle_spritesheet_scene(csfml_all, true, screen_buy, csfml_all->spritesheet);
    csfml_all->screens[SC_MENU] = false;
    csfml_all->screens[SC_BUY] = true;
}

void button_add_credits(bde_csfml_t *csfml_all)
{
    toggle_spritesheet_scene(csfml_all, false, screen_menu, csfml_all->spritesheet);
    toggle_spritesheet_scene(csfml_all, true, screen_add_credits, csfml_all->spritesheet);
    csfml_all->screens[SC_MENU] = false;
    csfml_all->screens[SC_ADD_CREDITS] = true;
}

void button_display_credits(bde_csfml_t *csfml_all)
{
    toggle_spritesheet_scene(csfml_all, false, screen_menu, csfml_all->spritesheet);
    toggle_spritesheet_scene(csfml_all, true, screen_display_credits, csfml_all->spritesheet);
    csfml_all->screens[SC_MENU] = false;
    csfml_all->screens[SC_DISPLAY_CREDITS] = true;
}
