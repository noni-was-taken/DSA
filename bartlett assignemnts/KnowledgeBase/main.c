#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#include "cursorBased.h"

typedef int List;

void insertArticle(VHeap* vh, List *L, Article data, int ndx);   
void displayArticles(VHeap* vh, List L);
void deleteArticle(VHeap* vh, List* L, int id);
Article searchArticles(VHeap* vh, List L, int id);


int main(){
    Article data;
    int intData;
    char choice;
    VHeap vh;
    List L = -1;
    initVHeap(&vh);
    while(tolower(choice) != 'e'){
        printf("\nA.insert data  B.delete  data  C.display data  D.search data  E.exit\n");
        scanf(" %c", &choice);
        switch(tolower(choice)){
            case 'a':
                printf("\nID: ");
                scanf(" %d", &data.id);
                printf("Title: ");
                scanf(" %s", &data.title);
                printf("Content: ");
                scanf(" %s", &data.content);

                printf("\nWhat position would u like to put this?\n");
                scanf(" %d", &intData);

                insertArticle(&vh, &L, data, intData);
                break;
            case 'b':
                printf("\nID to delete: ");
                scanf(" %d", &intData);
                
                deleteArticle(&vh, &L, intData);
                break;
            case 'c':
                printf("\nDisplaying data...\n");
                displayArticles(&vh, L);

                break;
            case 'd':
                printf("\nID for search: ");
                scanf(" %d", &intData);
                data = searchArticles(&vh, L, intData);
                if(data.id != -1){
                    printf("\nID: %d\n", data.id);
                    printf("Title: %s\n", data.title);
                    printf("Body: %s\n", data.content);
                }
                break;
        }
    }
    return 0;
}

void insertArticle(VHeap* vh, List *L, Article data, int ndx){
    int newNode = alloc(vh);
    if(newNode != -1){
        vh->H[newNode].data = data;
        if(ndx == -1){
            if(*L == -1){
                vh->H[newNode].next = -1;
                *L = newNode;
            }else{
                int trav;
                for(trav = *L; vh->H[trav].next != -1; trav = vh->H[trav].next){}
                vh->H[newNode].next = vh->H[trav].next;
                vh->H[trav].next = newNode;
            }
        }else{
            if(ndx == 0){
                vh->H[newNode].next = *L;
                *L = newNode;    
            }else{
                int trav, count = 0;
                for(trav = *L; trav != -1 && count < ndx; trav = vh->H[trav].next, count++){}
                if(trav != -1){
                    vh->H[newNode].next = vh->H[trav].next;
                    vh->H[trav].next = newNode;
                }else{
                    printf("\nPosition not found.");
                }
            }
        }
    }
    
}   

void displayArticles(VHeap* vh, List L){
    printf("\nArticles:\n");
    for(;L != -1; L = vh->H[L].next){
        printf("\nID: %d\n", vh->H[L].data.id);
        printf("Title: %s\n", vh->H[L].data.title);
        printf("Body: %s\n", vh->H[L].data.content);

        printf("-----------------------------------\n");
    }
}

void deleteArticle(VHeap* vh, List* L, int id){ 
    int trav;
    for(trav = *L; trav != -1 && vh->H[trav].data.id != id; trav = vh->H[trav].next){}
    if(trav != -1){
        if(trav == *L){
            int temp = *L;
            *L = vh->H[temp].next;
            dealloc(vh, temp);
        }else{
            int trav2;
            for(trav2 = *L; trav2 != -1 && vh->H[trav2].next != trav; trav2 = vh->H[trav2].next);
            if(trav2 != -1){
                int temp = trav;
                vh->H[trav2].next = vh->H[trav].next;
                dealloc(vh, temp);
            }
        }
    }else{
        printf("\ndata not found.");
    }
}

Article searchArticles(VHeap* vh, List L, int id){
    int trav;
    Article retVal;
    for(trav = L; trav != -1 && vh->H[trav].data.id != id; trav = vh->H[trav].next){}
    if(trav != -1){
        retVal = vh->H[trav].data;
    }else{
        printf("\nData not found.");
        retVal.id = -1;
    }
    return retVal;
}