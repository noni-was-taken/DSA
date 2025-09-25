#ifndef QUEUE_H
#define QUEUE_H
#define MAX 10

#include<stdio.h>
#include<stdbool.h>

typedef struct{
    int elems[MAX];
    int f;
    int r;
}Queue, *QueuePtr;

void initialize(QueuePtr Q){
    Q->f = 0;
    Q->r = -1;
}
bool isFull(Queue Q){
    return(Q.r+2)%MAX == Q.f;
}

bool isEmpty(Queue Q){
    return (Q.r+1)%MAX == Q.f;
}
void enqueue(QueuePtr Q, int data){
    if(!isFull(*Q)){   
        Q->r = (Q->r+1)%MAX;
        Q->elems[Q->r] = data;
    }
}
void dequeue(QueuePtr Q){
    if(!isEmpty(*Q)){
        Q->f = (Q->f+1)%MAX;
    }
}
int front(Queue Q){
    return isEmpty(Q) ? -1 : Q.elems[Q.f];
}

void displayQueue(Queue Q){
    for(;!isEmpty(Q); dequeue(&Q)){
        printf("%d ", front(Q));
    }
}

#endif