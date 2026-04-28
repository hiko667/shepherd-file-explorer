#ifndef FILES_H
#define FILES_H
#include <stdlib.h>
#include "entry.h"
#include "state.h"
struct entry ** getEntryNames(char * directory, int * count);
void freeEntries(struct entry ** entries, int count);
void goBack(struct state * globalState);
#endif