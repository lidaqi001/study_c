/**
 * 函数可变参数
*/

#include <stdio.h>
#include <stdarg.h>

enum drink {
    M,
    F,
    Z
};

double price(enum drink d) 
{
    switch (d)
    {
    case M:
        return 6.59;
    
    case F:
        return 5.31;

    case Z:
        return 4.82;

    default:
        break;
    }
}

double total(int args, ...)
{
    float total = 0;
    //必须引入标准库  #include <stdarg.h>
    //va_list 用来保存传给函数的其他参数。
    va_list ap;
    //说明可变参数从哪里开始。
    //需要把最后一个普通参数的名字告诉C，在这个例子中就是 args 变量
    va_start(ap, args);
    int i;
    for (size_t i = 0; i < args; i++)
    {
        //参数现在全保存在 va_list 中，可以用 va_arg 读取它们。 
        //va_arg 接收两个值： va_list 和要读取参数的类型。
        enum drink d = va_arg(ap, enum drink);
        printf("Price:%f\n", price(d));
        total += price(d);
    }
    //最后……销毁va_list。
    //当读完了所有参数，要用 va_end 宏告诉C你做完了
    va_end(ap);
    
    return total;
}

int main() 
{
    printf("total:%f", total(3, F, M, Z));

    return 0;
}