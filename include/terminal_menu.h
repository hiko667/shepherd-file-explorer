#ifndef TERMINAL_MENU_H
#define TERMINAL_MENU_H
#include <stdio.h>
#include "command.h"
#include "entry.h"
char runTerminalMenu(struct entry ** options, int count, int * position);

#endif