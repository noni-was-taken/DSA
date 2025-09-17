#ifndef CBSTACK_H
#define CBSTACK_H

#include<stdio.h>
#include<stdbool.h>

#define MAX 10

typedef int stack;

//initStack
void initStack(stack* S){
    *S = -1;
}

//isEmpty
bool isEmptyStack(stack S){
    return S == -1;
}  


//push
void push(VHeap* VH, stack* S, char data){
    stack temp = alloc(VH);
    if(temp != -1){
        VH->H[temp].data = data;
        VH->H[temp].next = *S;
        *S = temp;
    }
}

//pop
void pop(VHeap* VH, stack* S){
    if(!isEmptyStack(*S)){
        stack temp = *S;
        *S = VH->H[*S].next;
        dealloc(VH, temp);
    }
}

//top
char top(VHeap* VH, stack* S){
    return VH->H[*S].data;
}

//pushUnique
void pushUnique(VHeap* VH, stack* S, char data){
    stack temp; bool isUnique = false;
    initStack(&temp);
    for(;!isEmptyStack(*S) && top(VH, S) != data; push(VH, &temp, VH->H[*S].data), pop(VH, S)){}
    if(isEmptyStack(*S)) isUnique = true;
    for(;!isEmptyStack(temp); push(VH, S, VH->H[temp].data), pop(VH, &temp)){}
    if(isUnique) push(VH, S, data);
}

//displayStack
void displayStack(VHeap VH, stack S){
    printf("CBStack Contents: ");
    for(;!isEmptyStack(S); pop(&VH, &S)){
        printf("%c ", VH.H[S].data);
    }
}

//popUnique
void popUnique(VHeap* VH, stack* S, char data){
    stack temp;
    initStack(&temp);
    for(;!isEmptyStack(*S) && top(VH, S) != data; push(VH, &temp, VH->H[*S].data), pop(VH, S)){}
    if(!isEmptyStack(*S)){
        pop(VH, S);
    }
    for(;!isEmptyStack(temp); push(VH, S, VH->H[temp].data), pop(VH, &temp)){}
}


#endif