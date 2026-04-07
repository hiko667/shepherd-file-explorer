#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include "system.h"
#include "menu.h"


void clearTerminal(){
    if(SYSTEM_NAME == 'w') system("cls");
    else if(SYSTEM_NAME == 'l') system("clear");
}

void printType(enum entryTypes type){
    switch (type){
    case FILE_ENTRY: printf("[FILE]"); break;
    case HIDEN_FILE_ENTRY: printf("[HIDEN FILE]"); break;
    case DIR_ENTRY: printf("[DIR]"); break;
    case HIDEN_DIR_ENTRY: printf("[HIDEN DIR]"); break;
    default: printf("[ERROR]"); break;
    }
}

void printOptions(struct entry ** options, int position, int count){
    for(int i = 0;i<count; i++){
        if (position == i) printf("->>");
        printType(options[i]->type);
        printf(" %s\n", options[i]->name);
    }
}

int runTerminalMenu(struct entry ** options, int count){
    int position = 0;
    bool over = false;
    char keyCode;
    clearTerminal();
    printOptions(options, position, count);
    while(!over){
        if(_kbhit())
        {
            keyCode = _getch();
            switch (keyCode)
            {
            case 'w':
                if(position == 0) position = count-1;
                else position -= 1;
                clearTerminal();
                printOptions(options, position, count);
                break;
            case 's':
                if(position == count-1) position = 0;
                else position += 1;
                clearTerminal();
                printOptions(options, position, count);
                break;
            case 'q':
                over = true;
                clearTerminal();
                printOptions(options, position, count);
                break;
            default:
                break;
            }

        }
        else continue;
        
        
    }

}