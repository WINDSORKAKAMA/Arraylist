#include <stdio.h>
#include "arrlist.h"

// test basic push() and pop() operations

int main(){
    ArrayList array;
    
    initArrayList(&array, 17);
    
    push(&array, 197);
    // subtract 1 because length is the index ahead of  current index
    printf("Top Value: %d\n", array.inuse[array.length-1]);
    push(&array, 67);
    printf("Top Value: %d\n", array.inuse[array.length-1]);
    
    pop(&array);
    printf("Top Value: %d\n", array.inuse[array.length-1]);

    printf("Total Capacity: %d\n", array.capacity);
}
