/*
** EPITECH PROJECT, 2021
** terminal_bde
** File description:
** old.c
*/

// int main(int ac, char **av)
// {
//     printf("The MySQL client version is: %s\n", mysql_get_client_info());
//     MYSQL *con;
//     con = mysql_init(NULL);
//     char login[] = "John";
//     char password[] = "1234";
//     char sql_statement[2048];

//     if (mysql_real_connect(con, "127.0.0.1", "USERS_DB_OWNER", "1234", "USERS_DB", 3306, NULL, 0) == NULL) {
//         printf("The authentication failed with the following message:\n");
//         printf("%s\n", mysql_error(con));
//         exit(1);
//     }
//     printf("Connection with database established\n");

//     // Construct the SQL statement
//     sprintf(sql_statement, "INSERT INTO USERS_TBL(LOGIN, PASSWORD) VALUES('%s', '%s')", login, password);
//     if(mysql_query(con, sql_statement) != 0) {
//         printf("Query failed  with the following message:\n");
//         printf("%s\n", mysql_error(con));
//         exit(1);
//     } else {
//         printf("The auto-generated ID is: %ld\n", (long) mysql_insert_id(con));
//     }

//     printf("User %s inserted into the database\n", login);

//     mysql_close(con);
// }



// terminal version


// bool is_nbr(char *str)
// {
//     for (int i = 0; str[i] != '\0' && str[i] != '\n'; ++i)
//         if (str[i] < '0' || str[i] > '9')
//             return (false);
//     return (true);
// }

// bool check_if_admin(MYSQL *con, char *id_card)
// {
//     MYSQL_RES *res = NULL;
//     MYSQL_ROW row = NULL;
//     my_datas_t d = {NULL, 0, false};

//     row = get_row_from_id(con, res, id_card);
//     if (row == NULL) {
//         printf("Card not found.\n");
//         free(row);
//         mysql_free_result(res);
//         return (false);
//     }
//     d = get_datas_one_row(row);
//     if (d.admin) {
//         mysql_free_result(res);
//         return (true);
//     } else {
//         printf("You are not admin\n");
//         mysql_free_result(res);
//         return (false);
//     }
// }

// void process_add_credits(MYSQL *con, char *id_card, int current_nbr_credits)
// {
//     int cred = 0;
//     char *line = NULL;
//     size_t s;

//     printf("Present your admin card: ");
//     getline(&line, &s, stdin);
//     line[strlen(line) - 1] = '\0';
//     if (!check_if_admin(con, line))
//         return;
//     for (bool check = true; check;) {
//         printf("How many do you want to add ? ");
//         getline(&line, &s, stdin);
//         if (!is_nbr(line))
//             printf("Please enter an number\n");
//         else
//             check = false;
//     }
//     cred = atoi(line);
//     modify_one_row(con, id_card, current_nbr_credits + cred);
//     printf("You have been credited by %d credits\n", cred);
//     free(line);
// }

// void process_not_in_database(MYSQL *con, char *id_card)
// {
//     char *line = NULL;
//     size_t s;

//     printf("You're not in database.\n");
//     add_data_to_table(con, (my_datas_t){id_card, 0, false});
//     for (bool check = true; check;) {
//         printf("Do you want to add credits ? [y/n] ");
//         getline(&line, &s, stdin);
//         if (strlen(line) > 2)
//             printf("Please answer y/n\n");
//         else if (line[0] == 'y') {
//             process_add_credits(con, id_card, 0);
//             check = false;
//         } else if (line[0] == 'n')
//             check = false;
//         else
//             printf("Please answer y/n\n");
//     }
//     free(line);
// }

// bool big_loop(MYSQL *con)
// {
//     char *line = NULL;
//     size_t s;
//     my_datas_t d = {NULL, 0, false};
//     MYSQL_RES *res = NULL;
//     MYSQL_ROW row = NULL;

//     printf("Id card: ");
//     if (getline(&line, &s, stdin) == -1) {
//         free(row);
//         return (false);
//     }
//     line[strlen(line) - 1] = '\0';
//     if ((row = get_row_from_id(con, res, line)) == NULL) {
//         process_not_in_database(con, line);
//         free(row);
//         mysql_free_result(res);
//         return (true);
//     }
//     d = get_datas_one_row(row);
//     print_datas(d);
//     free(line);
//     mysql_free_result(res);
//     return (true);
// }