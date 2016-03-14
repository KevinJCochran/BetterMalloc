#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mymalloc.h"

int main(int argc, char ** argv)
{
    printf("\n===== Starting test4 =====\n");
    /*
     * Start by allocating 5000 bytes.
     */
    printf("Attempting to allocate 5000 bytes...\n");
    char * teststr = (char*)malloc(5000);

    printf("===== Ending test4 =====\n\n");
    return 0;
}
