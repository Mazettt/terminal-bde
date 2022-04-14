/*
** EPITECH PROJECT, 2021
** terminal_bde
** File description:
** main.c
*/

#include "../include/bde.h"

const char *c_my_db = "BDE_PAIEMENT_TERMINAL";
const char *c_my_table = "USERS_CREDITS";

void init_nfc(bde_csfml_t *csfml_all)
{
    nfc_init(&csfml_all->nfc.context);
    if (csfml_all->nfc.context == NULL) {
        fprintf(stderr, "Unable to init libnfc (malloc)");
        exit(84);
    }
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
    MYSQL *con = NULL;
    MYSQL_RES *result = NULL;

    init_nfc(csfml_all);
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
    if (PRINT_ALL)
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
    mysql_free_result(result);
    mysql_close(con);
    nfc_close(csfml_all->nfc.pnd);
    nfc_exit(csfml_all->nfc.context);
    destroy_all(csfml_all);
    return (0);
}
