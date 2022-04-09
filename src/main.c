/*
** EPITECH PROJECT, 2021
** terminal_bde
** File description:
** main.c
*/

#include "../include/bde.h"

const char *c_my_db = "BDE_PAIEMENT_TERMINAL";
const char *c_my_table = "USERS_CREDITS";

bool is_nbr(char *str)
{
    for (int i = 0; str[i] != '\0' && str[i] != '\n'; ++i)
        if (str[i] < '0' || str[i] > '9')
            return (false);
    return (true);
}

bool check_if_admin(MYSQL *con, char *id_card)
{
    MYSQL_ROW row = get_row_from_id(con, id_card);
    my_datas_t d = {NULL, 0, false};

    if (row == NULL) {
        printf("Card not found.\n");
        return (false);
    }
    d = get_datas_one_row(row);
    if (d.admin)
        return (true);
    else {
        printf("You are not admin\n");
        return (false);
    }
}

void process_add_credits(MYSQL *con, char *id_card, int current_nbr_credits)
{
    int cred = 0;
    char *line = NULL;
    size_t s;

    printf("Present your admin card: ");
    getline(&line, &s, stdin);
    line[strlen(line) - 1] = '\0';
    if (!check_if_admin(con, line))
        return;
    for (bool check = true; check;) {
        printf("How many do you want to add ? ");
        getline(&line, &s, stdin);
        if (!is_nbr(line))
            printf("Please enter an number\n");
        else
            check = false;
    }
    cred = atoi(line);
    modify_one_row(con, id_card, current_nbr_credits + cred);
    printf("You have been credited by %d credits\n", cred);
    free(line);
}

void process_not_in_database(MYSQL *con, char *id_card)
{
    char *line = NULL;
    size_t s;

    printf("You're not in database.\n");
    add_data_to_table(con, (my_datas_t){id_card, 0, false});
    for (bool check = true; check;) {
        printf("Do you want to add credits ? [y/n] ");
        getline(&line, &s, stdin);
        if (strlen(line) > 2)
            printf("Please answer y/n\n");
        else if (line[0] == 'y') {
            process_add_credits(con, id_card, 0);
            check = false;
        } else if (line[0] == 'n')
            check = false;
        else
            printf("Please answer y/n\n");
    }
    free(line);
}

void big_loop(MYSQL *con)
{
    char *line = NULL;
    size_t s;
    my_datas_t d = {NULL, 0, false};
    MYSQL_ROW row = NULL;

    printf("Id card: ");
    getline(&line, &s, stdin);
    line[strlen(line) - 1] = '\0';
    if ((row = get_row_from_id(con, line)) == NULL) {
        process_not_in_database(con, line);
        return;
    }
    d = get_datas_one_row(row);
    print_datas(d);
    free(line);
}

int main(int ac, char **av)
{
    MYSQL *con;
    MYSQL_RES *result = NULL;
    char buff[2048];
    my_datas_t d = {.id_card = "Martin", .credits = 20, .admin = true};

    con = mysql_init(NULL);
    if (mysql_real_connect(con, "127.0.0.1", "USERS_DB_OWNER", "1234", c_my_db, 3306, NULL, 0) == NULL) {
        printf("The authentication failed with the following message:\n");
        printf("%s\n", mysql_error(con));
        exit(1);
    }
    result = get_all_datas_from_table(con);
    print_all_table(result);

    while (true) {
        big_loop(con);
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
    mysql_free_result(result);
    mysql_close(con);
}
