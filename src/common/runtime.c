#include <string.h>
#include <stdlib.h>
#include "runtime.h"
#include "system.h"
#include "linked_list.h"
#include "terminal_menu.h"

void setSystemInfo(char * separator, char * path){
    separator = (SYSTEM_NAME == 'w') ? strdup("\\") : strdup("/");
    path = (SYSTEM_NAME == 'w') ? strdup("C:\\") : strdup("/");
}
void run(){
    char * separator;
    char * path;
    setSystemInfo(separator, path);
    struct node * cache = getNewLinkedList();
    while (1){
        
    }
    free(path);
    free(separator);
}
