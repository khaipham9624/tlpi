#include "get_libc_version.h"
#include <stdio.h>
#include "get_libc_version.h"
#include "tlpi_hdr.h"

const char* get_libc_version()
{
    return gnu_get_libc_version();
}

int main(int argc, char **argv)
{
    printf("libc version: %s\n", get_libc_version());
}