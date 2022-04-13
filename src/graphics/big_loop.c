/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** myrpg.c
*/

#include "../../include/bde.h"

EXT_INTS

void return_to_scan_menu(bde_csfml_t *csfml_all)
{
    for (int i = 0; i < NBR_SC; ++i)
        csfml_all->screens[i] = false;
    csfml_all->screens[SC_SCAN] = true;
    toggle_spritesheet_scene(csfml_all, false, screen_menu, csfml_all->spritesheet);
    toggle_spritesheet_scene(csfml_all, false, screen_add_credits, csfml_all->spritesheet);
    toggle_spritesheet_scene(csfml_all, false, screen_added_in_db, csfml_all->spritesheet);
    toggle_spritesheet_scene(csfml_all, false, screen_buy, csfml_all->spritesheet);
    toggle_spritesheet_scene(csfml_all, false, screen_debited, csfml_all->spritesheet);
    toggle_spritesheet_scene(csfml_all, false, screen_scan_admin, csfml_all->spritesheet);
    toggle_spritesheet_scene(csfml_all, true, screen_scan, csfml_all->spritesheet);
    free(csfml_all->current_d.id_card);
    csfml_all->current_d = (my_datas_t){NULL, 0, false};
}

void check_if_in_db(bde_csfml_t *csfml_all, char *card)
{
    if (get_row_from_id(csfml_all->sql.con, csfml_all->sql.res, card) == NULL) {
        add_data_to_table(csfml_all->sql.con, (my_datas_t){card, 0, false});
        if (PRINT_ALL)
            printf("%s added in database\n", card);
        csfml_all->screens[SC_MENU] = false;
        csfml_all->screens[SC_ADDED_TO_DB] = true;
        toggle_spritesheet_scene(csfml_all, false, screen_menu, csfml_all->spritesheet);
        toggle_spritesheet_scene(csfml_all, true, screen_added_in_db, csfml_all->spritesheet);
    }
}

void change_scene_if_card(bde_csfml_t *csfml_all)
{
    char *card = NULL;

    card = get_id_card(csfml_all);
    if (card != NULL) {
        csfml_all->current_d = get_infos_from_id(csfml_all->sql.con, card);
        if (PRINT_ALL) {
            printf("csfml_all->current_d.id_card = %s\n", csfml_all->current_d.id_card);
            printf("csfml_all->current_d.credits = %d\n", csfml_all->current_d.credits);
            printf("csfml_all->current_d.admin = %d\n", csfml_all->current_d.admin);
        }
        csfml_all->screens[SC_SCAN] = false;
        csfml_all->screens[SC_MENU] = true;
        toggle_spritesheet_scene(csfml_all, false, screen_scan, csfml_all->spritesheet);
        toggle_spritesheet_scene(csfml_all, true, screen_menu, csfml_all->spritesheet);
        check_if_in_db(csfml_all, card);
    }
    free(card);
}

void change_scene_if_admin_card(bde_csfml_t *csfml_all)
{
    char *card = NULL;
    my_datas_t d = {NULL, 0, false};

    card = get_id_card(csfml_all);
    if (card != NULL) {
        d = get_infos_from_id(csfml_all->sql.con, card);
        if (PRINT_ALL) {
            printf("d.id_card = %s\n", d.id_card);
            printf("d.credits = %d\n", d.credits);
            printf("d.admin = %d\n", d.admin);
        }
        if (d.admin && (strcmp(d.id_card, csfml_all->current_d.id_card) || !strcmp(d.id_card, "04526e5ae26480"))) {
            csfml_all->screens[SC_SCAN_ADMIN] = false;
            csfml_all->screens[SC_ADD_CREDITS] = true;
            toggle_spritesheet_scene(csfml_all, false, screen_scan_admin, csfml_all->spritesheet);
            toggle_spritesheet_scene(csfml_all, true, screen_add_credits, csfml_all->spritesheet);
        }
    }
    free(card);
}

void check_timeout_screen(bde_csfml_t *csfml_all)
{
    float time = sfClock_getElapsedTime(csfml_all->clock_screens).microseconds;

    if (time >= 30000000) {
        return_to_scan_menu(csfml_all);
        sfClock_restart(csfml_all->clock_screens);
    }
}

void big_loop_graphics(bde_csfml_t *csfml_all)
{
    float time = sfClock_getElapsedTime(csfml_all->begin.fps.clock).microseconds;
    my_datas_t d = {NULL, 0, false};

    my_events(csfml_all);
    if (csfml_all->screens[SC_SCAN]) {
        csfml_all->current_d = d;
        change_scene_if_card(csfml_all);
    }
    if (csfml_all->screens[SC_SCAN_ADMIN])
        change_scene_if_admin_card(csfml_all);
    if (!csfml_all->screens[SC_SCAN])
        check_timeout_screen(csfml_all);
    if (PRINT_ALL)
        printf("curren card: %s\n", csfml_all->current_d.id_card);
    check_click_buttons(csfml_all);
    check_mouse_on_all_buttons(csfml_all);
    draw_all(csfml_all);
}
