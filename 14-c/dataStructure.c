/**
 * 数据结构
*/
#include <stdio.h>

typedef struct 
{
    unsigned int first_visit:1;
    unsigned int come_again:1;
    unsigned int fingers_lost:4;
    unsigned int shark_attack:1;
    unsigned int days_a_week:3;
};
