/*
** EPITECH PROJECT, 2021
** terminal_bde
** File description:
** main.c
*/

#include "../include/bde.h"

const char *c_my_db = "BDE_PAIEMENT_TERMINAL";
const char *c_my_table = "USERS_CREDITS";

int main(int ac, char **av)
{
    MYSQL *con;
    MYSQL_RES *result;
    char buff[2048];
    my_datas_t d = {.id_card = "Martin", .credits = 20, .admin = true};

    con = mysql_init(NULL);
    if (mysql_real_connect(con, "127.0.0.1", "USERS_DB_OWNER", "1234", c_my_db, 3306, NULL, 0) == NULL) {
        printf("The authentication failed with the following message:\n");
        printf("%s\n", mysql_error(con));
        exit(1);
    }

    // add_data_to_table(con, d);

    result = get_all_datas_from_table(con);
    print_all_table(result);
    modify_one_row(con, "Martin", 30);
    result = get_all_datas_from_table(con);
    print_all_table(result);
    modify_one_row(con, "Martin", 31);
    result = get_all_datas_from_table(con);
    print_all_table(result);
    // printf("Number of rows: %ld\n\n", get_number_of_rows(result));
    mysql_close(con);
}
