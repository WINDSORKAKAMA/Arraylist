#if !defined (HEADER)
    #define HEADER 0
    #include <stdlib.h>

                                            /* *** Array list struct definition *** */
    typedef struct{
        int* inuse;             // pointer to buffer currently used
        int* n_inuse;           // pointer that will be used after buffer1 is full 
        
        unsigned capacity;      // maximum elements that the array list can hold
        unsigned length;        // the number of elements that the array list can hold at a given time
    }ArrayList;



                 /****    Used by user to access elements and addresses of the array    ***/

    // passes the data at index of the buffer in use 
    extern int pass(ArrayList* arr, int index);

    // stores the index(th) address of the buffer in use within addr 
    extern void use(ArrayList* arr, int index, int* addr);



    #ifndef NULL_DEF
        #define NULL_DEF 0
                                        /**** The following are used by push() ****/

        // arrlist is an ArrayList* or pointer to ArrayList that points to an ArrayList variable defined by a user
        // nullptr is an int** or double int pointer pointing to the null pointer in the memory pointed to by arrlist
        // nullp is equal to the address of the null pointer
        #define nullp(arrlist) ((arrlist->n_inuse == 0) ? &arrlist->n_inuse : &arrlist->inuse) 

        // arrlist is an ArrayList* or pointer to ArrayList that points to an ArrayList variable defined by a user
        // no_nullptr is an int** or double int pointer pointing to the non null pointer in the memory pointed to by arrlist
        // nnullp is equal to the address of the non-null pointer
        #define nnullp(arrlist) ((arrlist->n_inuse == 0) ? &arrlist->inuse : &arrlist->n_inuse)

        static void copy(int* src, int* dest, int size);
    #endif



                                /***     Main Functions used by the actual program     ***/
    
    // initializes length to 0 and arr->capacity to capacity allocates memory on the stack 
    // of size (sizeof arr->inuse * capacity) and initial address is stores in arr->inuse
    // n_inuse is set to 0 aka n_inuse is a null pointer
    extern void initArrayList(ArrayList* arr, unsigned capacity);

    // pushes the last input data onto the buffer in use if length < capacity
    // otherwise, memory is allocated on the heap with double the capacity and the initial address is held by n_inuse
    // inuse is set to 0 aka inuse becomes a null pointer 
    extern void push(ArrayList* arr, int data);

    /* pops the last input data off the buffer in use */
    extern void pop(ArrayList* arr); 
#endif