#ifndef WINDOWS_FILES_H
#define WINDOWS_FILES_H
#include <stdbool.h>
struct entry ** getEntryNames(char * directory, int * count);
void freeEntries(struct entry ** entries, int count);
#endif