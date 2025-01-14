#include "arrlist.c"
#include <stdio.h>

// Test push() heap allocation features
int main(){
    ArrayList array;
    initArrayList(&array, 4);
    for(int i = 0; i <= 5; i++){
        push(&array, i);
        if(i <= 3)
            printf("Top value: %d\n",array.inuse[array.length-1]);

        else
            printf("Top Value: %d\n", array.n_inuse[array.length-1]);
        printf("Current Size of Buffer: %u\n", array.capacity);
    }
    return 0;
}
