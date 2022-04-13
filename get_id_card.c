#include <stdlib.h>
#include <nfc/nfc.h>

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

char *get_id_card(int argc, const char *argv[])
{
    nfc_context *context;
    nfc_device *pnd;
    nfc_target nt;
    char *res = NULL;

    fprintf(stderr, "1 ");
    nfc_init(&context);
    fprintf(stderr, "2 ");
    if (context == NULL) {
        return (NULL);
    }
    fprintf(stderr, "3 ");
    const char *acLibnfcVersion = nfc_version();
    (void)argc;
    fprintf(stderr, "4 ");
    pnd = nfc_open(context, NULL);
    fprintf(stderr, "5 ");
    if (pnd == NULL) {
        return (NULL);
    }
    fprintf(stderr, "6 ");
    if (nfc_initiator_init(pnd) < 0) {
        nfc_perror(pnd, "nfc_initiator_init");
        return (NULL);
    }
    fprintf(stderr, "7 ");
    const nfc_modulation nmMifare = {
        .nmt = NMT_ISO14443A,
        .nbr = NBR_106,
    };
    fprintf(stderr, "8 ");
    if (nfc_initiator_select_passive_target(pnd, nmMifare, NULL, 0, &nt) > 0) {
        res = print_hex(nt.nti.nai.abtUid, nt.nti.nai.szUidLen);
    }
    fprintf(stderr, "9 ");
    nfc_close(pnd);
    fprintf(stderr, "10 ");
    nfc_exit(context);
    return (res);
}
