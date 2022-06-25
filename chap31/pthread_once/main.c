#include "tlpi_hdr.h"
#include <stdio.h>
#include <pthread.h>


static int glob = 0;
static pthread_once_t once_var = PTHREAD_ONCE_INIT;

void init()
{
    glob++;
}

void* func_to_init(void *args)
{
    pthread_once(&once_var, init);
}

int main()
{
    pthread_t thread1, thread2;
    int ret;
    ret = pthread_create(&thread1, NULL, func_to_init, NULL);
    if (ret < 0)
        errExitEN(ret, "pthread create");
    ret = pthread_create(&thread2, NULL, func_to_init, NULL);
    if (ret < 0)
        errExitEN(ret, "pthread create");
    ret = pthread_join(thread1, NULL);
    if (ret < 0)
        errExitEN(ret, "pthread join");
    ret = pthread_join(thread2, NULL);
    if (ret < 0)
        errExitEN(ret, "pthread join");
    printf("glob = %d\n", glob);
    return 0;
}