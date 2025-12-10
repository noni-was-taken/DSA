#include<stdio.h>
#include<stdbool.h>

#define max 15

//this heapsorts assumes that the array exists and is not sorted

typedef struct{
    int arr[max];
    int size;
    int capacity;
}List;

void initTest(List *l){
    int testCase[] = {51,67,89,2,5,87,2,8,62,1,22,7,3,23,6};
    for(int i = 0; i < max; i++){
        l->arr[i] = testCase[i];
    }
    l->size = 15;
    l->capacity = 15;
}

void heapify(List *l, int index){
    bool isHeapifying = true;
    
    for(;isHeapifying;){
        int largest = index;
        int left = 2*index + 1;
        int right = 2*index + 2;

        if(left < l->size && l->arr[left] > l->arr[largest]){
            largest = left;
        }
        
        if(right < l->size && l->arr[right] > l->arr[largest]){
            largest = right;
        }

        if(index == largest){
            isHeapifying = false;
        }else{
            int temp = l->arr[largest];
            l->arr[largest] = l->arr[index];
            l->arr[index] = temp;
        }

        index = largest;
    }
}

void heapSort(List *l){
    int n = l->size;
    for(int i = n/2-1; i >= 0;  i--){
        heapify(l, i);
    }

    for(int i = n-1; i > 0; i--){
        int temp = l->arr[0];
        l->arr[0] = l->arr[i];
        l->arr[i] = temp;

        l->size = i;
        heapify(l, 0);
    }

    l->size = n;
}

int main(){
    List newList;
    
    initTest(&newList);

    printf("Presort: ");
    for(int i = 0; i < newList.size; i++){
        printf("%d ", newList.arr[i]);
    }
    
    heapSort(&newList);

    printf("\nAftersort: ");
    for(int i = 0; i < newList.size; i++){
        printf("%d ", newList.arr[i]);
    }
}
