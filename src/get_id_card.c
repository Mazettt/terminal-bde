/*
** EPITECH PROJECT, 2021
** terminal_bde
** File description:
** get_id_card.c
*/

#include "../include/bde.h"
#include <inttypes.h>

char *print_hex(const uint8_t *pbtData, const size_t szBytes)
{
    size_t  szPos;
    char *buff = malloc(sizeof(char) * 40);

    sprintf(buff, "");
    for (szPos = 0; szPos < szBytes; szPos++) {
        if (PRINT_ALL)
            printf("%02x  ", pbtData[szPos]);
        sprintf(buff, "%s%02x", buff, pbtData[szPos]);
    }
    if (PRINT_ALL)
        printf("\n");
    return (buff);
}

char *get_id_card(bde_csfml_t *csfml_all)
{
    char *res = NULL;
    int res_read_nfc = 0;
    nfc_target nt;
    const uint8_t uiPollNr = 1;
    const uint8_t uiPeriod = 1;
    const nfc_modulation nmModulations[6] = {
        { .nmt = NMT_ISO14443A, .nbr = NBR_106 },
        { .nmt = NMT_ISO14443B, .nbr = NBR_106 },
        { .nmt = NMT_FELICA, .nbr = NBR_212 },
        { .nmt = NMT_FELICA, .nbr = NBR_424 },
        { .nmt = NMT_JEWEL, .nbr = NBR_106 },
        { .nmt = NMT_ISO14443BICLASS, .nbr = NBR_106 },
    };
    const size_t szModulations = 1;

    if (PRINT_ALL) {
        printf("NFC reader: %s opened\n", nfc_device_get_name(csfml_all->nfc.pnd));
        printf("NFC device will poll during %ld ms (%u pollings of %lu ms for %" PRIdPTR " modulations)\n", (unsigned long) uiPollNr * szModulations * uiPeriod * 150, uiPollNr, (unsigned long) uiPeriod * 150, szModulations);
    }
    if ((res_read_nfc = nfc_initiator_poll_target(csfml_all->nfc.pnd, nmModulations, szModulations, uiPollNr, uiPeriod, &nt)) < 0) {
        nfc_perror(csfml_all->nfc.pnd, "nfc_initiator_poll_target");
        return (NULL);
    }
    if (res_read_nfc > 0)
        res = print_hex(nt.nti.nai.abtUid, nt.nti.nai.szUidLen);
    else if (PRINT_ALL)
        printf("No target found.\n");
    return (res);
}
