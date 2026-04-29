#ifndef TERMINAL_MENU_H
#define TERMINAL_MENU_H
#include <stdio.h>
#include "entry.h"
#include "command.h"

command_t runTerminalMenu(struct entry ** options, int count, int * position);
void clearTerminal();
void printType(enum entryTypes type, int count);
void printOptions(struct entry ** options, int position, int count);
command_t decodeCommandFromKey(char key);

#endif