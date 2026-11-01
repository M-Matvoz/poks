#include <stdio.h>
#include "prefix_calculator.h"

char *prefix_calculator(int num)
{
    static char prefix[PREFIX_LENGTH + 1];
    // Fill the prefix array based on the number
    snprintf(prefix, PREFIX_LENGTH + 1, "%0*d", PREFIX_LENGTH, num);
    return prefix;
}
