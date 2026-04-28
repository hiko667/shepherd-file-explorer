#ifndef TERMINAL_MENU_H
#define TERMINAL_MENU_H
#include <stdio.h>
#include "entry.h"
#include "command.h"

command_t runTerminalMenu(struct entry ** options, int count, int * position);

#endif