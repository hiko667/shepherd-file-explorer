#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "open_window.h"
#include "runtime.h"
#include "system.h"
#include "files.h"
#include "linked_list.h"
#include "terminal_menu.h"
#include "state.h"

void setSystemInfo(char ** separator, char ** path){
    * separator = (SYSTEM_NAME == 'w') ? strdup("\\") : strdup("/");
    * path = (SYSTEM_NAME == 'w') ? strdup("C:\\") : strdup("/");
}
void loadDefaultState(struct state * globalState){
    (*globalState).over = false;
    (*globalState).separator = NULL;
    (*globalState).path = NULL;
    setSystemInfo(&(globalState->separator), &(globalState->path));
    (*globalState).count = 0;
    (*globalState).position = 0;
    (*globalState).cache = getNewLinkedList();
    if(SYSTEM_NAME == 'w'){
        size_t sizeOfFullPath = strlen((*globalState).path) + 2;
        char * path = malloc(sizeOfFullPath);
        snprintf(path, sizeOfFullPath, "%s*",(*globalState).path);
        printf("%s", path);
        (*globalState).currentDir = getEntryNames(path, &(globalState->count));
        free(path);
    }
    else{
        (*globalState).currentDir = getEntryNames((*globalState).path, &(globalState->count));
    }
    

}
void freeGlobalState(struct state * globalState){
    free(globalState->path);
    free(globalState->separator);
    freeEntries(globalState->currentDir, globalState->count);
    freeLinkedList(&(globalState->cache));
}

void evaluateCommand(char command, struct state * globalState){
    switch (command)
    {
    case 'q': (* globalState).over = true; break; // qui app
    case 'c': //clear cache
        freeLinkedList(&(globalState->cache));
        (*globalState).cache = getNewLinkedList();
        break;
    case 'f': //open window
        int position = (*globalState).position;
        if (globalState->currentDir[position]->type == FILE_ENTRY || 
            globalState->currentDir[position]->type == HIDEN_FILE_ENTRY){
            char * fileName = globalState->currentDir[position]->name;
            size_t sizeOfFullPath = strlen(globalState->path) + strlen(fileName) + 2;
            char * path = (char *)malloc(sizeOfFullPath);
            if(path){
                snprintf(path, sizeOfFullPath, "%s%s", globalState->path, fileName);
                printf("%s\n", fileName);
                printf("%s\n", globalState->separator);
                printf("%s\n", path);
            }
            openWindow(path);
        }
        else{
            
        }
        break;
    default:
        break;
    }
}

void run(){
    struct state globalState;
    loadDefaultState(&globalState);
    while (!globalState.over){
        char command = runTerminalMenu(globalState.currentDir, globalState.count, &(globalState.position));
        evaluateCommand(command, &globalState);
    }
    printf("Zuzia1");
    freeGlobalState(&globalState);
}