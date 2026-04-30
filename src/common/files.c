#include <stdio.h>
#include <string.h>
#include "files.h"
#include "linked_list.h"

void freeEntries(struct entry ** entries, int count){
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
    free(globalState->path);
    (*globalState).path = strdup(globalState->dirCache->path);
}

struct entry ** getEntryNames(char * path, int * count){
    countFilesInDirectory(path, count);
    struct entry ** readFiles = malloc(sizeof(struct entry *) * (*count));
    for(int i = 0; i < (*count); i++) readFiles[i] = malloc(sizeof(struct entry));
    readFilesToStruct(readFiles, path, (* count));
    return readFiles;
}