/**
 *  switch重构1cards.c代码
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char card_name[3];
    int count=0;
    do {
        /* code */
        puts("输入牌名:");
        scanf("%2s", card_name);
        int val=0;
        switch (card_name[0])
        {
            case 'Q':
            case 'K':
            case 'J':
                val = 10;
                break;
            case 'A':
                val = 11;
                break;
            case 'X':
                continue;
            
            default:
                val = atoi(card_name);
                if ((val < 1) || (val>10)){
                    puts("我无法理解这个值~");
                    continue;
                }
        }
        printf("这张牌的点数是:%i\n", val);

        if (val >=3 && val <=6){
            puts("计数增加");
            count++;
        } else if (val == 10){
            if (count == 0){
                puts("计数减少");
                count--;
            }
        }
        printf("当前计数:%i\n", count);
    } while (card_name[0] != 'X');
    
    
    return 0;
}