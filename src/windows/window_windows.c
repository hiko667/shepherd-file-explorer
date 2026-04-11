#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include "open_window.h"

void openWindow(const char * path){
    if(path == NULL) return;
    size_t stringSize = strlen(path) + 32;
    char * command = (char*)malloc(stringSize);
    snprintf(command, stringSize, "start \"\" \"%s\"", path);
    system(command);
    free(command);
}