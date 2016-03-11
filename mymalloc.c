#include <stdio.h>
#include <stdlib.h>
#include "mymalloc.h"

/*
 * my-malloc.c
 */

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
        return (entry+1);
    }

    //All hope is lost...
    printf("total failure\n");
    return NULL;
}
