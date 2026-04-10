#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "runtime.h"
#include "system.h"
#include "files.h"
#include "linked_list.h"
#include "terminal_menu.h"

void setSystemInfo(char ** separator, char ** path){
    * separator = (SYSTEM_NAME == 'w') ? strdup("\\") : strdup("/");
    * path = (SYSTEM_NAME == 'w') ? strdup("C:\\") : strdup("/");
}
void run(){
    //global state
    char * separator = NULL;
    char * path = NULL;
    int count = 0;
    setSystemInfo(&separator, &path);
    struct node * cache = getNewLinkedList();
    struct entry ** currentDir = (SYSTEM_NAME == 'w') ? getEntryNames(strcat(path, "*"), &count) : getEntryNames(path, &count);
    bool over = false;
    //end

    while (!over){
        struct command current = runTerminalMenu(currentDir, count);
        switch (current.command)
        {
        case 'q':
            over = true;
            break;
        default:
            break;
        }
    }
    freeEntries(currentDir, count);
    freeLinkedList(&cache);
    free(path);
    free(separator);
}
