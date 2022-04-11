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

bool check_if_card(void)
{
    char *test = NULL;

    test = get_id_card(1, NULL);
    if (test == NULL)
        printf("non\n");
    else
        printf("test = %s\n", test);
    free(test);
    return (0);
}

void check_if_in_db(bde_csfml_t *csfml_all, char *card)
{
    if (get_row_from_id(csfml_all->sql.con, csfml_all->sql.res, card) == NULL) {
        add_data_to_table(csfml_all->sql.con, (my_datas_t){card, 0, false});
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

    card = get_id_card(1, NULL);
    printf("test\n");
    if (card != NULL) {
        printf("card = %s\n", card);
        csfml_all->current_d = get_infos_from_id(csfml_all->sql.con, card);
        printf("csfml_all->current_d.id_card = %s\n", csfml_all->current_d.id_card);
        printf("csfml_all->current_d.credits = %d\n", csfml_all->current_d.credits);
        printf("csfml_all->current_d.admin = %d\n", csfml_all->current_d.admin);
        // csfml_all->current_d.id_card = strdup(card);
        // csfml_all->current_d.credits = get_nbr_credits(csfml_all->sql.con, csfml_all->current_d.id_card);
        csfml_all->screens[SC_SCAN] = false;
        csfml_all->screens[SC_MENU] = true;
        toggle_spritesheet_scene(csfml_all, false, screen_scan, csfml_all->spritesheet);
        toggle_spritesheet_scene(csfml_all, true, screen_menu, csfml_all->spritesheet);
        check_if_in_db(csfml_all, card);
    }
    sfClock_restart(csfml_all->begin.fps.clock);
    free(card);
}

void change_scene_if_admin_card(bde_csfml_t *csfml_all)
{
    char *card = NULL;
    my_datas_t d = {NULL, 0, false};

    card = get_id_card(1, NULL);
    printf("test admin\n");
    if (card != NULL) {
        printf("card admin = %s\n", card);
        d = get_infos_from_id(csfml_all->sql.con, card);
        printf("d.id_card = %s\n", d.id_card);
        printf("d.credits = %d\n", d.credits);
        printf("d.admin = %d\n", d.admin);
        if (d.admin) {
            csfml_all->screens[SC_SCAN_ADMIN] = false;
            csfml_all->screens[SC_ADD_CREDITS] = true;
            toggle_spritesheet_scene(csfml_all, false, screen_scan_admin, csfml_all->spritesheet);
            toggle_spritesheet_scene(csfml_all, true, screen_add_credits, csfml_all->spritesheet);
        }
    }
    sfClock_restart(csfml_all->begin.fps.clock);
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

    my_events(csfml_all);
    if (time >= 100000 && csfml_all->screens[SC_SCAN]) {
        // free(csfml_all->current_d.id_card);
        change_scene_if_card(csfml_all);
    }
    if (time >= 100000 && csfml_all->screens[SC_SCAN_ADMIN]) {
        change_scene_if_admin_card(csfml_all);
    }
    if (!csfml_all->screens[SC_SCAN])
        check_timeout_screen(csfml_all);
    // printf("current_d.id_card = %s\n", csfml_all->current_d.id_card);
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
