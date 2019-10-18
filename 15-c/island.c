/**
 * 灵活的数据
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char *name;
    char *opens;
    char *closes;
    struct island *next;
    
} island;

void display(island *start)
{
    island *i = start;

    for(; i!=NULL; i=i->next) {
        printf("Name: %s\n open: %s-%s \n", i->name, i->opens, i->closes);
    }
}

island* create(char *name)
{
    // 创建动态数据
    island *i = malloc(sizeof(island));
    // 将变量name拷贝到堆上;因为是局部变量,如果有第二次赋值,就会覆盖掉
    i->name = strdup(name);
    i->opens = "09:00";
    i->closes = "17:00";
    i->next = NULL;
    return i;
}

// 释放存储空间
void release(island *start)
{
    island *i = start;
    island *next = NULL;
    for (; i != NULL; i = next) {
        next = i->next;
        free(i->name);
        free(i);
    }
}
int main()
{
    island *start = NULL;
    island *i = NULL;
    island *next = NULL;
    char name[80];
    for(; fgets(name, 80, stdin) != NULL; i = next) {
        // 在外部复制变量到堆 == 在函数中复制变量到堆
        // next = create(strdup(name));
        next = create(name);
        if (start == NULL)
            start = next;
        if (i != NULL)
            i->next = next;
    }
    display(start);
    release(start);

    return 0;

    // char name[80];
    // fgets(name, 80, stdin);
    // island *island0 = create(name);
    // fgets(name, 80, stdin);
    // island *island1 = create(name);
    // // island0->next = &island1;
    // display(&island0);
    // return 0;

    // island amity = {"Amity", "09:00", "17:00", NULL};
    // island craggy = {"Craggy", "09:00", "17:00", NULL};
    // island isla_nublar = {"Isla Nublar", "09:00", "17:00", NULL};
    // island shutter = {"Shutter", "09:00", "17:00", NULL};
    // amity.next = &craggy;
    // craggy.next = &isla_nublar;
    // isla_nublar.next = &shutter;
    // island skull = {"Skull", "09:00", "18:00", NULL};
    // isla_nublar.next = &skull;
    // skull.next = &shutter;
    // display(&amity);
}
