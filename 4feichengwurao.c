#include <stdio.h>

void skip(char *msg)
{
    puts(msg+6);
}

int main()
{
    // int c[] = {1, 2, 3};
    // int *choice = c;
    // c[0] = 2;
    // c[1] = c[2];
    // c[2] = *choice;
    // printf("我选%i号男嘉宾",c[2]);
    // return 0; 

    // int doses[] = {1, 3, 2, 1000};
    // printf("服用%i毫克的药",3[doses]);
    // return 0;

    char *msg = "Don't call me";
    skip(msg);
    return 0;
}