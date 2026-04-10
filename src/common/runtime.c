#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
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
    setSystemInfo(&(globalState->path), &(globalState->separator));
    (*globalState).count = 0;
    (*globalState).position = 0;
    (*globalState).cache = getNewLinkedList();
    (*globalState).currentDir = (SYSTEM_NAME == 'w') ? 
    getEntryNames(strcat((*globalState).path, "*"), &(globalState->count)) : 
    getEntryNames((*globalState).path, &(globalState->count));

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
    case 'q': (* globalState).over = true; break;
    
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
    freeGlobalState(&globalState);
}