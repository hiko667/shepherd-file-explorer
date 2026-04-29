#include "terminal_menu.h"
#include <stdbool.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <poll.h>
#include <unistd.h>

int _getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

command_t runTerminalMenu(struct entry ** options, int count, int * position){
    bool over = false;
    char keyCode;
    clearTerminal();
    printOptions(options, (*position), count);
    while(!over){
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

}
