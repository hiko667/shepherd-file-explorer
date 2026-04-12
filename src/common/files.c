#include <stdio.h>
#include <string.h>
#include "files.h"

void freeEntries(struct entry ** entries, int count){
    if (!entries) return;
    for (int i = 0; i < count; i++) {
        if (entries[i]) {
            free(entries[i]->name); 
            free(entries[i]);
        }
    }
    free(entries);
}

void goBack(struct state * globalState){
    size_t i = strlen(globalState->path);
    while (globalState->path[i] != '\\') i--;
    char * temp = malloc(sizeof(char) * i);
    strncpy(globalState->path, temp, i);
    free(globalState->path);
    globalState->path = strdup(temp);
    free(temp);
}