/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** init_all.c
*/

#include "../../../include/bde.h"

void init_all_events_mouse(events_t *events)
{
    events->mouse.left = false;
    events->mouse.left_released = false;
    events->mouse.right = false;
    events->mouse.move_x = 0;
    events->mouse.move_y = 0;
    events->mouse.pos = (sfVector2i){0, 0};
    events->mouse_wheel.up = false;
    events->mouse_wheel.down = false;
    events->mouse_wheel.click = false;
}

void init_all_events(events_t *events)
{
    events->left = false;
    events->right = false;
    events->up = false;
    events->down = false;
    events->page_up = false;
    events->page_down = false;
    events->z = false;
    events->q = false;
    events->s = false;
    events->d = false;
    events->e = false;
    events->escape = false;
    events->space = false;
    events->ctrl = false;
    events->tab = false;
    events->enter = false;
    init_all_events_mouse(events);
}

void init_all_csfml(bde_csfml_t *csfml_all)
{
    csfml_all->begin.fps.clock = sfClock_create();
    csfml_all->begin.fps.timer = 0;
    init_all_events(&csfml_all->all_events);
    init_screens(csfml_all);
    csfml_all->spritesheet = malloc(sizeof(spritesheet_t) * NBR_SP);
    init_spritesheets(csfml_all->spritesheet, &csfml_all->begin);
    init_csfml(&csfml_all->begin);
}
