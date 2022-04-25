/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** struct.h
*/

#ifndef STRUCT_H
    #define STRUCT_H

    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <sys/stat.h>
    #include <stdbool.h>
    #include <nfc/nfc.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <stdio.h>
    #include <math.h>

typedef struct {
    sfVector2f pos;
    sfVector2f scale;
    sfIntRect rect;
    bool clickable;
    bool active;
    bool change_sprite_on_mouse;
} init_sprite_t;

typedef struct {
    char *str;
    int size;
    sfVector2f pos;
    sfColor color;
} init_text_t;

typedef struct {
    sfClock *clock;
    float timer;
} fps_t;

typedef struct {
    sfRenderWindow *window;
    sfUint8 *framebuffer;
    sfTexture *texture;
    sfSprite *sprite;
    fps_t fps;
} beginning_t;

typedef struct {
    bool left;
    bool left_released;
    bool right;
    sfVector2i pos;
} mouse_t;

typedef struct {
    bool escape;
    mouse_t mouse;
} events_t;

// typedef struct {
//     bool active;
//     float view_zoom;
//     sfVector2f view_pos;
// } screen_t;

typedef struct {
    bool active;
    bool clickable;
    bool change_sprite_on_mouse;
    sfVector2f pos;
    sfIntRect rect;
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *c_anim;
    sfClock *c_attack;
} spritesheet_t;

typedef struct {
    MYSQL *con;
    MYSQL_RES *res;
} my_sql_t;

typedef struct {
    nfc_context *context;
    nfc_device *pnd;
} nfc_poll_t;

typedef struct {
    beginning_t begin;
    events_t all_events;
    spritesheet_t *spritesheet;
    my_sql_t sql;
    nfc_poll_t nfc;
    bool *screens;
    sfClock *clock_screens;
    char *text_numpad;
    my_datas_t current_d;
    char *current_admin_card;
} bde_csfml_t;

#endif
