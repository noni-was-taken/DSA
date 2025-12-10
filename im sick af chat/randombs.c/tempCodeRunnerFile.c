#include<stdio.h>



int main(){
    for(int i = 0; i < 10; i++){

        for(int j = 0; j < i; j++){
            printf(" ");
        }
        for(int j = i; j < 10; j++){
            printf("* ");
        }
        printf("\n");
    }
}