/*
** EPITECH PROJECT, 2021
** terminal_bde
** File description:
** msql_includes.h
*/

#ifndef MYSQL_INCLUDES_H
    #define MYSQL_INCLUDES_H

    #include <mysql/mysql.h>
    #include <signal.h>
    #include <stdbool.h>

typedef struct {
    char *id_card;
    int credits;
    bool admin;
} my_datas_t;

typedef struct {
    MYSQL *con;
    MYSQL_RES *res;
    MYSQL_ROW row;
} all_mysql_t;

// get datas
long get_number_of_rows(MYSQL_RES *result);
MYSQL_RES *get_all_datas_from_table(MYSQL *con);
my_datas_t get_datas_one_row(MYSQL_ROW row);
MYSQL_ROW get_row_from_id(MYSQL *con, MYSQL_RES *res_buff, char *id_card);

// utils
void print_all_table(MYSQL_RES *result);
void print_datas(my_datas_t d);

// modify database
void add_data_to_table(MYSQL *con, my_datas_t d);
void modify_one_row(MYSQL *con, char *id_card, int credits);

// free
void free_row(MYSQL_ROW row);

#endif