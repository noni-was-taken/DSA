#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>


#define MAX 12

int main(){
    char string[MAX] = "Hello World";
    char tobeString[MAX] = {0};

    for(int i = 0; i < MAX; i++){
        for(;string[i] != tobeString[i];){
            tobeString[i]++;
            printf("%s\n", tobeString);
            Sleep(10); // Windows Sleep uses milliseconds
        }
    }

    return 0;
}