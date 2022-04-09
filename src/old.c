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
