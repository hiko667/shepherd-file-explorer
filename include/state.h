#ifndef STATE_H
#define STATE_H
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"
#include "entry.h"
struct state
{
    bool over;
    char * separator;
    char * path;
    int count;
    struct node * cache;
    struct entry ** currentDir;
};

#endif