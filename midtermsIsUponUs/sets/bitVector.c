#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"bitVectorFunctions.h"

#define numBits 8

typedef bool SET[numBits];

int main(){
    system("cls");

    SET A = {1,0,1,0,1,0,1,0};  /* 0xAA */
    SET B = {0,1,0,1,0,1,0,1};  /* 0x55 */

    SET U, D, I;

    printf("\nSET A\n");
    displaySET(A);

    printf("\nSET B\n");
    displaySET(B);

    printf("\nUnion\n");
    set_union(A,B,U);
    displaySET(U);

    printf("\nDifference\n");
    set_difference(A,B,D);
    displaySET(D);

    printf("\nIntersection\n");
    set_intersection(A,B,I);
    displaySET(I);
    
    return 0;
}
