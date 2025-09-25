/*
The 8-Lane Subway Track, Meets A Surfer

You were minding your business, *LEGALLY* Graffitiing a cool design on a subway track
then suddenly you hear a loud whistle and a dog barking. On your peripheral vision,
you see a misunderstood policeman and his pitbull terrier running on your direction.
The policeman didn't know you were given permission to decorate the subway walls, and by
the anger seen on the face of the policeman, he seems ready to be violent.

As if your body moved on its own, you bolt right on the opposite direction of where the
policeman is running from. But after a few meters of running, you are greeted with 7 inactive
trains, blocking the way except for all except one track. You then noticed that after those 7 trains
there are even more trains blocking the tracks. You are to navigate your way out of the subway
to ask help before the policeman beats you up. 

There are 5 sets of trains that you have to go through, and each set will look like this:
1 1 1 1 0 1 1 1
1 = train, 0 = no train

You, the surfer, will start from the very left side looking like this:
1 0 0 0 0 0 0 0

You are going to design an algorithm that will find the right path
and shift yourself to dodge the trains and escape.


for example:
1 1 1 1 0 1 1 1 <--- 5th set
1 0 1 1 1 1 1 1 <--- 4th set
1 1 1 0 1 1 1 1 <--- 3rd set
1 1 1 1 1 1 0 1 <--- 2nd set
1 1 1 1 0 1 1 1 <--- 1st set

1 0 0 0 0 0 0 0 <--- You

Shifts:
1st --> >>=4
2nd --> >>=2
3rd --> <<=3
4th --> <<=2
5th --> >>=3
*/
#include<stdio.h>
#include<stdbool.h>
#include "testCase.h"

int main(){
    char trains[5];
    char surfer = 128;

    int testCase;
    printf("What test case would you like to try?\n");
    printf("1, 2, 3, or 4?\n");
    scanf(" %d", &testCase);    
    
    testCode(trains, testCase);
    
    displayRoad(trains, surfer);
}

int shiftingSides(char trains[], char surfer[]){
    //
}