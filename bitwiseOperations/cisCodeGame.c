/*
The 8-Lane Subway Track, Meets A Surfer

You were minding your business, *LEGALLY* Graffitiing a cool design on a subway track, then suddenly 
you hear a loud whistle and a dog barking. In your peripheral vision, you see a misunderstood policeman 
and his pitbull terrier running in your direction. The policeman didn't know you had been permitted to 
decorate the subway walls, and the anger on the face of the policeman suggests that he is ready to be violent.


As if your body moved on its own, you bolt in the opposite direction from where the policeman is running. 
But after a few meters of running, you are greeted with 7 inactive trains, blocking the way for all except 
one track. You then noticed that after those 7 trains, there are even more trains blocking the tracks. You 
are to navigate your way out of the subway to ask for help before the policeman beats you up.


There are 5 sets of trains that you have to go through, and each set will look like this:
1 1 1 1 0 1 1 1
1 = train, 0 = no train


You, the surfer, will start from the very left side, looking like this:
1 0 0 0 0 0 0 0


TASK:
You are going to design an algorithm that will find the right path and shift yourself to dodge the trains and escape. 
The function for your algorithm will return an array of integers determining the number of shifts.
Positive means you shift to the right, while negative means you shift to the left.



For example:
1 0 0 0 0 0 0 0 <--- You

1 1 1 1 0 1 1 1 <--- 1st set
1 0 1 1 1 1 1 1 <--- 2nd set
1 1 1 0 1 1 1 1 <--- 3rd set
1 1 1 1 1 1 0 1 <--- 4th set
1 1 1 1 0 1 1 1 <--- 5th set

Shifts:
1st --> 4 --> >>=4
2nd --> -3 --> <<=3
3rd --> 2 --> >>=2
4th --> 3 --> >>=3
5th --> -2 --> <<=2
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void displayRoad(char trains[], unsigned char surfer);
void testCode(char trains[], int cases);
bool escapeAttempt(char trains[],unsigned char surfer, int* moves);
int *shiftingSides(char trains[], unsigned char surfer);

int main(){
    char trains[5];
    unsigned char surfer = 128;

    int testCase;
    printf("What test case would you like to try?\n");
    printf("1, 2, 3, or 4?\n");
    scanf(" %d", &testCase);    
    
    testCode(trains, testCase);
      
    displayRoad(trains, surfer);

    int *moves;
    moves = shiftingSides(trains, surfer);
    printf("\n\n");
    for(int i = 0; i < 5; i++){
        printf("%d ", moves[i]);
    }

    printf(escapeAttempt(trains, surfer, moves) ?  "\nYou escaped!" : "\nYou hit a train... ouch.");
    return 0;
}

int *shiftingSides(char trains[], unsigned char surfer){
    int *returnValue = malloc(sizeof(int)*5);
    //implement logic here
    int curr, path;
    unsigned char tempSurfer = surfer;
    for(int i = 0; i < 5; i++){
        curr = -1;
        for(int j = 0, mask = 128; mask; j++, mask >>= 1){
            if(tempSurfer & mask) curr = 7 - j;
        }
        path = -1;
        for(int j = 0, mask = 128; mask; j++, mask >>= 1){
            if((trains[i] & mask) == 0) path = 7 - j;
        }
        
        returnValue[i] = curr - path;

        if(returnValue[i] >= 0){
            tempSurfer >>= returnValue[i];
        }else{
            tempSurfer <<= -returnValue[i];
        }
    }
    return returnValue;
}

void displayRoad(char trains[], unsigned char surfer){
    printf("\nYour current position:\n");
    for(int mask = 1<<7; mask; mask >>=1){
        printf("%d ", (surfer&mask) ? 1 : 0);
    }
    printf("\nThe Tracks Ahead:\n");
    for(int i = 0; i < 5; i++){
        for(int mask = 1<<7; mask; mask >>=1){
            printf("%d ", (trains[i]&mask) ? 1 : 0);
        }
        printf("\n");
    }
}

void testCode(char trains[], int cases){
    switch(cases){
        case 1:
            trains[0] = 247;
            trains[1] = 223;
            trains[2] = 254;
            trains[3] = 127;
            trains[4] = 253;
            break;
        case 2:
            trains[0] = 127;  
            trains[1] = 191;   
            trains[2] = 223;   
            trains[3] = 239;   
            trains[4] = 247;   
            break;
        case 3:
            trains[0] = 251;   
            trains[1] = 253;   
            trains[2] = 254;   
            trains[3] = 254;   
            trains[4] = 127;   
            break;
        case 4:
            trains[0] = 254;   
            trains[1] = 254;    
            trains[2] = 254;    
            trains[3] = 254;    
            trains[4] = 254;    
            break;
        case 5:
            trains[0] = 127; 
            trains[1] = 127; 
            trains[2] = 127; 
            trains[3] = 127; 
            trains[4] = 127; 
            break;
        default:
            break;
        }
}

bool escapeAttempt(char trains[],unsigned char surfer, int* moves){
    bool stat = true;
    for(int i = 0; i < 5; i++){
        if(moves[i] >= 0){
            surfer >>= moves[i];
        }else{
            surfer <<= -moves[i];
        }
        if((trains[i] & surfer || surfer == 0) != 0) stat = false;
    }
    return stat;
}

