/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** check_mouse_on_buttons.c
*/

#include "../../../include/bde.h"

void check_one_button(bde_csfml_t *csfml_all, int i)
{
    sfFloatRect collision;

    if (csfml_all->spritesheet[i].active && csfml_all->spritesheet[i].clickable &&
    csfml_all->spritesheet[i].change_sprite_on_mouse) {
        collision = sfSprite_getGlobalBounds(csfml_all->spritesheet[i].sprite);
        if (check_mouse_on_one_button(csfml_all->all_events.mouse.pos, collision)) {
            csfml_all->spritesheet[i].rect.top = (csfml_all->all_events.mouse.left) ?
            csfml_all->spritesheet[i].rect.height * 2 :
            csfml_all->spritesheet[i].rect.height;
        } else
            csfml_all->spritesheet[i].rect.top = 0;
    }
}

void check_mouse_on_all_buttons(bde_csfml_t *csfml_all)
{
    for (int i = 0; i < NBR_SP; ++i)
        check_one_button(csfml_all, i);
}
