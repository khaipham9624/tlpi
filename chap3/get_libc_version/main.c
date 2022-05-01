#include <stdio.h>
#include "get_libc_version.h"
#include "tlpi_hdr.h"
int main(int argc, char **argv)
{
    if (argc > 1)
    {
        printf("argv[1] = %d\n", getInt(argv[1], GN_ANY_BASE, "opt"));
    }

    // switch (expression)
    // {
    // case /* constant-expression */:
    //     /* code */
    //     break;
    
    // default:
    //     break;
    // }
    printf("libc version: %s\n", get_libc_version());
}