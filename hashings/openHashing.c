#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxString 20
#define MAX 64

typedef struct{
    int id; 
    char fName[maxString];
    char lName[maxString];
}student;   

typedef struct node{
    student data;
    struct node *next;
}Node, *NodePtr;

typedef NodePtr Dictionary[MAX];


void initDict(Dictionary);

void insertStudent(Dictionary, int, char*, char*);

int hash(char*, char*);

void displayStudents(Dictionary d);

#include "test.h"

int main(){
    Dictionary dict;
    initDict(dict);
    /* run automated tests from test.h - returns number of failures */
    int failures = run_open_hashing_tests(dict);

    printf("\nTests completed: %d failure(s)\n", failures);

    /* show final dictionary state */
    displayStudents(dict);
    return 0;
}



void initDict(Dictionary d){

    for(int i = 0; i < MAX; i++){
        d[i] = NULL;
    }
    printf("\n> Dictionary Initialized.");
}

int hash(char *lName, char *fName){
    return (((int)lName[0])*89 + ((int)fName[0])*71)%MAX;
}

void insertStudent(Dictionary d, int id, char *lname, char *fname){
    int idx = hash(lname, fname);

    student s;
    s.id = id;
    strcpy(s.lName, lname);
    strcpy(s.fName, fname);
    
    
    NodePtr newNode = malloc(sizeof(Node));
    newNode->next = d[idx];
    newNode->data = s;
    
    d[idx] = newNode;

    printf("\nStudent Inserted");
}

void displayStudents(Dictionary d){
    printf("Dictionary:");
    for(int i = 0; i < MAX; i++){
        if(d[i] != NULL){
            printf("\n<%d> = ", i);
            NodePtr trav;
            for(trav = d[i]; trav != NULL; trav = trav->next){
                printf("[%d] %s, %s", trav->data.id, trav->data.lName, trav->data.fName);
                if(trav->next != NULL){
                    printf(" -> ");
                }
            } 
        }
    }
}