#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]){
    sleep(1);
    printf("%s", "baidu.com");
    return 0;
    
    // output1 : donuts with coffee
    char *my_env[] = {"FOOD=coffee", NULL};
    if(execle("./coffee", "./coffee", "donuts", NULL, my_env) == -1){
        fprintf(stderr,"Can't run process 0: %s\n", strerror(errno));
        return 1;
    }

    // output2 : cream with donuts
    char *my_env1[] = {"FOOD=donuts", NULL};
    if(execle("./coffee", "./coffee", "cream", NULL, my_env1) == -1){
        fprintf(stderr,"Can't run process 0: %s\n", strerror(errno));
        return 1;
    }

    // output3 : coffee with coffee
    if(execl("./coffee", "coffee", NULL) == -1){
        fprintf(stderr,"Can't run process 0: %s\n", strerror(errno));
        return 1;
    }

    // output4 : coffee with donuts
    char *my_env2[] = {"FOOD=donuts", NULL};
    if(execle("./coffee", "coffee", NULL, my_env2) == -1){
        fprintf(stderr,"Can't run process 0: %s\n", strerror(errno));
        return 1;
    }
    
    return 0;
}