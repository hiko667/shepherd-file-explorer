#ifndef STATE_H
#define STATE_H
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"
#include "entry.h"
struct state
{
    bool over;
    int position;
    char * separator;
    char * path;
    int count;
    struct node * cache;
    struct node * dirCache;
    struct entry ** currentDir;
};

#endif