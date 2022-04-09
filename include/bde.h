/*
** EPITECH PROJECT, 2021
** terminal_bde
** File description:
** bde.h
*/

#ifndef BDE_H
    #define BDE_H

    #include <mysql/mysql.h>
    #include "my.h"

typedef struct {
    char *id_card;
    int credits;
    bool admin;
} my_datas_t;

// get datas
long get_number_of_rows(MYSQL_RES *result);
MYSQL_RES *get_all_datas_from_table(MYSQL *con);
my_datas_t get_datas_one_row(MYSQL_ROW row);

// utils
void print_all_table(MYSQL_RES *result);

// modify database
void add_data_to_table(MYSQL *con, my_datas_t d);
void modify_one_row(MYSQL *con, char *id_card, int credits);

#endif
