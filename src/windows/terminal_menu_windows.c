#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include "terminal_menu.h"

command_t runTerminalMenu(struct entry ** options, int count, int * position){
    bool over = false;
    char keyCode;
    clearTerminal();
    printOptions(options, (*position), count);
    while(!over){
        if(_kbhit())
        {
            keyCode = _getch();
            switch (keyCode)
            {
            case 'w':
                if((*position) == 0) (*position) = count-1;
                else (*position) -= 1;
                clearTerminal();
                printOptions(options, (*position), count);
                break;
            case 's':
                if((*position) == count-1) (*position) = 0;
                else (*position) += 1;
                clearTerminal();
                printOptions(options, (*position), count);
                break;
            default:
                clearTerminal();
                return decodeCommandFromKey(keyCode); break;
            }

        }
        else continue;
    }

}