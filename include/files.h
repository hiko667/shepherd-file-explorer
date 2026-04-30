#ifndef FILES_H
#define FILES_H
#include <stdlib.h>
#include "entry.h"
#include "state.h"
void countFilesInDirectory(char * path, int * count);
void readFilesToStruct(struct entry ** readFiles, char * path, int count);
struct entry ** getEntryNames(char * directory, int * count);
void freeEntries(struct entry ** entries, int count);
void goBack(struct state * globalState);


#endif