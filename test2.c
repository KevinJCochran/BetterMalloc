#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mymalloc.h"

int main(int argc, char ** argv)
{
    printf("\n===== Starting test2 =====\n");

    /* attempt to free unallocated pointer. */
    printf("Attempt to free an unallocated pointer...\n");
    int i = 0;
    free(&i);

    printf("===== Ending test2 =====\n\n");

    return 0;
}
