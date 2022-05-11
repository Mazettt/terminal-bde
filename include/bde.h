/*
** EPITECH PROJECT, 2021
** terminal_bde
** File description:
** bde.h
*/

#ifndef BDE_H
    #define BDE_H

    #include "my.h"
    #include "mysql_includes.h"
    #include "csfml_structs.h"
    #include "csfml_includes.h"
    #include "csfml_enums.h"
    #include <string.h>
    #define RPI 0
#if RPI
    #define PRINT_ALL 0
    #define MOUSE_ACTIVE 0
    #define WITH_READER 1
    #define DATABASE_BDE 1
#else
    #define PRINT_ALL 0
    #define MOUSE_ACTIVE 1
    #define WITH_READER 0
    #define DATABASE_BDE 0
#endif
    #define TYPE_ADDED_IN_DB "Added in db"
    #define TYPE_BUY "Bought product"
    #define TYPE_ADD_CREDITS "Added credits"

char *get_id_card(bde_csfml_t *csfml_all);
char *my_getpass(void);

#endif
