#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mymalloc.h"

int main(int argc, char ** argv)
{
//=======================================================//

    size_t in = 50;
    char* test = (char*)BMalloc(in,__FILE__,__LINE__);

    printf("\nReturn value: %x\n",test);
    strcpy(test,"Hello World!");
    
    printf("%s, \n",test);
    free(test);
    
    printf("%s,\n",test);
    free(test); 
    printf("\nReturn value: %x\n",test);
    
//=======================================================//

    in = 25;
    char* test1 = (char*)BMalloc(in,__FILE__,__LINE__);

    printf("Return value: %x\n",test1);
    strcpy(test1,"Beautiful weather!");
    printf("%s, %s\n",test,test1);
    char* start = allMem;
    char* end   = (allMem+499);
    int diff = end - start;
    printf("start: %lx, end: %lx, diff: %d\n",start,end,diff);
    diff     = test1 - test;
    diff = diff-sizeof(MemEntry);
    printf("diff: %d\n",diff);
//=======================================================//
    return 0;
}
