#include <stdio.h>
#include "system.h"
#include "files.h"
#include "entry.h"
#include "terminal_menu.h"

int main(int argc, char * argv[])
{
    int count = 0;
    struct entry ** files = getEntryNames("C:\\*", &count);
    if (!files) return -1;
    runTerminalMenu(files, count);
    freeEntries(files, count);
    return 0;
}

