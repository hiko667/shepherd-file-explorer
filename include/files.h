#ifndef FILES_H
#define FILES_H
    struct entry ** getEntryNames(char * directory, int * count);
    void freeEntries(struct entry ** entries, int count);
#endif