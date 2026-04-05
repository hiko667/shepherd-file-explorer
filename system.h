#include <stdio.h>

#if defined(_WIN32)
    #define SYSTEM_NAME "windows"
#elif defined(_WIN64)
    #define SYSTEM_NAME "windows"
#elif defined(__CYGWIN__) && !defined(_WIN32)
    #define SYSTEM_NAME "windows"
#elif defined(__linux__)
    #define SYSTEM_NAME "linux"
#endif