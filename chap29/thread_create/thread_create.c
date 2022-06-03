#include <stdio.h>
#include <pthread.h>
#include "tlpi_hdr.h"

typedef struct my_struct
{
    int a;
    long b;
    char c;
}my_struct_t;

typedef struct my_ret_struct
{
    int a;
    long b;
}my_ret_struct_t;

void func_in_thread(my_struct_t *p_args)
{
    printf("Function in thread\n");
    my_ret_struct_t *ret = malloc(sizeof(my_ret_struct_t));
    memset(ret, 0, sizeof(my_ret_struct_t));
    ret->a = p_args->a + 1;
    ret->b = p_args->b + 1;
    pthread_exit(ret);
}

void* my_pthread_job_cb(void *args)
{
    my_struct_t *p_args = (my_struct_t*)(args);
    if (p_args->a < 10)
    {
        func_in_thread(p_args);
    }
    else if (p_args->a >= 10)
    {
        pthread_detach(pthread_self());
        printf("This thread is detached and dont care what and how happened!\n");
    }
    else
    {
        printf("Thread job\n");
        my_ret_struct_t *ret = malloc(sizeof(my_ret_struct_t));
        memset(ret, 0, sizeof(my_ret_struct_t));
        ret->a = p_args->a + 2;
        ret->b = p_args->b + 2;
        return ret;
    }
}

int main(int argc, char **argv)
{
    pthread_t threadId1;
    pthread_t threadId2;
    pthread_t threadId3;
    pthread_attr_t threadAttr1;
    pthread_attr_t threadAttr2;
    pthread_attr_t threadAttr3;

    int ret = pthread_attr_init(&threadAttr1);
    if (ret != 0)
        errExitEN(ret, "pthread attr init");
    
    ret = pthread_attr_init(&threadAttr2);
    if (ret != 0)
        errExitEN(ret, "pthread attr init");

    ret = pthread_attr_init(&threadAttr3);
    if (ret != 0)
        errExitEN(ret, "pthread attr init");

    my_struct_t *my_struct1 = malloc(sizeof(my_struct_t));
    ret = pthread_create(&threadId1, &threadAttr1, my_pthread_job_cb, my_struct1);
    if (ret < 0)
    {
        free(my_struct1);
        errExitEN(ret, "pthread create");
    }

    my_struct_t *my_struct2 = malloc(sizeof(my_struct_t));
    my_struct2->a = 3;
    my_struct2->b = 5;
    ret = pthread_create(&threadId2, &threadAttr2, my_pthread_job_cb, my_struct2);
    if (ret < 0)
    {
        free(my_struct2);
        errExitEN(ret, "pthread create");
    }

    my_struct_t *my_struct3 = malloc(sizeof(my_struct_t));
    my_struct3->a = 10;
    my_struct3->b = 5;
    ret = pthread_create(&threadId3, &threadAttr3, my_pthread_job_cb, my_struct3);
    if (ret < 0)
    {
        free(my_struct3);
        errExitEN(ret, "pthread create");
    }


    my_ret_struct_t *ret1;
    ret = pthread_join(threadId1, (void*)&ret1);
    if (ret < 0)
    {
        errExitEN(ret, "pthread join");
    }
    printf("%d %ld\n", ret1->a, ret1->b);
    free(ret1);
    free(my_struct1);

    my_ret_struct_t *ret2;
    ret = pthread_join(threadId2, (void*)&ret2);
    if (ret < 0)
    {
        errExitEN(ret, "pthread join");
    }
    printf("%d %ld\n", ret2->a, ret2->b);
    free(ret2);
    free(my_struct2);

    printf("End\n");
    return 0;
}