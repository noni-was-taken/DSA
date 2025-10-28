#ifndef DSA_ADTLIST_H
#define DSA_ADTLIST_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> 

typedef struct node{
    char data;
    struct node* next;
}Node, *NodePtr;

//init
void initializeList(NodePtr *n){
    *n = NULL;
}

//isEmpty
bool isEmpty(NodePtr n){
    return n == NULL;
}

//insertInx
void insertAt(NodePtr *n, int ndx, char data){
    NodePtr newNode = (NodePtr) malloc(sizeof(Node));
    if(newNode == NULL){
        printf("\nMemory allocation failed");
        exit(1);
    }
    newNode->data = data;
    if(!isEmpty(*n)){
        NodePtr *trav = n;
        for(int count = 0; *trav != NULL && count < ndx; count++, trav = &(*trav)->next){}
        if(*trav == NULL){
            printf("\nInserting last...");
        }
        newNode->next = *trav;
        *trav = newNode;
    }else{
        newNode->next = NULL;
        *n = newNode;
    }
} 


//deleteIndex
void deleteIndex(NodePtr *n, int ndx){
    if(!isEmpty(*n)){
        if(ndx == 0){
            NodePtr temp = *n;
            *n = temp->next;
            free(temp);
        }else{
            NodePtr *trav = n;
            for(int count = 0; (*trav)->next != NULL && count < ndx-1; count++, trav = &(*trav)->next){}
            if((*trav)->next != NULL){
                NodePtr temp = (*trav)->next;
                (*trav)->next = temp->next;
                free(temp);
            }
        }
    }
} 

//returnValue
char returnValue(NodePtr n, int ndx){
    char retVal;
    if(!isEmpty(n)){
        for(int i = 0; n != NULL && i < ndx; n = n->next, i++){}
        if(n == NULL){
            printf("\nThe list has no index %d", ndx);
            retVal = '\0';
        }else{
            retVal = n->data;
        }
    }else{
        printf("\nList is empty");
        retVal = '\0';
    }
    return retVal;
}

//insertLastUnique
void insertLastUnique(NodePtr *n, char data){
    NodePtr *trav;
    for(trav = n; *trav != NULL && (*trav)->data != data; trav = &(*trav)->next){}
    if(*trav == NULL){
        NodePtr newNode = malloc(sizeof(Node));
        if(newNode == NULL){
            printf("\nMemory allocation failed");
            exit(1);
        }
        newNode->data = data;
        newNode->next = NULL;
        (*trav) = newNode; 
    }else{
        printf("\nData is not unique");
    }
}

//deleteData
void deleteData(NodePtr *n, char data){
    NodePtr *trav;
    for(trav = n; *trav != NULL && (*trav)->data != data; trav = &(*trav)->next){}
    if(*trav != NULL){
        NodePtr temp = *trav;
        *trav = temp->next;
        free(temp);
    }else{
        printf("\nData not found");
    }
}


//display
void display(NodePtr n){
    printf("\nList Contents: ");
    for(;n != NULL;n = n->next){
        printf("%c ", n->data);
    }
}


#endif