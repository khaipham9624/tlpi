#include <stdio.h>
#include "get_libc_version.h"
int main()
{
    printf("libc version: %s\n", get_libc_version());
}