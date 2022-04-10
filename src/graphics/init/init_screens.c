/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** init_screens.c
*/

#include "../../../include/bde.h"

const int screen_menu[] = {SP_ADD_CREDITS, SP_BUY, SP_DISPLAY_CREDITS, -1};
const int screen_buy[] = {SP_0, SP_1, SP_2, SP_3, SP_4, SP_5, SP_6, SP_7, SP_8, SP_9, SP_CHECK, SP_CANCEL, -1};
const int screen_display_credits[] = {SP_0, SP_1, SP_2, SP_3, SP_4, SP_5, SP_6, SP_7, SP_8, SP_9, SP_CHECK, SP_CANCEL, -1};
const int screen_add_credits[] = {SP_0, SP_1, SP_2, SP_3, SP_4, SP_5, SP_6, SP_7, SP_8, SP_9, SP_CHECK, SP_CANCEL, -1};
// const int screen_scan_card[] = {-1};
// const int screen_remove_credits[] = {-1};

void init_screens(bde_csfml_t *csfml_all)
{
    csfml_all->screens = malloc(sizeof(bool) * NBR_SC);
    csfml_all->screens[SC_MENU] = true;
    csfml_all->screens[SC_BUY] = false;
    csfml_all->screens[SC_DISPLAY_CREDITS] = false;
    csfml_all->screens[SC_ADD_CREDITS] = false;
}
