#include<stdio.h>
#include<stdbool.h>

#define max 20
#define empty -1

typedef struct{
    int data[max];
    int size; //how many inside rn (*/ω＼*)
    int capacity; //max
}Tree;

void initTree(Tree*);
void insert(Tree*, int); //tree and data
void heapifyUP(Tree*, int); //tree and index || up heapify
void heapifyDOWN(Tree*, int); //tree and index || up heapify
void heapsort(Tree*); //print na ni lods, sorted nang array human ani ghurt
void print(Tree);

void initTree(Tree*TUNG){
    for(int i = 0; i < max; i++){
       TUNG->data[i] = empty;
    }
   TUNG->size = 0;
   TUNG->capacity = max;
}

int main(){
    Tree groot;

    initTree(&groot);
    insert(&groot, 5);  
    insert(&groot, 6);  
    insert(&groot, 10);  
    insert(&groot, 11);  
    insert(&groot, 23);  
    insert(&groot, 54);  
    insert(&groot, 67);  
    insert(&groot, 89);  
    insert(&groot, 101);  
    insert(&groot, 113);  
    insert(&groot, 80085);  
    insert(&groot, 696961);  
    insert(&groot, 0);  

    print(groot);
    heapsort(&groot);
    print(groot);
}

//insert last ni nigga
void insert(Tree*TUNG, int data){
    if(TUNG->size !=TUNG->capacity){
        int index =TUNG->size++;
       TUNG->data[index] = data;
        heapifyUP(TUNG, index);
    }
}

void heapifyUP(Tree*TUNG, int index){
    while(index){
        int parent = (index - 1)/2;

        if(TUNG->data[parent] < TUNG->data[index]){
            int temp = TUNG->data[index];
            TUNG->data[index] = TUNG->data[parent];
            TUNG->data[parent] = temp;
        }else{
            break;
        }

        index = parent;
    }    
}

void heapifyDOWN(Tree*TUNG, int index){
    while(1){
        int biggest = index;
        int left = (index*2) + 1;
        int right = (index*2) + 2;

        if(left < TUNG->size && TUNG->data[left] > TUNG->data[biggest]){
            biggest = left;
        }

        if(right < TUNG->size && TUNG->data[right] > TUNG->data[biggest]){
            biggest = right;
        }

        if(biggest == index){
            break;
        }else{
            int temp = TUNG->data[biggest];
            TUNG->data[biggest] = TUNG->data[index];
            TUNG->data[index] = temp;
        }
        
        index = biggest;
    }
    print(*TUNG);
}
//
void heapsort(Tree*TUNG){
    int og = TUNG->size;
    while(TUNG->size){
        TUNG->size--;
        int temp = TUNG->data[TUNG->size];
        TUNG->data[TUNG->size] = TUNG->data[0];
        TUNG->data[0] = temp;

        //print(*TUNG);

        heapifyDOWN(TUNG, 0);
    }
    TUNG->size = og;
}

void print(Tree SAHUR){
    printf("\narray nimo niga:");
    for(int i = 0; i < SAHUR.size; i++){
        printf("%d ", SAHUR.data[i]);
    }
}