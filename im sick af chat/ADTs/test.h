#ifndef TEST_H
#define TEST_H

// WARNING > ALL THE CODE HERE IS AI GENERATED TO TEST THE MAN-MADE FUNCTIONS IN THE HEADER FILES

#include <stdio.h>
#include "stackArr.h"
#include "queueArr.h"

void testStack(StackPtr S) {
    printf("\n--- Testing Stack ---");

    // Push A, B, C uniquely
    pushUnique(S, 'A');
    pushUnique(S, 'B');
    pushUnique(S, 'C');
    displayStack(*S);

    // Try pushing duplicate 'B'
    pushUnique(S, 'B');
    displayStack(*S);

    // Pop specific 'B'
    popUnique(S, 'B');
    displayStack(*S);

    // Pop specific 'Z' (not in stack)
    popUnique(S, 'Z');
    displayStack(*S);

    // Push more elements until full
    pushUnique(S, 'D');
    pushUnique(S, 'E');
    pushUnique(S, 'F');
    pushUnique(S, 'G');
    pushUnique(S, 'H');
    pushUnique(S, 'I');
    pushUnique(S, 'J');
    pushUnique(S, 'K'); // should not fit
    displayStack(*S);
}

void testQueue(QueuePtr Q) {
    printf("\n--- Testing Queue ---");

    // Enqueue A, B, C uniquely
    enqueueUnique(Q, 'A');
    enqueueUnique(Q, 'B');
    enqueueUnique(Q, 'C');
    displayQueue(*Q);

    // Try enqueue duplicate 'A'
    enqueueUnique(Q, 'A');
    displayQueue(*Q);

    // Dequeue specific 'B'
    dequeueUnique(Q, 'B');
    displayQueue(*Q);

    // Dequeue specific 'Z' (not in queue)
    dequeueUnique(Q, 'Z');
    displayQueue(*Q);

    // Fill queue until full
    enqueueUnique(Q, 'D');
    enqueueUnique(Q, 'E');
    enqueueUnique(Q, 'F');
    enqueueUnique(Q, 'G');
    enqueueUnique(Q, 'H');
    enqueueUnique(Q, 'I');
    enqueueUnique(Q, 'J');
    enqueueUnique(Q, 'K'); // should not fit
    displayQueue(*Q);
}

#endif
