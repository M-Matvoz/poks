#include <windows.h>
#include <wincrypt.h>
#include <stdio.h>
#include "uuid.h"

static int random_bytes(unsigned char *buf, DWORD len)
{
    HCRYPTPROV prov;
    if (!CryptAcquireContext(&prov, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT))
        return 0;
    BOOL ok = CryptGenRandom(prov, len, buf);
    CryptReleaseContext(prov, 0);
    return ok;
}

char *uuid4(void)
{
    static char out[37];
    unsigned char b[16];
    if (!random_bytes(b, sizeof(b)))
        return NULL;
    b[6] = (b[6] & 0x0F) | 0x40;
    b[8] = (b[8] & 0x3F) | 0x80;
    snprintf(out, sizeof(out),
             "%02x%02x%02x%02x-%02x%02x-%02x%02x-%02x%02x-%02x%02x%02x%02x%02x%02x",
             b[0], b[1], b[2], b[3], b[4], b[5], b[6], b[7],
             b[8], b[9], b[10], b[11], b[12], b[13], b[14], b[15]);
    return out;
}