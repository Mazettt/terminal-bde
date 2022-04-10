/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** check_click_buttons.c
*/

#include "../../../include/bde.h"

void nothing(bde_csfml_t *csfml_all)
{
    return;
}

bool check_click_one_button(bde_csfml_t *csfml_all, int i)
{
    static const void (*functions[])(bde_csfml_t *) = FUNCTIONS_BUTTONS;
    sfFloatRect collision;

    if (csfml_all->spritesheet[i].clickable && csfml_all->spritesheet[i].active) {
        collision = sfSprite_getGlobalBounds(csfml_all->spritesheet[i].sprite);
        if (check_mouse_on_one_button(csfml_all->all_events.mouse.pos, collision)) {
            (*functions[i])(csfml_all);
            csfml_all->all_events.mouse.left = false;
            return (true);
        }
    }
    return (false);
}

void check_click_buttons(bde_csfml_t *csfml_all)
{
    if (!csfml_all->all_events.mouse.left_released)
        return;
    for (int i = 0; i < NBR_SP; ++i)
        if (check_click_one_button(csfml_all, i))
            return;
}
