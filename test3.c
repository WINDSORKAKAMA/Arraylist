#include "arrlist.h"
#include <stdio.h>

// pass() works but use() does not
int main(){
    ArrayList array;
    initArrayList(&array, 4);
    push(&array, 17);
    printf("Old Value of inuse[0]: %d\n", array.inuse[array.length-1]);

    printf("Value Passed: %d\n", pass(&array, 0));

    return 0;
}