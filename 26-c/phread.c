/**
 * 线程
*/

#include <pthread.h>
#include <stdio.h>

int beers = 2000000;

pthread_mutex_t beers_lock = PTHREAD_MUTEX_INITIALIZER;

void* drink_lots(void *a)
{
    int i;
    // 加锁
    pthread_mutex_lock(&beers_lock);

    for (i = 0; i < 100000; i++) {
        beers = beers - 1;
    }

    // 解锁
    pthread_mutex_unlock(&beers_lock);
    printf("beers = %i\n", beers);
    return NULL;
}

int main()
{
    pthread_t threads[20];
    int t;
    printf("%i bottles of beer on the wall\n%i bottles of beer\n", beers, beers);
    for (t = 0; t < 20; t++) {
        // 创建线程
        pthread_create(  &threads[t], NULL, drink_lots, NULL);
    }
    void* result;
    for (t = 0; t < 20; t++) {
        // 等待线程结束, 并接收结果
        pthread_join(threads[t], &result);
    }
    printf("There are now %i bottles of beer on the wall\n", beers);
    return 0;
}