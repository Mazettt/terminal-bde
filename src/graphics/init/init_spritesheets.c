/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-martin.d-herouville
** File description:
** init_main_map.c
*/

#include "../../../include/bde.h"

void init_numbers(spritesheet_t *spritesheet, beginning_t *begin)
{
    int offset = 130;
    set_one_sprite("assets/0.png", &spritesheet[SP_0],
    begin, (init_sprite_t){{WIDTH / 2, HEIGHT / 6 * 5}, {0.15, 0.15},
    {0, 0, 541, 541}, .clickable = true, .change_sprite_on_mouse = true, .active = false});
    set_one_sprite("assets/1.png", &spritesheet[SP_1],
    begin, (init_sprite_t){{WIDTH / 2 - offset, HEIGHT / 6 * 4}, {0.15, 0.15},
    {0, 0, 541, 541}, .clickable = true, .change_sprite_on_mouse = true, .active = false});
    set_one_sprite("assets/2.png", &spritesheet[SP_2],
    begin, (init_sprite_t){{WIDTH / 2, HEIGHT / 6 * 4}, {0.15, 0.15},
    {0, 0, 541, 541}, .clickable = true, .change_sprite_on_mouse = true, .active = false});
    set_one_sprite("assets/3.png", &spritesheet[SP_3],
    begin, (init_sprite_t){{WIDTH / 2 + offset, HEIGHT / 6 * 4}, {0.15, 0.15},
    {0, 0, 541, 541}, .clickable = true, .change_sprite_on_mouse = true, .active = false});
    set_one_sprite("assets/4.png", &spritesheet[SP_4],
    begin, (init_sprite_t){{WIDTH / 2 - offset, HEIGHT / 6 * 3}, {0.15, 0.15},
    {0, 0, 541, 541}, .clickable = true, .change_sprite_on_mouse = true, .active = false});
    set_one_sprite("assets/5.png", &spritesheet[SP_5],
    begin, (init_sprite_t){{WIDTH / 2, HEIGHT / 6 * 3}, {0.15, 0.15},
    {0, 0, 541, 541}, .clickable = true, .change_sprite_on_mouse = true, .active = false});
    set_one_sprite("assets/6.png", &spritesheet[SP_6],
    begin, (init_sprite_t){{WIDTH / 2 + offset, HEIGHT / 6 * 3}, {0.15, 0.15},
    {0, 0, 541, 541}, .clickable = true, .change_sprite_on_mouse = true, .active = false});
    set_one_sprite("assets/7.png", &spritesheet[SP_7],
    begin, (init_sprite_t){{WIDTH / 2 - offset, HEIGHT / 6 * 2}, {0.15, 0.15},
    {0, 0, 541, 541}, .clickable = true, .change_sprite_on_mouse = true, .active = false});
    set_one_sprite("assets/8.png", &spritesheet[SP_8],
    begin, (init_sprite_t){{WIDTH / 2, HEIGHT / 6 * 2}, {0.15, 0.15},
    {0, 0, 541, 541}, .clickable = true, .change_sprite_on_mouse = true, .active = false});
    set_one_sprite("assets/9.png", &spritesheet[SP_9],
    begin, (init_sprite_t){{WIDTH / 2 + offset, HEIGHT / 6 * 2}, {0.15, 0.15},
    {0, 0, 541, 541}, .clickable = true, .change_sprite_on_mouse = true, .active = false});
    set_one_sprite("assets/check.png", &spritesheet[SP_CHECK],
    begin, (init_sprite_t){{WIDTH / 2 + offset, HEIGHT / 6 * 5}, {0.15, 0.15},
    {0, 0, 541, 541}, .clickable = true, .change_sprite_on_mouse = true, .active = false});
    set_one_sprite("assets/cancel.png", &spritesheet[SP_CANCEL],
    begin, (init_sprite_t){{WIDTH / 2 - offset, HEIGHT / 6 * 5}, {0.15, 0.15},
    {0, 0, 541, 541}, .clickable = true, .change_sprite_on_mouse = true, .active = false});
    set_one_sprite("assets/return.png", &spritesheet[SP_RETURN],
    begin, (init_sprite_t){{WIDTH / 2 + offset, HEIGHT / 6 * 1}, {0.15, 0.15},
    {0, 0, 541, 541}, .clickable = true, .change_sprite_on_mouse = true, .active = false});
}

void init_menu(spritesheet_t *spritesheet, beginning_t *begin)
{
    set_one_sprite("assets/buy.png", &spritesheet[SP_BUY],
    begin, (init_sprite_t){{WIDTH / 2, HEIGHT / 4 * 1}, {0.12, 0.12},
    {0, 0, 2705, 541}, .clickable = true, .change_sprite_on_mouse = true, .active = false});
    set_one_sprite("assets/add_credits.png", &spritesheet[SP_ADD_CREDITS],
    begin, (init_sprite_t){{WIDTH / 2, HEIGHT / 4 * 2}, {0.12, 0.12},
    {0, 0, 2705, 541}, .clickable = true, .change_sprite_on_mouse = true, .active = false});
    set_one_sprite("assets/back.png", &spritesheet[SP_BACK],
    begin, (init_sprite_t){{WIDTH / 2, HEIGHT / 4 * 3}, {0.12, 0.12},
    {0, 0, 2705, 541}, .clickable = true, .change_sprite_on_mouse = true, .active = false});
}

void init_scan(spritesheet_t *spritesheet, beginning_t *begin)
{
    set_one_sprite("assets/scan.png", &spritesheet[SP_SCAN],
    begin, (init_sprite_t){{WIDTH / 2, HEIGHT / 2}, {0.2, 0.2},
    {0, 0, 2705, 1623}, .clickable = false, .change_sprite_on_mouse = false, .active = true});
    set_one_sprite("assets/scan_admin.png", &spritesheet[SP_SCAN_ADMIN],
    begin, (init_sprite_t){{WIDTH / 2, HEIGHT / 2}, {0.2, 0.2},
    {0, 0, 2705, 1623}, .clickable = false, .change_sprite_on_mouse = false, .active = false});
}

void init_spritesheets(spritesheet_t *spritesheet, beginning_t *begin)
{
    init_numbers(spritesheet, begin);
    init_menu(spritesheet, begin);
    init_scan(spritesheet, begin);
    set_one_sprite("assets/added_to_db.png", &spritesheet[SP_ADDED_IN_DB],
    begin, (init_sprite_t){{WIDTH / 2, HEIGHT / 2}, {0.2, 0.2},
    {0, 0, 2705, 1623}, .clickable = false, .change_sprite_on_mouse = false, .active = false});
    set_one_sprite("assets/no_enouth.png", &spritesheet[SP_NO_ENOUTH],
    begin, (init_sprite_t){{WIDTH / 2, HEIGHT / 2}, {0.2, 0.2},
    {0, 0, 2705, 1623}, .clickable = false, .change_sprite_on_mouse = false, .active = false});
}
