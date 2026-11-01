#include <stdio.h>
#include "prefix_calculator.h"
#include "crc.h"
#include "uuid.h"

int main(void)
{
    for (int i = START_INT; i <= END_INT; i++)
    {
        char *prefix = prefix_calculator(i);
        char *uuid = uuid4();
        char *crc = crc32(uuid);
        printf("%s-%s %s\n", prefix, uuid, crc);
    }
}
