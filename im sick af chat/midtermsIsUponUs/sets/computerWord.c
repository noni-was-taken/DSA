#include<stdio.h>
#include<stdlib.h>
#include"computerWordFunctions.h"

typedef unsigned char SET;

int main(){
    system("cls");

    SET A = 254;
    SET B = 170;

    printf("\nSET A\n");
    displaySET(A);

    printf("\nSET B\n");
    displaySET(B);

    printf("\nUnion\n");
    displaySET(set_union(A, B));

    printf("\nDifference\n");
    displaySET(set_difference(A, B));

    printf("\nIntersection\n");
    displaySET(set_intersection(A, B));
    
    return 0;
}
