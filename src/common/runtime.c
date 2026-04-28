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
#include "command.h"


void setSystemInfo(char ** separator, char ** path){
    * separator = (SYSTEM_NAME == 'w') ? strdup("\\") : strdup("/");
    * path = (SYSTEM_NAME == 'w') ? strdup("C:\\") : strdup("/");
}

void setCurrentDir(struct state * globalState){
    if (globalState->currentDir != NULL) freeEntries(globalState->currentDir, globalState->count);
    if(SYSTEM_NAME == 'w'){
        size_t sizeOfFullPath = strlen((*globalState).path) + 3;
        char * path = malloc(sizeOfFullPath);
        snprintf(path, sizeOfFullPath, "%s*",(*globalState).path);     
        printf("%s", path);
        (*globalState).currentDir = getEntryNames(path, &(globalState->count));
        printf("Zuzia3");
        free(path);
    }
    else{
        (*globalState).currentDir = getEntryNames((*globalState).path, &(globalState->count));
    }
}

void loadDefaultState(struct state * globalState){
    (*globalState).over = false;
    (*globalState).separator = NULL;
    (*globalState).path = NULL;
    setSystemInfo(&(globalState->separator), &(globalState->path));
    (*globalState).count = 0;
    (*globalState).position = 0;
    (*globalState).cache = getNewLinkedList();
    (*globalState).dirCache = getNewLinkedList();
    push(&(globalState->dirCache), (*globalState).path);
    globalState->currentDir = NULL;
    (*globalState).mode = SHEPHERD_UNKNOWN;
    setCurrentDir(globalState);
}
void freeGlobalState(struct state * globalState){
    free(globalState->path);
    free(globalState->separator);
    freeEntries(globalState->currentDir, globalState->count);
    freeLinkedList(&(globalState->cache));
    freeLinkedList(&(globalState->dirCache));
}

void openFile(struct state * globalState, int position){
    char * fileName = globalState->currentDir[position]->name;
    size_t sizeOfFullPath = strlen(globalState->path) + strlen(fileName) + 2;
    char * path = (char *)malloc(sizeOfFullPath);
    if(path){
        snprintf(path, sizeOfFullPath, "%s%s", globalState->path, fileName);
    }
    openWindow(path);
    free(path);
}

void openDir(struct state * globalState, int position){
    char * dirName = globalState->currentDir[position]->name;
    size_t sizeOfFullPath = strlen(globalState->path) + strlen(dirName) + 2;
    char * path = (char *)malloc(sizeOfFullPath);
    snprintf(path, sizeOfFullPath, "%s%s%s", globalState->path, dirName, globalState->separator);
    free(globalState->path);
    globalState->path = strdup(path);
    push(&(globalState->dirCache), globalState->path);
    setCurrentDir(globalState);
    free(path);
}

void evaluateCommand(command_t com, struct state * globalState){
    switch (com)
    {
    case SHEPHERD_QUIT: (* globalState).over = true; break; // quit app
    case SHEPHERD_CLEAR_CACHE: //clear cache
        freeLinkedList(&(globalState->cache));
        (*globalState).cache = getNewLinkedList();
        break;
    case SHEPHERD_PICK: //open file or switch directory
        int position = (*globalState).position;
        if (globalState->currentDir[position]->type == FILE_ENTRY || 
            globalState->currentDir[position]->type == HIDEN_FILE_ENTRY){
            openFile(globalState, position);
        }
        else{
            openDir(globalState, position);
            globalState->position = 0;
        }
        break;
    case SHEPHERD_GO_BACK:
        if(strcmp(globalState->path, "C:\\") != 0)
        {
            goBack(globalState);
            setCurrentDir(globalState);
            globalState->position = 0;
        }
        break;
    case SHEPHERD_MOVE:
        if((*globalState).mode != SHEPHERD_UNKNOWN){
            freeLinkedList(&(globalState->cache));
            (*globalState).cache = getNewLinkedList();
        }
        size_t pathLength = sizeof(char) * (strlen(globalState->path) + strlen(globalState->currentDir[position]->name));
        char * path = malloc(pathLength);
        path = strdup(globalState->path);
        strcat(path, globalState->currentDir[position]->name);
        push(&(globalState->dirCache), path);
        free(path);
        break;
    case SHEPHERD_COPY:

        break;
    default:
        break;
    }
}

void run(){
    struct state globalState;
    loadDefaultState(&globalState);
    while (!globalState.over){
        command_t com = runTerminalMenu(globalState.currentDir, globalState.count, &(globalState.position));
        evaluateCommand(com, &globalState);
    }
    freeGlobalState(&globalState);
}