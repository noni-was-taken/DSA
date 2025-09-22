#ifndef CBQUEUE_H
#define CHQUEUE_H

#include<stdio.h>
#include<stdbool.h>

typedef struct{
    int f;
    int r;
}Queue;

//initQueue
void initQueue(Queue* Q){
    Q->f = -1;
    Q->r = -1;
}
//isEmpty
bool isEmptyQueue(Queue Q){
    return Q.f == -1;
}

//enqueue
void enqueue(VHeap* VH, Queue* Q, char data){
    int temp = alloc(VH);
    if(temp != -1){
        VH->H[temp].data = data;
        VH->H[temp].next = Q->r;
        if(isEmptyQueue(*Q)){
            Q->f = temp;
        }
        Q->r = temp;
    }
}

//dequeue
void dequeue(VHeap* VH, Queue* Q){
    if(!isEmpty(*Q)){
        int temp = Q->f;
        Q->f = VH->H[Q->f].next;
        dealloc(VH, temp);
    }
}

//front
char front(VHeap* VH, Queue* Q){
    return VH->H[Q->f].data;
}

//pushUnique
void pushUnique(VHeap* VH, Queue* Q, char data){
    Queue temp;
    initQueue(&temp);
    for(;!isEmptyQueue(*Q) && front(VH, Q) != data; enqueue(VH, &temp, front(VH, Q)), dequeue(VH, Q)){}
    if(isEmptyQueue(*Q)){
        for(;!isEmptyQueue(temp); enqueue(VH, Q, front(VH, &temp)), dequeue(VH, &temp)){}
        enqueue(VH, Q, data);
    }else{
        for(;!isEmptyQueue(temp); enqueue(VH, Q, front(VH, &temp)), dequeue(VH, &temp)){}
        printf("\nQ: Data is not unique");
    }
}

//display
void displayQueue(VHeap VH, Queue Q){
    printf("CBQueue Contents: ");
    for(;!isEmptyQueue(Q); dequeue(&VH, &Q)){
        printf("%c ", front(&VH, &Q));
    }
}

//popUnique
void popUnique(VHeap* VH, Queue* Q, char data){
    Queue temp;
    initStack(&temp);
    for(;!isEmptyQueue(*Q) && front(VH, Q) != data; enqueue(VH, &temp, front(VH, Q)), dequeue(VH, Q)){}
    if(!isEmptyQueue(*Q)){
        dequeue(VH, Q);
    }
    for(;!isEmptyQueue(temp); push(VH, Q, front(VH, &temp)), pop(VH, &temp)){}
}

#endif