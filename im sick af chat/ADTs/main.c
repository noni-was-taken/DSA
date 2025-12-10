#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// #include "stackArr.h"
// #include "stackLL.h"
// #include "queueArr.h"
// #include "queueLL.h"
#include "ADTList.h"
#include "test.h"

int main() {
    // StackPtr S = (StackPtr) malloc(sizeof(Stack));
    // QueuePtr Q = (QueuePtr) malloc(sizeof(Queue));

    // initStack(S);
    // initQueue(Q);

    // testStack(S);
    // testQueue(Q);

    // free(S);
    // free(Q);
    // return 0;

    NodePtr list;
    initializeList(&list);
    insertAt(&list, 0, 'A');
    insertAt(&list, 1, 'B');
    insertAt(&list, 2, 'C');
    display(list); // Expected: A B C
    deleteIndex(&list, 1);
    display(list); // Expected: A C
    insertLastUnique(&list, 'C'); // Should print "Data is not unique"
    insertLastUnique(&list, 'D');
    display(list); // Expected: A C D
    deleteData(&list, 'C');
    display(list); // Expected: A D
    return 0;

}
