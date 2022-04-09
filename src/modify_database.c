/*
** EPITECH PROJECT, 2021
** terminal_bde
** File description:
** modify_database.c
*/

#include "../include/bde.h"

extern const char *c_my_db;
extern const char *c_my_table;

void add_data_to_table(MYSQL *con, my_datas_t d)
{
    char buff[2048];

    sprintf(buff, "INSERT INTO %s(ID_CARD, CREDITS, ADMIN) VALUES('%s', '%d', '%d')", c_my_table, d.id_card, d.credits, d.admin);
    if(mysql_query(con, buff) != 0) {
        printf("Query failed  with the following message:\n");
        printf("%s\n", mysql_error(con));
        exit(1);
    }
}

void modify_one_row(MYSQL *con, char *id_card, int credits)
{
    char buff[2048];

    sprintf(buff, "UPDATE %s SET CREDITS = %d WHERE ID_CARD = \"%s\"", c_my_table, credits, id_card);
    if(mysql_query(con, buff) != 0) {
        printf("Query failed  with the following message:\n");
        printf("%s\n", mysql_error(con));
        exit(1);
    }
}
