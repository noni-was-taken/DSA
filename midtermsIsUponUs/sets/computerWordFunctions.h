#ifndef COMPUTER_WORD_FUNCTIONS_H
#define COMPUTER_WORD_FUNCTIONS_H

#include<stdio.h>
#include<stdlib.h>

typedef unsigned char SET;

SET set_union(SET A, SET B){
    return A|B;
}

SET set_difference(SET A, SET B){
    return A&~B;
}

SET set_intersection(SET A, SET B){
    return A&B;
}

void displaySET(SET s){
    SET mask = 1;
    for(mask <<= ((sizeof(mask)*8)-1); mask; mask >>= 1){
        printf("%d ", (s&mask)?1:0);
    }
}


#endif