#ifndef MY_MALLOC_H
#define MY_MALLOC_H
#define SIZE 5000
#define KEY_VALUE 8483938
#define malloc(x) mymalloc((x),__FILE__,__LINE__)
#define free(x) myfree((x),__FILE__,__LINE__)
/*
 * my-malloc.h
 */

#include <stdlib.h>

static char allMem[SIZE];

/*
 * MemEntry holds information about a memory entry and
 * pointer to the previous and next entries.
 */
typedef struct MemEntry_ MemEntry;
struct MemEntry_
{
    MemEntry* next;
    MemEntry* prev;
    size_t key;
    short free;
    int entrySize;
};

/*
 * Better memory allocator function allocates memory in
 * static char array of size "SIZE". 
 * Takes unsigned int "size" and Returns void pointer to 
 * allocated memory of size "size" or NULL if unsuccessful.
 */
void *mymalloc(size_t size, char* file, int line);

void myfree(void *ptr,char *file,int line);
#endif
