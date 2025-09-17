#ifndef QUEUE_H
#define QUEUE_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    char data;
    struct node *next;
}Node, *NodePtr;

typedef struct{
    NodePtr front;
    NodePtr rear;
}Queue, *QueuePtr;

void initQueue(QueuePtr Q){
    Q->front = NULL;
    Q->rear = NULL;
}

bool isEmptyQueue(Queue Q){
    return Q.front == NULL;
}
 
void enqueue(QueuePtr Q, char data){
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory Allocation Failed");
        exit(1);
    }
    newNode->next = NULL;
    newNode->data = data;
    if(isEmptyQueue(*Q)){
        Q->front = newNode;
        Q->rear = newNode;
    }else{
        Q->rear->next = newNode;
        Q->rear = Q->rear->next;
    }
}

void dequeue(QueuePtr Q){
    if(!isEmptyQueue(*Q)){
        NodePtr temp = Q->front;
        Q->front = Q->front->next;
        free(temp);    
    }
}
char front(Queue Q){
    return isEmptyQueue(Q) ? '\0' : Q.front->data; 
}

void enqueueUnique(QueuePtr Q, char data){
    Queue temp;
    initQueue(&temp);
    for(;!isEmptyQueue(*Q) && front(*Q) != data; enqueue(&temp, front(*Q)), dequeue(Q)){}
    if(isEmptyQueue(*Q)){
        for(;!isEmptyQueue(temp); enqueue(Q, front(temp)), dequeue(&temp)){}
        enqueue(Q, data);
    }else{
        for(;!isEmptyQueue(temp); enqueue(Q, front(temp)), dequeue(&temp)){}
        printf("\nQ: Data is not unique");
    }
}

void displayQueue(Queue Q){
    if(!isEmptyQueue(Q)){
        printf("\nQueue Contents:");
        NodePtr trav = NULL;
        for(trav = Q.front; trav != NULL; trav = trav->next){
            printf("%c ", trav->data);
        }    
    }
}

void dequeueUnique(QueuePtr Q, char data){
    Queue temp;
    initQueue(&temp);
    for(;!isEmptyQueue(*Q) && front(*Q) != data; enqueue(&temp, front(*Q)), dequeue(Q)){}
    if(!isEmptyQueue(*Q)){
        dequeue(Q);
    }else{
        printf("\nQ: There are no occurance of entry data");
    }
    for(;!isEmptyQueue(temp); enqueue(Q, front(temp)), dequeue(&temp)){}
}

#endif