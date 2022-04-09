/*
** EPITECH PROJECT, 2021
** project
** File description:
** main.c
*/

#include "../include/my.h"
// #include <my_global.h>
#include <mysql/mysql.h>

int main(int ac, char **av)
{
    printf("The MySQL client version is: %s\n", mysql_get_client_info());
}
