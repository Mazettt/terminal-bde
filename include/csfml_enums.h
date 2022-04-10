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
    button_num_check, button_num_cancel, button_add_credits, button_buy, button_display_credits}

enum size_window {
    WIDTH = 500,
    HEIGHT = 350
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
    SP_ADD_CREDITS,
    SP_BUY,
    SP_DISPLAY_CREDITS,
    NBR_SP
};

enum screens {
    SC_MENU,
    SC_BUY,
    SC_DISPLAY_CREDITS,
    SC_ADD_CREDITS,
    NBR_SC
};

#endif
