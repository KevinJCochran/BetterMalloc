#ifndef MY_MALLOC_H
#define MY_MALLOC_H

/*
 * my-malloc.h
 */

#include <stdlib.h>

/*
 * MemEntry holds information about a memory entry and
 * pointer to the previous and next entries.
 */
typedef struct MemEntry* MemEntryPtr;
struct MemEntry
{
    MemEntryPtr next;
    MemEntryPtr prev;
    int free;
    int memSize;
}

int BMalloc(int size);


#endif
