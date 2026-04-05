#ifndef ENTRY_H
#define ENTRY_H
enum entryTypes {
    DIR_ENTRY,
    FILE_ENTRY,
    HIDEN_DIR_ENTRY,
    HIDEN_FILE_ENTRY
};
struct entry{
    char * name;
    enum entryTypes type;
};

#endif