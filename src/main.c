/*
** EPITECH PROJECT, 2021
** terminal_bde
** File description:
** main.c
*/

#include "../include/bde.h"

#if DATABASE_BDE
const char *c_my_db = "bde";
#else
const char *c_my_db = "BDE_PAIEMENT_TERMINAL";
#endif
const char *c_my_table = "USERS_CREDITS";

void init_nfc(bde_csfml_t *csfml_all)
{
    nfc_init(&csfml_all->nfc.context);
    if (csfml_all->nfc.context == NULL) {
        fprintf(stderr, "Unable to init libnfc (malloc)");
        exit(84);
    }
    if (PRINT_ALL)
        printf("nfc version: %s\n", nfc_version());
    csfml_all->nfc.pnd = nfc_open(csfml_all->nfc.context, NULL);
    if (csfml_all->nfc.pnd == NULL) {
        fprintf(stderr, "Unable to open NFC device.");
        nfc_exit(csfml_all->nfc.context);
        exit(84);
    }
    if (nfc_initiator_init(csfml_all->nfc.pnd) < 0) {
        nfc_perror(csfml_all->nfc.pnd, "nfc_initiator_init");
        nfc_close(csfml_all->nfc.pnd);
        nfc_exit(csfml_all->nfc.context);
        exit(84);
    }
}

int main(int ac, char **av)
{
    bde_csfml_t *csfml_all = malloc(sizeof(bde_csfml_t));
    MYSQL *con = mysql_init(NULL);
    MYSQL_RES *result = NULL;
#if DATABASE_BDE
    char *password = my_getpass();

    if (mysql_real_connect(con, "10.137.215.21", "bde", password, c_my_db, 3306, NULL, 0) == NULL) {
        printf("The authentication failed with the following message:\n");
        printf("%s\n", mysql_error(con));
        return (1);
    }
#else
    if (mysql_real_connect(con, "127.0.0.1", "USERS_DB_OWNER", "1234", c_my_db, 3306, NULL, 0) == NULL) {
        printf("The authentication failed with the following message:\n");
        printf("%s\n", mysql_error(con));
        return (1);
    }
#endif
    if (WITH_READER)
        init_nfc(csfml_all);
    init_all_csfml(csfml_all);
    if (!csfml_all->begin.window || !csfml_all->begin.framebuffer)
        return (1);
    sfWindow_setFramerateLimit((sfWindow *)csfml_all->begin.window, 60);
    sfRenderWindow_setMouseCursorVisible(csfml_all->begin.window, MOUSE_ACTIVE);
    result = get_all_datas_from_table(con);
    csfml_all->sql.con = con;
    csfml_all->sql.res = result;
    if (PRINT_ALL)
        print_all_table(result);
    printf("Paiement bde v1.0 ready.\n");
    while (sfRenderWindow_isOpen(csfml_all->begin.window)) {
        clean_window(&csfml_all->begin, sfWhite);
        big_loop_graphics(csfml_all);
    }
    mysql_free_result(result);
    mysql_close(con);
    nfc_close(csfml_all->nfc.pnd);
    nfc_exit(csfml_all->nfc.context);
    destroy_all(csfml_all);
    return (0);
}
