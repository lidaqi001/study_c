/**
 * 不同平台上数据类型大小不同,下面这个程序会获取各个数据类型的最大最小值,占用字节数
*/

#include <stdio.h>
// 含有表示整型(比如int和char) 大小的值.
#include <limits.h>
// 含有表示float和都变了累心各大小的值.
#include <float.h>

int main()
{
    printf("The value of INT_MAX is %i\n", INT_MAX);
    printf("The value of INT_MIN is %i\n", INT_MIN);
    printf("An int takes %li bytes\n", sizeof(int));
    puts("-----");

    printf("The value of FLT_MAX is %f\n", FLT_MAX);
    printf("The value of FLT_MIN is %.50f\n", FLT_MIN);
    printf("A float takes %li bytes\n", sizeof(float));
    puts("-----");
    
    printf("The value of CHAR_MAX is %i\n", CHAR_MAX);
    printf("The value of CHAR_MIN is %i\n", CHAR_MIN);
    printf("A char takes %li bytes\n", sizeof(char));
    puts("-----");
    
    printf("The value of DBL_MAX is %f\n", DBL_MAX);
    printf("The value of DBL_MIN is %.50f\n", DBL_MIN);
    printf("A double takes %li bytes\n", sizeof(double));
    puts("-----");
    
    printf("The value of SHRT_MAX is %i\n", SHRT_MAX);
    printf("The value of SHRT_MIN is %i\n", SHRT_MIN);
    printf("A short takes %li bytes\n", sizeof(short));
    puts("-----");
    
    printf("The value of LONG_MAX is %li\n", LONG_MAX);
    printf("The value of LONG_MIN is %li\n", LONG_MIN);
    printf("A long takes %li bytes\n", sizeof(long));
    return 0;
}