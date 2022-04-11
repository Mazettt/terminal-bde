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
    MYSQL_RES *res = NULL;
    MYSQL_ROW row = NULL;
    my_datas_t d = {NULL, 0, false};

    row = get_row_from_id(con, res, id_card);
    if (row == NULL) {
        printf("Card not found.\n");
        free(row);
        mysql_free_result(res);
        return (false);
    }
    d = get_datas_one_row(row);
    if (d.admin) {
        mysql_free_result(res);
        return (true);
    } else {
        printf("You are not admin\n");
        mysql_free_result(res);
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

bool big_loop(MYSQL *con)
{
    char *line = NULL;
    size_t s;
    my_datas_t d = {NULL, 0, false};
    MYSQL_RES *res = NULL;
    MYSQL_ROW row = NULL;

    printf("Id card: ");
    if (getline(&line, &s, stdin) == -1) {
        free(row);
        return (false);
    }
    line[strlen(line) - 1] = '\0';
    if ((row = get_row_from_id(con, res, line)) == NULL) {
        process_not_in_database(con, line);
        free(row);
        mysql_free_result(res);
        return (true);
    }
    d = get_datas_one_row(row);
    print_datas(d);
    free(line);
    mysql_free_result(res);
    return (true);
}

int main(int ac, char **av)
{
    MYSQL *con;
    MYSQL_RES *result = NULL;
    bde_csfml_t *csfml_all = malloc(sizeof(bde_csfml_t));

    init_all_csfml(csfml_all);
    if (!csfml_all->begin.window || !csfml_all->begin.framebuffer)
        return (1);
    sfWindow_setFramerateLimit((sfWindow *)csfml_all->begin.window, 60);
    csfml_all->begin.fps.clock = sfClock_create();
    con = mysql_init(NULL);
    if (mysql_real_connect(con, "127.0.0.1", "USERS_DB_OWNER", "1234", c_my_db, 3306, NULL, 0) == NULL) {
        printf("The authentication failed with the following message:\n");
        printf("%s\n", mysql_error(con));
        return (1);
    }
    result = get_all_datas_from_table(con);
    print_all_table(result);
    csfml_all->sql.con = con;
    csfml_all->sql.res = result;
    csfml_all->current_d = (my_datas_t){NULL, 0, false};
    csfml_all->text_numpad = malloc(sizeof(char) * 11);
    csfml_all->text_numpad[0] = '\0';
    csfml_all->clock_screens = sfClock_create();
    while (sfRenderWindow_isOpen(csfml_all->begin.window)) {
        clean_window(&csfml_all->begin, sfWhite);
        big_loop_graphics(csfml_all);
    }
    destroy_all(csfml_all);
    mysql_free_result(result);
    mysql_close(con);
    return (0);
}
