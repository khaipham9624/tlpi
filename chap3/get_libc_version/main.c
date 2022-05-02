#include <stdio.h>
#include "get_libc_version.h"
#include "tlpi_hdr.h"
int main(int argc, char **argv)
{
    printf("libc version: %s\n", get_libc_version());
}