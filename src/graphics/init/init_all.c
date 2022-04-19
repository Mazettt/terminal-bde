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
    events->mouse.pos = (sfVector2i){0, 0};
}

void init_all_events(events_t *events)
{
    events->escape = false;
    init_all_events_mouse(events);
}

void init_all_csfml(bde_csfml_t *csfml_all)
{
    csfml_all->begin.fps.clock = sfClock_create();
    csfml_all->begin.fps.timer = 0;
    csfml_all->current_d = (my_datas_t){NULL, 0, false};
    csfml_all->text_numpad = malloc(sizeof(char) * 5);
    csfml_all->text_numpad[0] = '\0';
    csfml_all->clock_screens = sfClock_create();
    csfml_all->begin.fps.clock = sfClock_create();
    init_all_events(&csfml_all->all_events);
    init_screens(csfml_all);
    csfml_all->spritesheet = malloc(sizeof(spritesheet_t) * NBR_SP);
    init_spritesheets(csfml_all->spritesheet, &csfml_all->begin);
    init_csfml(&csfml_all->begin);
}
