/*
** EPITECH PROJECT, 2021
** terminal_bde
** File description:
** modify_database.c
*/

#include "../include/bde.h"

extern const char *c_my_db;
extern const char *c_my_table;
const char *c_table_history = "HISTORIQUE";

bool add_history(MYSQL *con, char *id_card, char *type_operation, int credits_modified, unsigned int credits_before, char *id_admin)
{
    char buff[2048];

    if (id_admin != NULL)
        sprintf(buff, "INSERT INTO %s(ID_CARD, TYPE_OPERATION, CREDITS_MODIFIED, CREDITS_BEFORE, ID_ADMIN) VALUES('%s', '%s', '%d', '%d', '%s')", c_table_history, id_card, type_operation, credits_modified, credits_before, id_admin);
    else
        sprintf(buff, "INSERT INTO %s(ID_CARD, TYPE_OPERATION, CREDITS_MODIFIED, CREDITS_BEFORE) VALUES('%s', '%s', '%d', '%d')", c_table_history, id_card, type_operation, credits_modified, credits_before);

    if(mysql_query(con, buff) != 0) {
        printf("Query failed  with the following message:\n");
        printf("%s\n", mysql_error(con));
        return (false);
    }
    return (true);
}

bool add_data_to_table(MYSQL *con, my_datas_t d)
{
    char buff[2048];

    sprintf(buff, "INSERT INTO %s(ID_CARD, CREDITS, ADMIN, TOTAL_CREDITS) VALUES('%s', '%d', '%d', '%d')", c_my_table, d.id_card, d.credits, d.admin, d.total_credits);
    if(mysql_query(con, buff) != 0) {
        printf("Query failed  with the following message:\n");
        printf("%s\n", mysql_error(con));
        return (false);
    }
    return (true);
}

bool modify_one_row(MYSQL *con, char *id_card, int credits, int total_credits)
{
    char buff[2048];

    sprintf(buff, "UPDATE %s SET CREDITS = %d, TOTAL_CREDITS = %d WHERE ID_CARD = \"%s\"", c_my_table, credits, total_credits, id_card);
    if(mysql_query(con, buff) != 0) {
        printf("Query failed  with the following message:\n");
        printf("%s\n", mysql_error(con));
        return (false);
    }
    return (true);
}
