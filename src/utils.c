/*
** EPITECH PROJECT, 2021
** terminal_bde
** File description:
** utils.c
*/

#include "../include/bde.h"

extern const char *c_my_db;
extern const char *c_my_table;

void print_datas(my_datas_t d)
{
    printf("ID_CARD: %s\n", d.id_card);
    printf("CREDITS: %d\n", d.credits);
    printf("ADMIN: %d\n", d.admin);
    printf("\n");
}

void print_all_table(MYSQL_RES *result)
{
    MYSQL_ROW row = NULL;
    my_datas_t d = {NULL, 0, false};

    while((row = mysql_fetch_row(result)) != NULL) {
        d = get_datas_one_row(row);
        printf("ID_CARD: %s\n", d.id_card);
        printf("CREDITS: %d\n", d.credits);
        printf("ADMIN: %d\n", d.admin);
        printf("\n");
    }
}
