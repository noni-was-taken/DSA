#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define max 10

typedef struct{
    int arr[max];
    int count;
}heap;

void displayHeap(heap);

void init(heap*);

void insert(heap*, int);

int main(){
    heap tree;
    init(&tree);

    int input = 10;
    while(input){
        printf("Insert Value: ");
        scanf("%d", &input);
        insert(&tree, input);
    }

    displayHeap(tree);
    return 0;
}

void displayHeap(heap tree){
    int count = 0;
    for(int i = 0; i < max; i++){
        printf("%d ", tree.arr[i]);
    }
}

void init(heap* tree){
    for(int i = 0; i < max; i++){
        tree->arr[i] = 0;
    }
    tree->count = 0;
}

void insert(heap* tree, int data){
    if(tree->count < max){
        tree->arr[tree->count] = data;
        int child = tree->count;
        while(child > 0){
            int parent = (child - 1) / 2;
            if(tree->arr[parent] < tree->arr[child]){
                int temp = tree->arr[parent];
                tree->arr[parent] = tree->arr[child];
                tree->arr[child] = temp;
                child = parent;
            } else {
                child = 0;
            }
            
        }
        tree->count++;
    }else{
        printf("Cannot input value.\n");
    }
}