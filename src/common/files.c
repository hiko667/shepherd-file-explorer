#include <stdio.h>
#include <string.h>
#include "files.h"
#include "linked_list.h"

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
    pop(&(globalState->dirCache));
    printf(globalState->dirCache->path);
    free(globalState->path);

    (*globalState).path = strdup(globalState->dirCache->path);
}