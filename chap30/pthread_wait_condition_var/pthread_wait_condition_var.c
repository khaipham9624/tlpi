#include <stdio.h>
#include <pthread.h>
#include "tlpi_hdr.h"

static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
static pthread_mutex_t mux = PTHREAD_MUTEX_INITIALIZER;

static int glob = 0;
const static int low_threshold = 0;
const static int high_threshold = 100;

void* func_produce(void *args)
{
    int ret;
    while (1)
    {
        ret = pthread_mutex_lock(&mux);
        if (ret < 0)
            errExitEN(ret, "mutex lock");
        
        // while (glob == high_threshold)
        //     pthread_cond_wait(&cond, &mux);
        //     if (ret < 0)
        //         errExitEN(ret, "cond wait");
        
        while (glob < high_threshold)
        {
            glob++;
            printf("Produce %d \n", glob);
        }

        ret = pthread_mutex_unlock(&mux);
        if (ret < 0)
            errExitEN(ret, "mutex unlock");
        
        ret = pthread_cond_signal(&cond);
        // ret = pthread_cond_broadcast(&cond);
        if (ret < 0)
            errExitEN(ret, "cond signal");
    }
}

void* func_consume(void *args)
{
    while (1)
    {
        int ret;
        ret = pthread_mutex_lock(&mux);
        if (ret < 0)
            errExitEN(ret, "mutex lock");
        
        // This is a rule!
        while (glob == low_threshold)
            ret = pthread_cond_wait(&cond, &mux);
            if (ret < 0)
                errExitEN(ret, "cond wait");
        
        while (glob > low_threshold)
        {
            /* code */
            glob--;
            printf("Consume %d \n", glob);
        }
        
        ret = pthread_mutex_unlock(&mux);
        if (ret < 0)
            errExitEN(ret, "mutex unlock");
        
        ret = pthread_cond_signal(&cond);
        if (ret < 0)
            errExitEN(ret, "cond signal");
    }
    
}

int main()
{
    pthread_t threadId1, threadId2;
    int ret;
    ret = pthread_create(&threadId1, NULL, func_produce, NULL);
    if (ret < 0)
        errExitEN(ret, "pthread create 1");
    ret = pthread_create(&threadId2, NULL, func_consume, NULL);
    if (ret < 0)
        errExitEN(ret, "pthread create 2");

    pthread_join(threadId1, NULL);
    pthread_join(threadId2, NULL);
}