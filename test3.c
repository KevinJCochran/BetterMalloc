#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mymalloc.h"

int main(int argc, char ** argv)
{
    printf("\n===== Starting test3 =====\n");
    /*
     * Start by allocating 100 bytes and copying a string into
     * the allocated area.
     */
    printf("Attempting to store string...\n");
    char * teststr = (char*)malloc(100);
    strcpy(teststr,"Test String");
    
    /* Show that string was successfully stored in memory. */
    printf("Stored string: %s\n",teststr);
    printf("Stored at address: %x\n",teststr);

    /* Attempt to free pointer that is off. */
    printf("Attempt to free bad pointer...\n");
    teststr = teststr + 5;
    free(teststr);

    printf("===== Ending test3 =====\n\n");
    return 0;
}
