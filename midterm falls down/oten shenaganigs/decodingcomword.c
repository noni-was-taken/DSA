#include<stdio.h>
#include<stdlib.h>


// Write your functions here...

int bitsize = sizeof(short int)*8*4;


int * bitmaskToArray(short int word[]){
    int *retval = malloc(sizeof(int)*bitsize);
    
    unsigned int mask = 1u << 15;
    int index = 0;
    for(int i = 0; i < bitsize; i++){
        if((word[index])&mask){
            retval[i] = 1;
        }else{
            retval[i] = 0;
        }
        
        mask >>= 1;
        if((i+1)%16 == 0){
            index += 1;
            mask = 1u << 15;
        }
    }
    
    return retval;
}

char *decodeString(int arr[]){
    char *retval = calloc(sizeof(char), 8);
    int index = 0;
    unsigned char mask = 1u << 7;
    for(int i = 0; i < bitsize; i++){
        
        retval[index] += (arr[i] != 0) ? mask : 0;
        
        mask >>= 1;
        if((i+1)%8 == 0){
            index += 1;
            mask = 1u << 7;
        }
    }
    
    
    return retval;
}

void displayBitPattern(int arr[]){
    // printf("%d", bitsize*sizeof(int));
    
    for(int i = 0; i < bitsize; i++){
        printf("%d", arr[i]);
        if((i+1)%16 == 0) printf(" ");
    }
}