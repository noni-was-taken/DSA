#ifndef BIT_VECTOR_FUNCTIONS_H
#define BIT_VECTOR_FUNCTIONS_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define numBits 8

typedef bool SET[numBits];


void set_union(SET A, SET B, SET O){
    for(int i = numBits - 1; i >= 0; i--){
        O[i] = (A[i] || B[i]);
    }
}   

void set_difference(SET A, SET B, SET O){
    for(int i = numBits - 1; i >= 0; i--){
        O[i] = (A[i] && !B[i]);
    }
}

void set_intersection(SET A, SET B, SET O){
    for(int i = numBits - 1; i >= 0; i--){
        O[i] = (A[i] && B[i]);
    }
}   

void displaySET(SET s){   
    for(int i = numBits - 1; i >= 0; i--){
        printf("%d ", (s[i])?1:0);
    }
}


#endif