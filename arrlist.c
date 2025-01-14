// Source File definitions

#include "arrlist.h"

    #ifndef SUPPORT 0
        #define SUPPORT 0

        int pass(ArrayList* arr, int index){
            if(arr->n_inuse == 0)
                return *(arr->inuse + index);
            else
                return *(arr->n_inuse + index);
        }

        // TODO: Identify root cause of the defectiveness of use()
        void use(ArrayList* arr, int index, int* addr){
            if(arr->n_inuse == 0)
                addr = arr->inuse + index;
            else
                addr = arr->n_inuse + index;
        }

        void copy(int* src, int* dest, int size){
            for(int i = 0; i < size; i++)
                dest[i] = src[i];
        }
    #endif


    #ifndef IMPLEMENTATION 0
        #define IMPLEMENTATION 0
        void initArrayList(ArrayList* arr, unsigned capacity){
            arr->capacity = capacity;
            arr->inuse = (int*)malloc(sizeof(int) * arr->capacity);
            arr->length = 0;
            arr->n_inuse = 0;
        }

        void push(ArrayList* arr, int data){
            int **n_nullptr;

            n_nullptr = nnullp(arr);

            if(arr->length < arr->capacity)
                (*n_nullptr)[arr->length] = data;

            else{
                int** nullptr = nullp(arr);

                arr->capacity *= 2;
                (*nullptr) = (int*)malloc(sizeof(int) * arr->capacity);

                copy(*n_nullptr, *nullptr, arr->capacity);

                free(*n_nullptr);
                *n_nullptr = 0;

                (*nullptr)[arr->length] = data;
            }
            arr->length += 1;
        }

        void pop(ArrayList* arr){
            arr->length -= 1;
        }
    #endif
