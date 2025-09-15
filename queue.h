#ifndef DEFAULT_FUNCTIONS_H
#define DEFAULT_FUNCTION_H
#define MAX 10

typedef struct{
    char elems[MAX];
    int f;
    int r;
}Queue, *QueuePtr;

void initQueue(QueuePtr Q){
    Q->f = 0;
    Q->r = -1;
}

void dequeueUnique(QueuePtr Q){
    
}

#endif