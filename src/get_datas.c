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
    MYSQL_RES *res = NULL;

    sprintf(buff, "SELECT * FROM %s", c_my_table);
    if (mysql_query(con, buff) != 0) {
        printf("Query failed  with the following message:\n");
        printf("%s\n", mysql_error(con));
        exit(1);
    }
    res = mysql_store_result(con);
    return (res);
}

int get_nbr_credits(MYSQL *con, char *id_card)
{
    char buff[2048];
    MYSQL_RES *res = NULL;
    MYSQL_ROW row = NULL;
    int cred = 0;

    sprintf(buff, "SELECT CREDITS FROM %s WHERE ID_CARD = \"%s\"", c_my_table, id_card);
    if (mysql_query(con, buff) != 0) {
        printf("Query failed  with the following message:\n");
        printf("%s\n", mysql_error(con));
        return (-1);
    }
    res = mysql_store_result(con);
    row = mysql_fetch_row(res);
    if (row != NULL)
        cred = atoi(row[0]);
    mysql_free_result(res);
    return (cred);
}

int get_total_credits(MYSQL *con, char *id_card)
{
    char buff[2048];
    MYSQL_RES *res = NULL;
    MYSQL_ROW row = NULL;
    int cred = 0;

    sprintf(buff, "SELECT TOTAL_CREDITS FROM %s WHERE ID_CARD = \"%s\"", c_my_table, id_card);
    if (mysql_query(con, buff) != 0) {
        printf("Query failed  with the following message:\n");
        printf("%s\n", mysql_error(con));
        return (-1);
    }
    res = mysql_store_result(con);
    row = mysql_fetch_row(res);
    if (row != NULL)
        cred = atoi(row[0]);
    mysql_free_result(res);
    return (cred);
}

MYSQL_ROW get_row_from_id(MYSQL *con, MYSQL_RES *res_buff, char *id_card)
{
    char buff[2048];
    MYSQL_ROW row = NULL;

    sprintf(buff, "SELECT * FROM %s WHERE ID_CARD = \"%s\"", c_my_table, id_card);
    if (mysql_query(con, buff) != 0) {
        printf("Query failed  with the following message:\n");
        printf("%s\n", mysql_error(con));
        return (NULL);
    }
    res_buff = mysql_store_result(con);
    row = mysql_fetch_row(res_buff);
    return (row);
}

my_datas_t get_datas_one_row(MYSQL_ROW row)
{
    my_datas_t d = {NULL, 0, false, 0};

    if (row == NULL)
        return (d);
    d.id_card = strdup(row[0]);
    d.credits = atoi(row[1]);
    d.admin = atoi(row[2]);
    d.total_credits = atoi(row[3]);
    return (d);
}

my_datas_t get_infos_from_id(MYSQL *con, char *id_card)
{
    MYSQL_RES *res = NULL;
    MYSQL_ROW row = NULL;
    my_datas_t d = {NULL, 0, false, 0};

    row = get_row_from_id(con, res, id_card);
    if (row == NULL)
        return (d);
    d = get_datas_one_row(row);
    mysql_free_result(res);
    return (d);
}
