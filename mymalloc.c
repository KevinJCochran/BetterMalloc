#include <stdio.h>
#include <stdlib.h>
#include "mymalloc.h"

/*
 * my-malloc.c
 */

//size of memEntries 
static const int entriesSize = SIZE/sizeof(MemEntry)+1;
static void *memEntries[SIZE/sizeof(MemEntry)+1];

static int getIndex()
{
    int i;
    for(i = 0; i < entriesSize;i++)
    {
        if(memEntries[i] == 0)
            return i;
    }
    return 1;
}

void *BMalloc(size_t size, char* file, int line)
{
    printf("Starting BMalloc...\n");
    MemEntry* entry = (MemEntry*)allMem; 
    MemEntry* temp = entry;
    MemEntry newEntry = {NULL,NULL,KEY_VALUE,0,size};

    //Check if there are any MemEntries created yet.
    if(entry->key == KEY_VALUE)
    {
        //Iterate through the MemEnteries looking for free space.
        while(entry != NULL)
        {
            //if there is room, then this will find it.
            if(entry->free == 1 && size <= (entry->entrySize)+sizeof(MemEntry)+1)
            {
                temp = entry;
                temp = temp+1;
                temp = (MemEntry*)((char*)temp)+size;
                *temp = newEntry;
                temp->entrySize = (entry->entrySize)-(size)-(sizeof(MemEntry));
                temp->free = 1;
                memEntries[getIndex()] = temp; 
                temp->next = entry->next;
                temp->prev = entry;
                entry->entrySize = size;
                entry->free = 0;
                entry->next = temp;
                return (entry+1);
            }
            entry = entry->next;
        }
        //Space was not found. Return NULL.
        printf("tried to enter but not enough room\n");
        return NULL;
    }
    //First entry. Create two MemEntries. One for requested mem
    //and one for left over mem.
    else if(size <= (SIZE)-(sizeof(MemEntry)*2))
    {
        printf("attempting to create first entry\n");
        *entry = newEntry;
        temp = temp+1;
        temp = (MemEntry*)((char*)temp)+size;
        *temp = newEntry;
        temp->entrySize = (SIZE)-(size)-(sizeof(MemEntry)*2);
        temp->free = 1;
        temp->next = NULL;
        temp->prev = entry;
        entry->entrySize = size;
        entry->free = 0;
        entry->next = temp;
        memEntries[getIndex()] = allMem;
        return (entry+1);
    }

    //All hope is lost...
    printf("total failure\n");
    return NULL;
}

//free a memory buffer pointed to by p
void BFree(void *p, char *file, int line)
{
    MemEntry *ptr;
    MemEntry *prev;
    MemEntry *next;

    if(p == NULL)
    {
        printf("Pointer is NULL, free failed\n");
        return;
    }

    ptr = (MemEntry*)((char*)p - sizeof(MemEntry));

    int i;
    int valid = 0;
    //static int i = 0; 
    for(i = 0; i<entriesSize;i++)
    { 
       if(ptr == memEntries[i] && !ptr->free)
       {
          valid = 1;
          break; 
       }
    }
    if(!valid)
    {
        printf("Error: Memory has already been freed\n");
        return;
    } 
    if((prev = ptr->prev) != 0 && prev->free)
    {
        //the previous chunk is free,so
        //merge this chunk with the previous chunk
        prev->entrySize += sizeof(MemEntry) + ptr->entrySize;
        memEntries[i] = 0;
        printf("freeing block %#x merging with predecessor new size id %d\n", p, prev->entrySize);
    }
    else
    {
        printf("freeing block %#x\n", p);
        //not setting memEntry to null b/c not necessarily removing it, just free=1
        ptr->free = 1;
        prev = ptr; //used for the step below
    }
    if((next = ptr->next) != 0 && next->free)
    {
        //the next chunk free, merge with it
        prev->entrySize += sizeof(MemEntry) + next->entrySize;
        prev->next = next->next; 
        prev->free = 1;
        for(i = 0;i < entriesSize; i++)
        {
            if(next == memEntries[i])
            {
                memEntries[i] = 0;
                break;
            }
        }
        printf("freeing block %#x merging with successor new size is %d\n",p,prev->entrySize);
    }
}
                    
    
