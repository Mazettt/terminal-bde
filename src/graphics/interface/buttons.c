/*
** EPITECH PROJECT, 2021
** terminal_bde
** File description:
** menu.c
*/

#include "../../../include/bde.h"

EXT_INTS

void button_num_1(bde_csfml_t *csfml_all)
{
    int len = strlen(csfml_all->text_numpad);

    if (len < 2) {
        csfml_all->text_numpad[len] = '1';
        csfml_all->text_numpad[len + 1] = '\0';
    }
}

void button_num_2(bde_csfml_t *csfml_all)
{
    int len = strlen(csfml_all->text_numpad);

    if (len < 2) {
        csfml_all->text_numpad[len] = '2';
        csfml_all->text_numpad[len + 1] = '\0';
    }
}

void button_num_3(bde_csfml_t *csfml_all)
{
    int len = strlen(csfml_all->text_numpad);

    if (len < 2) {
        csfml_all->text_numpad[len] = '3';
        csfml_all->text_numpad[len + 1] = '\0';
    }
}

void button_num_4(bde_csfml_t *csfml_all)
{
    int len = strlen(csfml_all->text_numpad);

    if (len < 2) {
        csfml_all->text_numpad[len] = '4';
        csfml_all->text_numpad[len + 1] = '\0';
    }
}

void button_num_5(bde_csfml_t *csfml_all)
{
    int len = strlen(csfml_all->text_numpad);

    if (len < 2) {
        csfml_all->text_numpad[len] = '5';
        csfml_all->text_numpad[len + 1] = '\0';
    }
}

void button_num_6(bde_csfml_t *csfml_all)
{
    int len = strlen(csfml_all->text_numpad);

    if (len < 2) {
        csfml_all->text_numpad[len] = '6';
        csfml_all->text_numpad[len + 1] = '\0';
    }
}

void button_num_7(bde_csfml_t *csfml_all)
{
    int len = strlen(csfml_all->text_numpad);

    if (len < 2) {
        csfml_all->text_numpad[len] = '7';
        csfml_all->text_numpad[len + 1] = '\0';
    }
}

void button_num_8(bde_csfml_t *csfml_all)
{
    int len = strlen(csfml_all->text_numpad);

    if (len < 2) {
        csfml_all->text_numpad[len] = '8';
        csfml_all->text_numpad[len + 1] = '\0';
    }
}

void button_num_9(bde_csfml_t *csfml_all)
{
    int len = strlen(csfml_all->text_numpad);

    if (len < 2) {
        csfml_all->text_numpad[len] = '9';
        csfml_all->text_numpad[len + 1] = '\0';
    }
}

void button_num_0(bde_csfml_t *csfml_all)
{
    int len = strlen(csfml_all->text_numpad);

    if (len < 2) {
        csfml_all->text_numpad[len] = '0';
        csfml_all->text_numpad[len + 1] = '\0';
    }
}

void button_num_check(bde_csfml_t *csfml_all)
{
    if (csfml_all->screens[SC_BUY]) {
        csfml_all->screens[SC_BUY] = false;
        toggle_spritesheet_scene(csfml_all, false, screen_buy, csfml_all->spritesheet);
        if (csfml_all->current_d.credits - atoi(csfml_all->text_numpad) < 0) {
            csfml_all->screens[SC_NO_ENOUTH] = true;
            toggle_spritesheet_scene(csfml_all, true, screen_no_enouth, csfml_all->spritesheet);
        } else {
            csfml_all->screens[SC_DEBITED] = true;
            toggle_spritesheet_scene(csfml_all, true, screen_debited, csfml_all->spritesheet);
            modify_one_row(csfml_all->sql.con, csfml_all->current_d.id_card, csfml_all->current_d.credits - atoi(csfml_all->text_numpad));
        }
    }
    if (csfml_all->screens[SC_ADD_CREDITS]) {
        csfml_all->screens[SC_ADD_CREDITS] = false;
        csfml_all->screens[SC_MENU] = true;
        toggle_spritesheet_scene(csfml_all, false, screen_add_credits, csfml_all->spritesheet);
        toggle_spritesheet_scene(csfml_all, true, screen_menu, csfml_all->spritesheet);
        modify_one_row(csfml_all->sql.con, csfml_all->current_d.id_card, csfml_all->current_d.credits + atoi(csfml_all->text_numpad));
        csfml_all->current_d.credits = get_nbr_credits(csfml_all->sql.con, csfml_all->current_d.id_card);
    }
}

void button_num_cancel(bde_csfml_t *csfml_all)
{
    if (csfml_all->screens[SC_ADD_CREDITS])
        toggle_spritesheet_scene(csfml_all, false, screen_add_credits, csfml_all->spritesheet);
    if (csfml_all->screens[SC_BUY])
        toggle_spritesheet_scene(csfml_all, false, screen_buy, csfml_all->spritesheet);
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
    toggle_spritesheet_scene(csfml_all, true, screen_scan_admin, csfml_all->spritesheet);
    csfml_all->screens[SC_MENU] = false;
    csfml_all->screens[SC_SCAN_ADMIN] = true;
}

void button_back(bde_csfml_t *csfml_all)
{
    if (csfml_all->screens[SC_ADDED_TO_DB] || csfml_all->screens[SC_NO_ENOUTH]) {
        csfml_all->screens[SC_ADDED_TO_DB] = false;
        csfml_all->screens[SC_NO_ENOUTH] = false;
        csfml_all->screens[SC_MENU] = true;
        toggle_spritesheet_scene(csfml_all, false, screen_added_in_db, csfml_all->spritesheet);
        toggle_spritesheet_scene(csfml_all, false, screen_no_enouth, csfml_all->spritesheet);
        toggle_spritesheet_scene(csfml_all, true, screen_menu, csfml_all->spritesheet);
    }
    if (csfml_all->screens[SC_DEBITED]) {
        csfml_all->screens[SC_DEBITED] = false;
        csfml_all->screens[SC_SCAN] = true;
        toggle_spritesheet_scene(csfml_all, false, screen_debited, csfml_all->spritesheet);
        toggle_spritesheet_scene(csfml_all, true, screen_scan, csfml_all->spritesheet);
    }
    if (csfml_all->screens[SC_SCAN_ADMIN]) {
        csfml_all->screens[SC_SCAN_ADMIN] = false;
        csfml_all->screens[SC_MENU] = true;
        toggle_spritesheet_scene(csfml_all, false, screen_scan_admin, csfml_all->spritesheet);
        toggle_spritesheet_scene(csfml_all, true, screen_menu, csfml_all->spritesheet);
    }
    if (csfml_all->screens[SC_MENU]) {
        csfml_all->screens[SC_MENU] = false;
        csfml_all->screens[SC_SCAN] = true;
        toggle_spritesheet_scene(csfml_all, false, screen_menu, csfml_all->spritesheet);
        toggle_spritesheet_scene(csfml_all, true, screen_scan, csfml_all->spritesheet);
    }
}
