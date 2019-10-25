/**
 * 动态库
*/

#include "checkSum.h"

int checksum(char *message)
{
    int c = 0;
    while (*message) {
        c += c ^ (int)(*message);
        message++;
    }
    return c;
}
