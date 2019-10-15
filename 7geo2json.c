/**
 * 小工具:字符串格式转换
 * <fprintf> 标准格式输出
 * command:./7geo2json < 7.csv > output/7.output 2> output/7.err
*/
#include <stdio.h>

int main()
{
    float latitude;
    float longitude;
    char info[80];
    int started = 0;
    puts("data=[");
    while (scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3) {

        // printf("111{latitude: %f, longitude: %f, info: '%s'},\n", latitude, longitude, info);
        // 输出标准错误,而非标准输出
        if (latitude >90 || latitude < -90){
            fprintf(stderr, "无法识别的latitude:%f\n", latitude);
            return 2;
        } 
        if (longitude > 180 || longitude < -180){
            fprintf(stderr, "无法识别的longitude:%f\n", longitude);
            return 2;
        }

        if (started){
            printf(",\n");
        } else {
            started = 1;
        }
        printf("{latitude: %f, longitude: %f, info: '%s'}", latitude, longitude, info);
    }
    puts("\n]");
    return 0;
}