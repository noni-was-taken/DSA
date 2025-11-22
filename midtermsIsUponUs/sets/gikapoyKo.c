#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef unsigned int SET;

int bit_size = sizeof(SET)*8;

// insert, delete, is_member, union, intersection, difference

bool insert(SET *s, int pos); //return false if already a member
bool delete(SET *s, int pos); //return false if there is no member already
bool is_member(SET *s, int pos);
SET unionSet(SET a, SET b);
SET intersectionSet(SET a, SET b);
SET differenceSet(SET a, SET b);

void printSet(SET s);

int main(){
    system("cls");
    SET a = 0;
    SET b = 0;

    insert(&a, 12);
    printSet(a);


    return 0;
}

bool insert(SET *s, int pos){
    bool retval = false;
    if(pos > bit_size) printf("Invalid position");
    else{
        SET mask = 1u << pos;
        if(((*s)&mask) == 0u){
            *s |= mask;
            retval = true;    
        }
    }
    return retval;
}

void printSet(SET s){
    printf("\n");
    SET mask = 1 << (bit_size-1);
    for(int count = 1;mask; mask >>= 1, count++){
        printf("%d ", (s&mask) ? 1 : 0);
        if(count%8 == 0) printf(" ");
    }
}