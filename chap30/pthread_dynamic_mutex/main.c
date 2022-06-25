#include <stdio.h>
#include <pthread.h>
#include "tlpi_hdr.h"

static int glob = 0;
static pthread_mutex_t mtx;

void* func_thread_cb(void *args)
{
    int s;
    while (glob < 1000)
    {
        s = pthread_mutex_lock(&mtx);
        if (s < 0)
            errExitEN(s, "mutex lock");
        printf("%d \n", glob++);
        s = pthread_mutex_unlock(&mtx);
        if (s < 0)
            errExitEN(s, "mutex unlock");
    }
}


int main()
{
    pthread_t pid1, pid2;
    int ret = 0;
    pthread_mutexattr_t mutex_attr;
    pthread_mutexattr_settype(&mutex_attr, PTHREAD_MUTEX_NORMAL);
    ret = pthread_mutex_init(&mtx, NULL);

    ret = pthread_create(&pid1, NULL, func_thread_cb, NULL);
    if (ret < 0)
        errExitEN(ret, "pthread create");
    ret = pthread_create(&pid2, NULL, func_thread_cb, NULL);
    if (ret < 0)
        errExitEN(ret, "pthread create");
    pthread_join(pid1, NULL);
    pthread_join(pid2, NULL);

    ret = pthread_mutex_destroy(&mtx);
    if (ret < 0)
        errExitEN(ret, "mutex destroy");
    
    exit(EXIT_SUCCESS);
    
}