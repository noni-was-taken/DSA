#include<stdio.h>
#include<ctype.h>

int hash1(int);

int hash2(char*);

int hash3(int, int, int);

int main(){
    int input;
    printf("input a number that is atleast greater than 99: ");
    scanf("%d", &input);
    printf("Magic number: %d", hash1(input));

    char cInput[20];
    printf("enter thy surname: ");
    scanf(" %s", &cInput);
    printf("Magic number 2: %d", hash2(cInput));
    
    int r, g, b;
    printf("enter the crazy values of: ");
    scanf(" %d", &r);
    scanf(" %d", &g);
    scanf(" %d", &b);
    printf("Magic number 3: %d", hash3(r,g,b));

    return 0;
}

int hash1(int n){
    return (n%1000) / 100;
}

int hash2(char *s){
    return toupper(s[0]) - 65;
}

int hash3(int r, int g, int b){
    return (r + g + b)%64;
}