#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include "arrayStack.h"

#define MAX 5

void pushContainer(Stack* s[], int data);

void popContainer(Stack* s[], int id);

void displayContainer(Stack s[]);

int main(){
    char choice;
    int data;
    Stack container[3];
    
    StackPtr conAdds[] = {&container[0], &container[1], &container[2]};

    for(int i = 0; i < 3; i++){
        initialize(&container[i]);
        container[i].stackID = i;
    }

    while(tolower(choice) != 'd'){
        printf("\nA.push  B.pop a stack  C.display  D.exit\n");
        scanf(" %c", &choice);

        switch(tolower(choice)){
            case 'a':
                printf("\nInput Data: ");
                scanf(" %d", &data);
                pushContainer(conAdds, data);
                break;
            case 'b':
                printf("\nInput ID");
                scanf(" %d", &data);
                popContainer(conAdds, data);
                break;    
            case 'c':
                printf("\nDisplaying data:\n");
                displayContainer(container);
                break;
        }   
    }   
    return 0;
}


void pushContainer(Stack* s[], int data){
    bool pushed = false;
    for(int i = 0; i < 3 && !pushed; i++){
        if(!isFull(*s[i])){
            push(s[i], data);
            pushed = !pushed;
        }
    }
    if(!pushed){
        printf("\nContainers are full");
    }    
}   

void popContainer(Stack* s[], int id){
    if(id < 3 && id > -1){
        if(!isEmpty(*s[id])){
            int data = pop(s[id]);
            printf("\ndata %d has been popped from container %d", data, id);
        }
    }
}

void displayContainer(Stack s[]){
    for(int i = 0; i < 3; i++){
        printf("\nContainer %d: ", i);
        display(s[i]);
    }
}