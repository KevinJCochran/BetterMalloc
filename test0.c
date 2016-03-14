#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mymalloc.h"

int main(int argc, char ** argv)
{
    printf("\n===== Starting test0 =====\n");
    /*
     * Start by allocating 100 bytes and copying a string into
     * the allocated area.
     */
    printf("Attempting to store string...\n");
    char * teststr = (char*)malloc(100);
    strcpy(teststr,"Hello world!");
    
    /* Show that string was successfully stored in memory. */
    printf("Stored string: %s\n",teststr);
    printf("Stored at address: %x\n",teststr);

    /* Allocate three more blocks of memory */
    printf("Attempting to store string...\n");
    char * teststr1 = (char*)malloc(50);
    strcpy(teststr1,"What nice weather!");
    printf("Stored string: %s\n",teststr1);
    printf("Stored at address: %x\n",teststr1);
    
    printf("Attempting to store string...\n");
    char * teststr2 = (char*)malloc(75);
    strcpy(teststr2,"The sun is Shinning!");
    printf("Stored string: %s\n",teststr2);
    printf("Stored at address: %x\n",teststr2);

    printf("Attempting to store string...\n");
    char * teststr3 = (char*)malloc(85);
    strcpy(teststr3,"I think I'll take a walk today!");
    printf("Stored string: %s\n",teststr3);
    printf("Stored at address: %x\n",teststr3);

    /* Show that all memory is in place by printing all strings.*/
    printf("String 0: %s\n",teststr);
    printf("String 1: %s\n",teststr1);
    printf("String 2: %s\n",teststr2);
    printf("String 3: %s\n",teststr3);

    /* Continue to free all memory */
    printf("Attempting to free string0...\n");
    free(teststr);
    printf("Attempting to free string1...\n");
    free(teststr1);
    printf("Attempting to free string2...\n");
    free(teststr2);
    printf("Attempting to free string3...\n");
    free(teststr3);
    printf("All strings freed\n");

    printf("===== Ending test0 =====\n");

    return 0;
}
