#include<stdio.h>

int main(){
    // int mango = 15;
    // //assumes there are 8 bits
    // int mask = 128;
    // for(int i = 0; i < 8; i++){
    //     printf("%d", (mango&mask>>i) ? 1 : 0);
    // }    

    char mango = 15;
    for(int mask = 1<<(sizeof(mango)*8-1); mask; mask >>= 1){
        printf("%d", mango&mask ? 1 : 0);
    }
    return 0;
}