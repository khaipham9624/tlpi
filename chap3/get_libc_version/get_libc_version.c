#include "get_libc_version.h"
const char* get_libc_version()
{
    return gnu_get_libc_version();
}