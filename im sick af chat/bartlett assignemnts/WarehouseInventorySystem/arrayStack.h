#ifndef STACK_H
#define STACK_H
#define MAX 5
#include<stdio.h>
#include<stdbool.h>

typedef struct{
    int stackID;
    int elems[MAX];
    int top;
}Stack, *StackPtr;


void initialize(StackPtr S){
    S->top = -1;
}
bool isEmpty(Stack S){     
    return S.top == -1 ? true : false;
}    
bool isFull(Stack S){
    return S.top == MAX - 1 ? true : false;
}    
void push(StackPtr S, int data){
    if(!isFull(*S)){
        S->top++;
        S->elems[S->top] = data;
    }
}
int top(Stack S){
    if(!isEmpty(S)){
        return S.elems[S.top];
    }
    return -1;
}
int pop(StackPtr S){
    int retVal = -1;
    if(!isEmpty(*S)){
        retVal = top(*S);
        S->top--;
    }
    return retVal;
}

void display(Stack S){
    for(;!isEmpty(S); pop(&S)){
        printf("%d ", top(S));
    }       
}    
#endif