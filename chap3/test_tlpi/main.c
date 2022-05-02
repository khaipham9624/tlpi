#include <stdio.h>
#include "tlpi_hdr.h"
int main(int argc, char **argv)
{
    errno = 1;
    errMsg("This is %s", "error");
    // errExit("This is %s", "error");
    // err_exit("This is %s", "error");
    // errExitEN(2, "This is %s", "error");
    // fatal("This is %s", "error");
    // usageErr("This is %s", "error");
    // cmdLineErr("This is %s", "error");
}