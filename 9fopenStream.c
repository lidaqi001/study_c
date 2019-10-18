/**
 * 创建数据流,读写
 * 获取参数
 * command:./9fopenStream KFC file1 UFO file2 fileElse
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// argc 参数数量(包含脚本自身命令), argv 参数指针数组
int main(int argc, char * argv[])
{
    char line[80];

    if (argc != 6) {
        fprintf(stderr, "You need to give 5 arguments\n");
        return 1;
    }

    // 获取参数
    char path1[20];
    char path2[20];
    char path3[20];
    sprintf(path1, "output/%s", argv[2]);
    sprintf(path2, "output/%s", argv[4]);
    sprintf(path3, "output/%s", argv[5]);

    FILE *in;
    if (!(in = fopen("9.csv", "r"))) {
        fprintf(stderr, "open file error.\n");
        return 1;
    }

    FILE *file1 = fopen(path1, "w");
    FILE *file2 = fopen(path2, "w");
    FILE *file3 = fopen(path3, "w");

    while (fscanf(in, "%79[^\n]\n", line) == 1)
    {
        if (strstr(line, argv[1]))
            fprintf(file1, "%s\n", line);
        else if (strstr(line, argv[3]))
            fprintf(file2, "%s\n", line);
        else 
            fprintf(file3, "%s\n", line);
    }

    fclose(file1);
    fclose(file2);
    fclose(file3);
    
    return 0;
    
}
