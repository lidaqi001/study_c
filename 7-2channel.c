/**
 * 管道连接两个工具
 * command:(./7-2channel | ./7geo2json) < 7.csv > output/7.output 2> output/7.err
*/
#include <stdio.h>

int main()
{
    float latitude;
    float longitude;
    char info[80];
    while (scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3) {

        // printf("{latitude: %f, longitude: %f, info: '%s'},\n", latitude, longitude, info);
        if (latitude > 26 && latitude < 34){
            if (longitude > -76 && longitude < -64){
                fprintf(stdout, "%f,%f,%s\n", latitude, longitude, info);
            }
        }
    
    }
    return 0;
}