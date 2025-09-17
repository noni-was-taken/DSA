#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "stackArr.h"
// #include "stackLL.h"
// #include "queueArr.h"
#include "queueLL.h"
#include "test.h"

int main() {
    StackPtr S = (StackPtr) malloc(sizeof(Stack));
    QueuePtr Q = (QueuePtr) malloc(sizeof(Queue));

    initStack(S);
    initQueue(Q);

    testStack(S);
    testQueue(Q);

    free(S);
    free(Q);
    return 0;
}
