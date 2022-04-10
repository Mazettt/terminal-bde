/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** events.c
*/

#include "../../../include/bde.h"

void events_key_global(sfEvent event, bde_csfml_t *csfml_all)
{
    switch (event.type) {
        case sfEvtKeyPressed:
            events_key_pressed(csfml_all, event);
            break;
        case sfEvtKeyReleased:
            events_key_released(event, &csfml_all->all_events);
            break;
        case sfEvtTextEntered:
            break;
        default:
            break;
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
        case sfEvtMouseWheelScrolled:
            events_scroll_wheel(event, all_events);
            break;
        case sfEvtMouseMoved:
            events_mouse_moved(event, all_events);
            break;
        default:
            break;
    }
}

void my_events(bde_csfml_t *csfml_all)
{
    sfEvent event;

    csfml_all->all_events.mouse_wheel.up = false;
    csfml_all->all_events.mouse_wheel.down = false;
    csfml_all->all_events.mouse.left_released = false;
    csfml_all->all_events.mouse.move_x = 0;
    csfml_all->all_events.mouse.move_y = 0;
    while (sfRenderWindow_pollEvent(csfml_all->begin.window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(csfml_all->begin.window);
        if (event.type == sfEvtKeyPressed || event.type == sfEvtKeyReleased ||
        event.type == sfEvtTextEntered)
            events_key_global(event, csfml_all);
        if (event.type == sfEvtMouseButtonPressed || event.type ==
        sfEvtMouseButtonReleased || event.type == sfEvtMouseWheelScrolled ||
        event.type == sfEvtMouseMoved)
            events_mouse_global(event, &csfml_all->begin, &csfml_all->all_events);
    }
    csfml_all->all_events.mouse.pos =
    sfMouse_getPositionRenderWindow(csfml_all->begin.window);
}
