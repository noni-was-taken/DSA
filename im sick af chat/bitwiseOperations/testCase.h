#ifndef TESTCASE_H
#define TESTCASE_H

#include<stdio.h>

void displayRoad(char trains[], unsigned char surfer){
    printf("\nYour current position:\n");
    for(int mask = 1<<7; mask; mask >>=1){
        printf("%d ", (surfer&mask) ? 1 : 0);
    }
    printf("\nThe Tracks Ahead:\n");
    for(int i = 0; i < 5; i++){
        for(int mask = 1<<7; mask; mask >>=1){
            printf("%d ", (trains[i]&mask) ? 1 : 0);
        }
        printf("\n");
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
            break;
        case 2:
            trains[0] = 127;   
            trains[1] = 191;   
            trains[2] = 223;   
            trains[3] = 239;   
            trains[4] = 247;   
            break;
        case 3:
            trains[0] = 251;   
            trains[1] = 253;   
            trains[2] = 254;   
            trains[3] = 254;   
            trains[4] = 127;   
            break;
        case 4:
            trains[0] = 254;   
            trains[1] = 254;   
            trains[2] = 254;   
            trains[3] = 254;   
            trains[4] = 254;   
            break;
        case 5:
            trains[0] = 127;
            trains[1] = 127;
            trains[2] = 127;
            trains[3] = 127;
            trains[4] = 127;
            break;
        default:
            break;
        }
}

bool escapeAttempt(char trains[],unsigned char surfer, int* moves){
    bool stat = true;
    for(int i = 0; i < 5; i++){
        if(moves[i] >= 0){
            surfer >>= moves[i];
        }else{
            surfer <<= -moves[i];
        }
        if((trains[i] & surfer || surfer == 0) != 0) stat = false;
    }
    return stat;
}
#endif