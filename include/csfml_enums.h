/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** myrpg.h
*/

#ifndef MY_RPG_H
    #define MY_RPG_H

    #include "my.h"
    #include "csfml_includes.h"
    #define RADIAN(x) x * 3.14159265359 / 180
    #define FUNCTIONS_BUTTONS {button_num_0, button_num_1, button_num_2, button_num_3, \
    button_num_4, button_num_5, button_num_6, button_num_7, button_num_8, button_num_9, \
    button_num_check, button_num_cancel, button_back, button_return, button_add_credits, button_buy, nothing, nothing, nothing, nothing}
    #define EXT_INTS extern int screen_menu[];  \
    extern int screen_buy[];    \
    extern int screen_add_credits[];    \
    extern int screen_scan[];   \
    extern int screen_scan_admin[]; \
    extern int screen_added_in_db[];    \
    extern int screen_debited[];    \
    extern int screen_no_enouth[];  \
    extern int screen_error[];  \

enum size_window {
    WIDTH = 1280,
    HEIGHT = 720
};

enum sprites {
    SP_0,
    SP_1,
    SP_2,
    SP_3,
    SP_4,
    SP_5,
    SP_6,
    SP_7,
    SP_8,
    SP_9,
    SP_CHECK,
    SP_CANCEL,
    SP_BACK,
    SP_RETURN,
    SP_ADD_CREDITS,
    SP_BUY,
    SP_SCAN,
    SP_SCAN_ADMIN,
    SP_ADDED_IN_DB,
    SP_NO_ENOUTH,
    SP_ERROR,
    NBR_SP
};

enum screens {
    SC_SCAN,
    SC_SCAN_ADMIN,
    SC_MENU,
    SC_BUY,
    SC_ADD_CREDITS,
    SC_ADDED_TO_DB,
    SC_DEBITED,
    SC_NO_ENOUTH,
    SC_ERROR,
    NBR_SC
};

#endif
