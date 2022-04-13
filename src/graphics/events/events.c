/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** events.c
*/

#include "../../../include/bde.h"

void events_mouse_pressed(beginning_t *begin, sfEvent event,
events_t *all_events)
{
    if (sfMouseLeft == event.key.code)
        all_events->mouse.left = true;
}

void events_mouse_released(beginning_t *begin, sfEvent event,
events_t *all_events)
{
    if (sfMouseLeft == event.key.code) {
        all_events->mouse.left = false;
        all_events->mouse.left_released = true;
    }
}


void events_mouse_global(sfEvent event, beginning_t *begin,
events_t *all_events)
{
    switch (event.type) {
        case sfEvtMouseButtonPressed:
            events_mouse_pressed(begin, event, all_events);
            break;
        case sfEvtMouseButtonReleased:
            events_mouse_released(begin, event, all_events);
            break;
        default:
            break;
    }
}

void my_events(bde_csfml_t *csfml_all)
{
    sfEvent event;

    csfml_all->all_events.mouse.left_released = false;
    while (sfRenderWindow_pollEvent(csfml_all->begin.window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(csfml_all->begin.window);
        if (event.type == sfEvtKeyPressed)
            if (sfKeyEscape == event.key.code)
                sfRenderWindow_close(csfml_all->begin.window);
        if (event.type == sfEvtMouseButtonPressed || event.type == sfEvtMouseButtonReleased) {
            events_mouse_global(event, &csfml_all->begin, &csfml_all->all_events);
            sfClock_restart(csfml_all->clock_screens);
        }
    }
    csfml_all->all_events.mouse.pos = sfMouse_getPositionRenderWindow(csfml_all->begin.window);
}
