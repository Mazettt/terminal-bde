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
    nfc_device *pnd;
    nfc_target nt;
    nfc_context *context;
    char *res = NULL;

    nfc_init(&context);
    if (context == NULL) {
        return (NULL);
    }
    const char *acLibnfcVersion = nfc_version();
    (void)argc;
    pnd = nfc_open(context, NULL);
    if (pnd == NULL) {
        return (NULL);
    }
    if (nfc_initiator_init(pnd) < 0) {
        fprintf(stderr, "my err\n");
        nfc_perror(pnd, "nfc_initiator_init");
        return (NULL);
    }
    const nfc_modulation nmMifare = {
        .nmt = NMT_ISO14443A,
        .nbr = NBR_106,
    };
    if (nfc_initiator_select_passive_target(pnd, nmMifare, NULL, 0, &nt) > 0) {
        res = print_hex(nt.nti.nai.abtUid, nt.nti.nai.szUidLen);
    }
    nfc_close(pnd);
    nfc_exit(context);
    return (res);
}
