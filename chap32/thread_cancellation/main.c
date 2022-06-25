#include "tlpi_hdr.h"
#include <stdio.h>
#include <pthread.h>
#include <string.h>

void routine(void* args)
{
    printf("clean up\n");
}

void* func(void *args)
{
    int count = 0;
    int old_state;
    int old_type;
    int ret;
    pthread_cleanup_push(routine, NULL);

    ret = pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &old_state);
    if (ret != 0)
        errExitEN(ret, "pthread set cancel state disable");
 
    while (1)
    {
        count++;
        printf("counter = %d\n", count);
        
        ret = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, &old_state);
        if (ret != 0)
            errExitEN(ret, "pthread set cancel state enable");

        ret = pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, &old_type);
        if (ret != 0)
            errExitEN(ret, "pthread set cancel type");

        printf("...\n");
        sleep(1);
        printf("***\n");
    }
    pthread_cleanup_pop(1);
    return NULL;
}

int main()
{
    pthread_t threadId;
    int ret;

    ret = pthread_create(&threadId, NULL, func, NULL);
    if (ret < 0)
        errExitEN(ret, "pthread create");

    sleep(3);
    ret = pthread_cancel(threadId);
    if (ret != 0)
        errExitEN(ret, "pthread cancel");

    ret = pthread_join(threadId, NULL);
    if (ret < 0)
        errExitEN(ret, "pthread join");
    return 0;
}