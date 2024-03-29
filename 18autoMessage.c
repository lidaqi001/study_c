
#include <stdio.h>

enum response_type {
    DUMP, SECOND_CHANCE, MARRIAGE
};
typedef struct {
    char *name;
    enum response_type type;
} response;

void dump(response r)
{
    printf("Dear %s,\n", r.name);
    puts("Unfortunately your last date contacted us to");
    puts("say that they will not be seeing you again");
}
void second_chance(response r)
{
    printf("Dear %s,\n", r.name);
    puts("Good news: your last date has asked us to");
    puts("arrange another meeting. Please call ASAP.");
}
void marriage(response r)
{
    printf("Dear %s,\n", r.name);
    puts("Congratulations! Your last date has contacted");
    puts("us with a proposal of marriage.");
}

int main()
{
    response r[] = {
         {"Luis", SECOND_CHANCE},{"Mike", DUMP},
        {"Matt", SECOND_CHANCE}, {"William", MARRIAGE}
    };
    int i;
    void (*replies[])(response) = {dump, second_chance, marriage};
    for (size_t i = 0; i < 4; i++)
    {
        /* 处理方法一 : switch */
        // switch (r[i].type)
        // {
        // case DUMP:
        //     dump(r[i]);
        //     break;

        // case SECOND_CHANCE:
        //     second_chance(r[i]);
        //     break;
        
        // default:
        //     marriage(r[i]);
        // }

        /* 处理方法二 : 函数指针数组 */
        (replies[r[i].type])(r[i]);
    }
    return 0;
}