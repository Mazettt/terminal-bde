/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** protos.h
*/

#ifndef PROTOS_H
    #define PROTOS_H

    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <sys/stat.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <stdio.h>
    #include <math.h>
    #include "csfml_structs.h"

void bde_graphics(void);
void big_loop_graphics(bde_csfml_t *csfml_all);
void draw_all(bde_csfml_t *csfml_all);

// events
void events_key_pressed(bde_csfml_t *csfml_all, sfEvent event);
void events_key_released(sfEvent event, events_t *all_events);
void events_mouse_pressed(beginning_t *begin, sfEvent event, events_t *all_events);
void events_mouse_released(beginning_t *begin, sfEvent event, events_t *all_events);
void events_scroll_wheel(sfEvent event, events_t *all_events);
void events_mouse_moved(sfEvent event, events_t *all_events);
void my_events(bde_csfml_t *csfml_all);

// init
void init_all_csfml(bde_csfml_t *csfml_all);
void init_screens(bde_csfml_t *csfml_all);
void init_spritesheets(spritesheet_t *spritesheet, beginning_t *begin);

// draw simple
void my_draw_circle(sfUint8 *framebuffer, sfVector2i center, int radius, sfColor color);
void my_draw_rectangle(sfUint8 *framebuffer, sfIntRect rect, sfColor color);
void my_draw_line(sfUint8 *framebuffer, sfVector2i point_a, sfVector2i point_b, sfColor color);
void my_draw_square(sfUint8 *framebuffer, unsigned int size, sfColor color);
void my_putpixel(int x, int y, sfUint8 *framebuffer, sfColor color);

// interface
void check_click_buttons(bde_csfml_t *csfml_all);
void check_mouse_on_all_buttons(bde_csfml_t *csfml_all);

// utils
void clean_window(beginning_t *begin, sfColor color);
void init_csfml(beginning_t *beginning);
int my_rand(int min, int max);
bool check_mouse_on_one_button(sfVector2i pos, sfFloatRect collision);

// utils sprites
void set_one_sprite(char *filename, spritesheet_t *spritesheet, beginning_t *begin, init_sprite_t init_sprite);
void write_text(beginning_t *begin, init_text_t struct_text);
void draw_one_sprite(beginning_t *begin, sfSprite *sprite, sfIntRect rect, sfVector2f pos);
void toggle_spritesheet_scene(bde_csfml_t *csfml_all, bool status, int *screen_i, spritesheet_t *spritesheet);

// destroy
void destroy_all(bde_csfml_t *csfml_all);

// pointeurs sur fonctions
void button_num_1(bde_csfml_t *csfml_all);
void button_num_2(bde_csfml_t *csfml_all);
void button_num_3(bde_csfml_t *csfml_all);
void button_num_4(bde_csfml_t *csfml_all);
void button_num_5(bde_csfml_t *csfml_all);
void button_num_6(bde_csfml_t *csfml_all);
void button_num_7(bde_csfml_t *csfml_all);
void button_num_8(bde_csfml_t *csfml_all);
void button_num_9(bde_csfml_t *csfml_all);
void button_num_0(bde_csfml_t *csfml_all);
void button_num_check(bde_csfml_t *csfml_all);
void button_num_cancel(bde_csfml_t *csfml_all);
void button_buy(bde_csfml_t *csfml_all);
void button_add_credits(bde_csfml_t *csfml_all);
void button_display_credits(bde_csfml_t *csfml_all);
void button_back(bde_csfml_t *csfml_all);
void button_return(bde_csfml_t *csfml_all);

#endif
