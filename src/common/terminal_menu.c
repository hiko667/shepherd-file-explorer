#include "terminal_menu.h"
#include "system.h"

void clearTerminal(){
    if(SYSTEM_NAME == 'w') system("cls");
    else if(SYSTEM_NAME == 'l') system("clear");
}

void printType(enum entryTypes type, int count){
    switch (type){
    case FILE_ENTRY: printf("[FILE]"); break;
    case HIDEN_FILE_ENTRY: printf("[HIDEN FILE]"); break;
    case DIR_ENTRY: printf("[DIR]"); break;
    case HIDEN_DIR_ENTRY: printf("[HIDEN DIR]"); break;
    default: printf("[ERROR] %d", count); break;
    }
}

void printOptions(struct entry ** options, int position, int count){
    
    for(int i = 0;i<count; i++){

        if (position == i) printf("->>");
        printType(options[i]->type, count);
        printf(" %s\n", options[i]->name);
    }
}

command_t decodeCommandFromKey(char key){
    switch (key){
    case 'f': return SHEPHERD_PICK; break;
    case 'd': return SHEPHERD_GO_BACK; break;
    case 'c': return SHEPHERD_CLEAR_CACHE; break;
    case 'q': return SHEPHERD_QUIT; break;
    default: return SHEPHERD_UNKNOWN; break;
    }
}