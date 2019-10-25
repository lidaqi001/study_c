#include "encrypt.h"

void encrypt(char *message)
{
    char c;
    while (*message)
    {
        /* code */
        *message = *message ^ 31;
        message++;
    }
    
}