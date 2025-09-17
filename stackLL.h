#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    char data;
    struct node *next;
} Node, *NodePtr;

typedef struct {
    NodePtr top;
} Stack, *StackPtr;

void initStack(StackPtr S) {
    S->top = NULL;
}

bool isEmptyStack(Stack S) {
    return S.top == NULL;
}
void push(StackPtr S, char data) {
    NodePtr newNode = (NodePtr) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("\nS: Memory allocation failed");
        return;
    }
    newNode->data = data;
    newNode->next = S->top; 
    S->top = newNode; 
    printf("\nS: Added %c Successfully", data);
}

void pop(StackPtr S) {
    if (!isEmptyStack(*S)) {
        NodePtr temp = S->top;
        S->top = S->top->next;
        free(temp);
    }
}

char top(Stack S) {
    if (!isEmptyStack(S)) {
        return S.top->data;
    }
    return '\0'; 
}

// void pushUnique(StackPtr S, char data) {
//     NodePtr curr = S->top;
//     while (curr != NULL && curr->data != data) {
//         curr = curr->next;
//     }
//     if (curr == NULL) {
//         push(S, data);
//     } else {
//         printf("\nS: Data is not Unique");
//     }
// }

void pushUnique(StackPtr S, char data) {
    Stack temp;
    initStack(&temp);
    for(;!isEmptyStack(*S) && top(*S) != data; push(&temp, top(*S)), pop(S)){}
    if(isEmptyStack(*S)){
        for(;!isEmptyStack(temp); push(S, top(temp)), pop(&temp)){}
        push(S, data);
    }else{
        for(;!isEmptyStack(temp); push(S, top(temp)), pop(&temp)){}
        printf("\nS: Data is not unique");
    }
}

void displayStack(Stack S) {
    printf("\nStack Contents:");
    NodePtr curr = S.top;
    while (curr != NULL) {
        printf("%c ", curr->data);
        curr = curr->next;
    }
}

void popUnique(StackPtr S, char data){
    Stack temp;
    initStack(&temp);
    for(;!isEmptyStack(*S) && top(*S) != data; push(&temp, top(*S)), pop(S)){}
    if(!isEmptyStack(*S)){
        pop(S);
    }else{
        printf("\nS: No occurance of entry data");
    }
    for(;!isEmptyStack(temp); push(S, top(temp)), pop(&temp)){}
}


// void popUnique(StackPtr S, char data) { // pop first occurrence
//     if (isEmptyStack(*S)) {
//         printf("\nS: Stack is empty.");
//         return;
//     }
//     NodePtr curr = S->top;
//     NodePtr prev = NULL;
//     while (curr != NULL && curr->data != data) {
//         prev = curr;
//         curr = curr->next;
//     }
//     if (curr == NULL) {
//         printf("\nS: No occurrence of entry was found.");
//     } else {
//         if (prev == NULL) {
//             S->top = curr->next;
//         } else {
//             prev->next = curr->next;
//         }
//         free(curr);
//     }
// }

#endif
