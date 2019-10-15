/**
 *  百慕大三角的海盗
*/

#include <stdio.h>

void go_sourth_east(int * lat, int * lon)
{
    // 为什么++,--没有起到效果???
    // *lat--;
    // *lon++;
    *lat = *lat - 1;
    *lon = *lon + 1;
}

int main()
{
    int latitude = 32;
    int longitude = -64;
    go_sourth_east(&latitude, &longitude);
    printf("%p\n", &latitude);
    printf("停~当前位置：[%i, %i]\n", latitude, longitude);
    
    return 0;
}
