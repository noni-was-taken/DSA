#ifndef QUEUE_H
#define QUEUE_H
#define MAX 10

#include<stdio.h>
#include<stdbool.h>

typedef struct{
    char elems[MAX];
    int f;
    int r;
}Queue, *QueuePtr;

void initQueue(QueuePtr Q){
    Q->f = 0;
    Q->r = -1;
}
bool isFullQueue(Queue Q){
    return(Q.r+2)%MAX == Q.f;
}

bool isEmptyQueue(Queue Q){
    return (Q.r+1)%MAX == Q.f;
}
void enqueue(QueuePtr Q, char data){
    if(!isFullQueue(*Q)){   
        Q->r = (Q->r+1)%MAX;
        Q->elems[Q->r] = data;
    }
}
void dequeue(QueuePtr Q){
    if(!isEmptyQueue(*Q)){
        Q->f = (Q->f+1)%MAX;
    }
}
char front(Queue Q){
    return isEmptyQueue(Q) ? '\0' : Q.elems[Q.f];
}
void enqueueUnique(QueuePtr Q, char data){
    Queue temp;
    for(temp = *Q; !isEmptyQueue(temp) && front(temp) != data; dequeue(&temp)){}
    if(isEmptyQueue(temp)) enqueue(Q, data);
    else printf("\nQ: Data is not unique");
}
void displayQueue(Queue Q){
    printf("\nQueue Contents:");
    for(;!isEmptyQueue(Q); dequeue(&Q)){
        printf("%c ", front(Q));
    }
}
void dequeueUnique(QueuePtr Q, char data){
    Queue temp;
    initQueue(&temp);
    for(;!isEmptyQueue(*Q) && front(*Q) != data; enqueue(&temp, front(*Q)), dequeue(Q)){}
    if(isEmptyQueue(*Q)) printf("\nQ: No occurance of entry was found.");
    else dequeue(Q);
    for(;!isEmptyQueue(temp); enqueue(Q, front(temp)), dequeue(&temp)){}
}

#endif