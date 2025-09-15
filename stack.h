#ifndef DEFAULT_FUNCTIONS_H
#define DEFAULT_FUNCTION_H
#define MAX 10

typedef struct{
    char elems[MAX];
    int top;
}Stack, *StackPtr;

void initStack(StackPtr S){
    int top = -1;
}

void pushUnique(StackPtr S, char data){
    Stack temp;
    for(temp = *S; !isEmpty(temp) && top(temp) != data; pop(temp)){}
    if(isEmpty(temp)) push(S, data);
}

void displayStack(Stack S){
    printf("Stack Contents:");
    for(;!isEmpty(S); pop(S)){
        printf("%d ", top(S));
    }   
}

void popUnique(StackPtr S, char data){
    p
}

bool isEmpty(Stack S){
    return S.top == -1 ? true : false;
}

bool isFull(Stack S){
    return S.top == MAX - 1 ? true : false;
}

#endif