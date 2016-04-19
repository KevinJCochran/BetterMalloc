#include <stdio.h>
#include <stdlib.h>
#include "mymalloc.h"

/*
 * my-malloc.c
 */

void *mymalloc(size_t size, char* file, int line)
{
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
                temp = (MemEntry*)((char*)temp + size);
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
        printf("File:%s:line:%d:ERROR:All mem used\n",file,line);
        return NULL;
    }
    //First entry. Create two MemEntries. One for requested mem
    //and one for left over mem.
    else if(size <= (SIZE)-(sizeof(MemEntry)*2))
    {
        *entry = newEntry;
        temp = temp+1;
        temp = (MemEntry*)((char*)temp + size);
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

    //Too much memory requested.
    return NULL;
}


void myfree(void *ptr, char *file, int line)
{
    //Checks if pointer is in range.
    if( ptr >= (void*)(allMem+sizeof(MemEntry)) && 
                                    ptr <= (void*)(allMem+(SIZE-sizeof(MemEntry))) )
    {
        MemEntry * entry = (MemEntry*)ptr;
        MemEntry * temp = (MemEntry*)ptr;
        entry = entry - 1;
        //Checks if pointing at valid MemEntry
        if(entry->key == KEY_VALUE)
        {
            //Checks for redundentcy
            if(entry->free == 1)
            {
                printf("File:%s:line:%d:ERROR:Redundant ptr\n",file,line);
                return;
            }
            else
            {
                entry->free = 1;
            }
            //Check if able to merger entries
            temp = entry->prev;
            if(temp != NULL && temp->free == 1)
            {
                temp->next = entry->next;
                temp->entrySize = (temp->entrySize) + (entry->entrySize) + sizeof(MemEntry);
            }
            temp = entry->next;
            if(temp != NULL && temp->free == 1)
            {
                entry->next = temp->next;
                entry->entrySize = (entry->entrySize) + (temp->entrySize) + sizeof(MemEntry);
            }
            return;
        }
        //Bad pointer passed.
        else
        {
            printf("File:%s:line:%d:ERROR:Ptr not returned from malloc\n",file,line);
            return;
        }
    }
    //Outside pointer passed.
    else
    {
        printf("File:%s:line:%d:ERROR:Non-allocated ptr\n",file,line);
        return;
    }
}
