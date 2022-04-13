/*
** EPITECH PROJECT, 2021
** terminal_bde
** File description:
** get_id_card.c
*/

#include "../include/bde.h"

char *print_hex(const uint8_t *pbtData, const size_t szBytes)
{
    size_t  szPos;
    char *buff = malloc(sizeof(char) * 40);

    sprintf(buff, "");
    for (szPos = 0; szPos < szBytes; szPos++) {
        printf("%02x  ", pbtData[szPos]);
        sprintf(buff, "%s%02x", buff, pbtData[szPos]);
    }
    printf("\n");
    return (buff);
}

char *get_id_card(bde_csfml_t *csfml_all)
{
    char *res = NULL;
    nfc_target nt;
    const nfc_modulation nmMifare = {
        .nmt = NMT_ISO14443A,
        .nbr = NBR_106,
    };

    if (nfc_initiator_select_passive_target(csfml_all->nfc.pnd, nmMifare, NULL, 0, &nt) > 0) {
        res = print_hex(nt.nti.nai.abtUid, nt.nti.nai.szUidLen);
    }
    return (res);
}
