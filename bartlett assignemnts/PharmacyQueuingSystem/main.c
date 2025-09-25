#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>

#include "arrayQueue.h"

void insertLine(QueuePtr q, int data);

void serviceLine(QueuePtr r, QueuePtr p);

void displayLines(QueuePtr r, QueuePtr p);

int main(){
    int data;
    char choice;

    Queue Regular;
    Queue Priority;

    initialize(&Regular);
    initialize(&Priority);

    int customerNumber = 1;
    while(tolower(choice) != 'd'){
        printf("\nA.new customer  B.service customer  C.display queues  D.exit\n");
        scanf(" %c", &choice);
        switch(tolower(choice)){
            case 'a':
                printf("\n1.Regular   2.Priority\n");
                scanf("%d", &data);
                if(data == 1) insertLine(&Regular, customerNumber);
                else insertLine(&Priority, customerNumber);
                customerNumber++;
                break;
            case 'b':
                printf("\nCalling in new customer.");
                serviceLine(&Regular, &Priority);
                break;
            case 'c':
                printf("\nDisplaying Lines\n");
                displayLines(&Regular, &Priority);
                break;
        }
    }

    
}


void insertLine(QueuePtr q, int data){
    if(!isFull(*q)){
        enqueue(q, data);
    }
    else printf("\nLine is Full");
}

void serviceLine(QueuePtr r, QueuePtr p){
    if(!isEmpty(*p)){
        dequeue(p);
    }else if(!isEmpty(*r)){
        dequeue(r);
    }else{
        printf("\nLines are empty");
    }
}

void displayLines(QueuePtr r, QueuePtr p){
    printf("\nRegular line:");
    displayQueue(*r);
    printf("\nPriority line:");
    displayQueue(*p);
}