#include <stdio.h>
#include <string.h>
#include "crc.h"

#define CRC32_POLY 0xEDB88320u

uint32_t crc32_compute(const void *data, size_t len)
{
    const unsigned char *bytes = data;
    uint32_t crc = 0xFFFFFFFFu;

    for (size_t i = 0; i < len; i++)
    {
        crc ^= bytes[i];
        for (int bit = 0; bit < 8; bit++)
        {
            if (crc & 1)
                crc = (crc >> 1) ^ CRC32_POLY;
            else
                crc >>= 1;
        }
    }
    return ~crc;
}

char *crc32(const char *input)
{
    static char crc_result[9]; // 8 characters for CRC32 + null terminator
    snprintf(crc_result, sizeof(crc_result), "%08X",
             (unsigned)crc32_compute(input, strlen(input)));
    return crc_result;
}