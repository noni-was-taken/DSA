#include<stdio.h>
#include<ctype.h>

#define max 20

int main(){
    char input[3];
    while(input[0] != 'Z'){
        scanf("%s", &input);
        printf("hash = %d", ((input[0] - 'A') * 26 * 26 + (input[1] - 'A') * 26 + (input[2] - 'A'))%10);    
        printf("\n\n");
    }
    return 0;
}