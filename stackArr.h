#ifndef STACK_H
#define STACK_H
#define MAX 10

#include<stdio.h>
#include<stdbool.h>

typedef struct{
    char elems[MAX];
    int top;
}Stack, *StackPtr;

void initStack(StackPtr S){
    S->top = -1;
}
bool isEmptyStack(Stack S){     
    return S.top == -1 ? true : false;
}    
bool isFullStack(Stack S){
    return S.top == MAX - 1 ? true : false;
}    
void push(StackPtr S, char data){
    if(!isFullStack(*S)){
        S->top++;
        S->elems[S->top] = data;
    }
}
void pop(StackPtr S){
    if(!isEmptyStack(*S)){
        S->top--;
    }
}
char top(Stack S){
    if(!isEmptyStack(S)){
        return S.elems[S.top];
    }
    return '\0';
}
void pushUnique(StackPtr S, char data){
    Stack temp;
    for(temp = *S; !isEmptyStack(temp) && top(temp) != data; pop(&temp)){}
    if(isEmptyStack(temp)) push(S, data);
    else printf("\nS: Data is not Unique");
}   
void displayStack(Stack S){
    printf("\nStack Contents:");
    for(;!isEmptyStack(S); pop(&S)){
        printf("%c ", top(S));
    }       
}    
void popUnique(StackPtr S, char data){ //pop first occurance
    Stack temp;
    initStack(&temp);
    for(;!isEmptyStack(*S) && top(*S) != data; push(&temp, top(*S)), pop(S)){}
    if(isEmptyStack(*S)) printf("\nS: No occurance of entry was found.");
    else pop(S);
    for(;!isEmptyStack(temp); push(S, top(temp)), pop(&temp)){}
}    
#endif