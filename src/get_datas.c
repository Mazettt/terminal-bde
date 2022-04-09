/*
** EPITECH PROJECT, 2021
** terminal_bde
** File description:
** get_datas.c
*/

#include "../include/bde.h"

extern const char *c_my_db;
extern const char *c_my_table;

long get_number_of_rows(MYSQL_RES *result)
{
    return ((long)mysql_num_rows(result));
}

MYSQL_RES *get_all_datas_from_table(MYSQL *con)
{
    char buff[2048];
    MYSQL_RES *res;

    sprintf(buff, "SELECT ID_CARD, CREDITS, ADMIN FROM %s", c_my_table);
    if (mysql_query(con, buff) != 0) {
        printf("Query failed  with the following message:\n");
        printf("%s\n", mysql_error(con));
        exit(1);
    }
    res = mysql_store_result(con);
    return (res);
}

my_datas_t get_datas_one_row(MYSQL_ROW row)
{
    my_datas_t d = {NULL, 0, false};

    d.id_card = row[0];
    d.credits = atoi(row[1]);
    d.admin = atoi(row[2]);
    return (d);
}
