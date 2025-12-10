#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define max 26

typedef struct node{
    char data;
    struct node* next;
}Node, *NodePtr;

typedef NodePtr Dictionary[26];

void initDict(Dictionary d){
    for(int i = 0; i < max; i++){
        d[i] = NULL;
    }
}

int hash(char data){
    return (toupper(data) - 'A')%26;
}

void insert(Dictionary d, char data){
    int index = hash(data);
    
    NodePtr new = malloc(sizeof(Node));
    if(new == NULL){
        exit(1);
    }
    new->data = data;
    new->next = d[index];

    d[index] = new;
}

bool delete(Dictionary d, char data){
    int index = hash(data);
    NodePtr *trav = &d[index];

    for(;*trav != NULL && (*trav)->data != data; trav = &(*trav)->next){}
    if(*trav == NULL){
        return false;
    }else{
        NodePtr temp = *trav;
        *trav = (*trav)->next;
        free(temp);
    }

    return true;
}

int main(){
    char string[max];
    char string2[max];

    printf("Input 1: ");
    scanf(" %s", string);
   
    printf("\nInput 2: ");
    scanf(" %s", string2);

    //checker
    bool dies = false;
    int len =  strlen(string);
    if(len == strlen(string2)){
        Dictionary tralele;
        initDict(tralele);

        for(int i = 0; i < len; i++){
            insert(tralele, string[i]);
        }
        for(int i = 0; i < len; i++){
            if(!delete(tralele, string2[i])){
                dies = true;
                break;
            }
        }
    
    }else{
        dies = true;
    }

    if(!dies){
        printf("\nstrings are anagram");
    }else{
        printf("\nstrings are not anagram");
    }
    // printf("%d", strcmp(string, string2));

    return 0;
}