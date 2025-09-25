#ifndef CURSORBASED_H
#define CURSORBASED_H
#define MAX 20

#include<stdio.h>
#include<stdbool.h>

typedef struct{
    int id;
    char title[64];
    char content[255];
}Article;

typedef struct{
    Article data;
    int next;
}node, HeapNodes[MAX];

typedef struct{
    int avail;
    HeapNodes H;
}VHeap;


void initVHeap(VHeap* VH){
    VH->avail = MAX-1;
    for(int i = VH->avail; i >= 0; i--){
        VH->H[i].next =  i-1;
    }
    printf("Virtual Heap Initialized");
}

int alloc(VHeap* VH){
    int retVal = VH->avail;
    if(retVal != -1){
        VH->avail = VH->H[retVal].next;
    }
    return retVal;
}

void dealloc(VHeap* VH, int ndx){
    VH->H[ndx].next = VH->avail;
    VH->avail = ndx;
} 

#endif