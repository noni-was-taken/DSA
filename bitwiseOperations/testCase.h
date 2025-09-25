#ifndef TESTCASE_H
#define TESTCASE_H

#include<stdio.h>

void displayRoad(char trains[], char surfer){
    printf("The Tracks Ahead:\n");
    for(int i = 0; i < 5; i++){
        for(int mask = 1<<7; mask; mask >>=1){
            printf("%d", (trains[i]&mask) ? 1 : 0);
        }
        printf("\n");
    }
    printf("\nYour current position:\n");
    for(int mask = 1<<7; mask; mask >>=1){
        printf("%d", (surfer&mask) ? 1 : 0);
    }
}

void testCode(char trains[], int cases){
    switch(cases){
        case 1:
            trains[0] = 247;
            trains[1] = 223;
            trains[2] = 254;
            trains[3] = 127;
            trains[4] = 253;
        default:
            break;
    }
}

#endif