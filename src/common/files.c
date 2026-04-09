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