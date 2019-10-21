/**
 * getopt 获取命令行选项
 * 命令行选项是以'-'开头的命令行参数
 * command: ./10GetOpt -td now arg1 arg2 || ./10GetOpt -d now -t arg1 arg2 || ./10GetOpt -t -d now arg1 arg2
*/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *delivery = "";
    int thick = 0;
    int count = 0;
    char ch;

    // "d:t" 标示接收 -d , -t 两个选项
    // 选项之后的":"(冒号),标示该选项接收一个参数
    while ((ch = getopt(argc, argv, "d:t")) != EOF) {
        switch (ch)
        {
        case 'd':
            // getopt()会用 optarg 变量标记该选项参数
            delivery = optarg;
            break;

        case 't':
            /* code */
            thick = 1;
            break;

        default:
            fprintf(stderr, "Unknow option: '%s'\n", optarg);
            return 1;
        }
    }
    // printf("%i,\n",optind);

    // optind 为getopt()当前处理的选项索引,默认值为1
    argc -= optind;     // 总数量减去索引数量, 得到参数的数量
    argv += optind;     // 指针数组删去索引数据, 得到参数数组

    if (thick) {
        puts("Thick crust.");
    }
    if (delivery[0]) {
        printf("Tobe delivered %s. \n", delivery);
    }
    
    puts("Ingredients:");
    for (count = 0; count < 10; count++) {
        puts(argv[count]);
    }

    return 0;
}