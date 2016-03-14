#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mymalloc.h"

int main(int argc, char ** argv)
{
    printf("\n===== Starting test1 =====\n");
    /*
     * Start by allocating 100 bytes and copying a string into
     * the allocated area.
     */
    printf("Attempting to store string...\n");
    char * teststr = (char*)malloc(100);
    strcpy(teststr,"Test str");
    
    /* Show that string was successfully stored in memory. */
    printf("Stored string: %s\n",teststr);
    printf("Stored at address: %x\n",teststr);

    /* Attempt to free ptr twice. */
    printf("Error message should display...\n");
    free(teststr);
    free(teststr);

    printf("===== Ending test1 =====\n\n");
    return 0;
}
