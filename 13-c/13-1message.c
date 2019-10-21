/**
 * 多源文件编译
 * command: 
 *          gcc -c *.c && gcc *.o -o encrypt   ||    make encrypt
*/


#include <stdio.h>
#include "13-3encrypt.h"

int main()
{
    char msg[80];
    while (fgets(msg, 80, stdin)) {
        encrypt(msg);
        printf("%s", msg);
    }
    return 0;
}