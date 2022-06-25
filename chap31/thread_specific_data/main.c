// #define _GNU_SOURCE

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include "tlpi_hdr.h"

/*
An application can determine how many keys an
implementation actually supports either via the definition of PTHREAD_KEYS_MAX
(defined in <limits.h>) or by calling sysconf(_SC_THREAD_KEYS_MAX). Linux
supports up to 1024 keys.
*/

/*
static __thread buf[MAX_ERROR_LEN]; Thread-Local Storage is an easier way than thread-specific data, but it is nonstandard
use static and __thread to declare Thread-Local Storage
*/

static pthread_once_t once = PTHREAD_ONCE_INIT;
static pthread_key_t key;

static int _sys_nerr = 3;
char* _sys_errlist[] =
{
    "err1",
    "err2",
    "err3"
};

#define MAX_ERROR_LEN 256
// static char buf[MAX_ERROR_LEN];


void destr_func(void *buf)
{
    // this buf is freed automatically when thread terminates
    // free(buf);
}

void init_key()
{
    int ret = pthread_key_create(&key, destr_func);
    if (ret < 0)
        errExitEN(ret, "pthread key create");
}

// char *
// strerror(int err)
// {
//     if (err < 0 || err >= _sys_nerr || _sys_errlist[err] == NULL) {
//         snprintf(buf, MAX_ERROR_LEN, "Unknown error %d", err);
//     } else {
//         strncpy(buf, _sys_errlist[err], MAX_ERROR_LEN - 1);
//         buf[MAX_ERROR_LEN - 1] = '\0';
//         /* Ensure null termination */
//     }
//     return buf;
// }


char *strerror(int err)
{
    char *buf;

    int ret = pthread_once(&once, init_key);
    if (ret < 0)
        errExitEN(ret, "pthread once");
    
    buf = pthread_getspecific(key);

    // The block of data is allocated only one times
    if (buf == NULL) // if first call from this thread, allocate buffer for thread, and save its location.
    {
        buf = malloc(MAX_ERROR_LEN);
        if (buf == NULL)
            errExit("malloc");

        ret = pthread_setspecific(key, buf);
        if (ret != 0)
            errExitEN(ret, "pthread set specific");
    }

    if (err < 0 || err >= _sys_nerr || _sys_errlist[err] == NULL) {
    // if (err < 0) {
        snprintf(buf, MAX_ERROR_LEN, "Unknown error %d", err);
    } else {
        strncpy(buf, _sys_errlist[err], MAX_ERROR_LEN - 1);
        buf[MAX_ERROR_LEN - 1] = '\0';
        /* Ensure null termination */
    }
    return buf;
}

void *func(void *args)
{
    char *str;
    printf("Other thread about to call strerror()\n");
    str = strerror(2);
    printf("Other thread: str (%p) = %s\n", str, str);
    // comment out free(str) if we use destructor of pthread_key_create()
    free(str);
    return NULL;
}

int main()
{
    pthread_t threadId;
    char *str;
    int ret;

    str = strerror(1);
    printf("Main thread has called strerror()\n");

    ret = pthread_create(&threadId, NULL, func, NULL);
    if (ret < 0)
        errExitEN(ret, "pthread create");
    
    ret = pthread_join(threadId, NULL);
    if (ret < 0)
        errExitEN(ret, "pthread join");

    printf("Main thread: str (%p) = %s\n", str, str);

    // comment out free(str) if we use destructor of pthread_key_create()
    free(str);

    return 0;

}