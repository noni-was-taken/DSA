#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define max 64

typedef struct{
    char colorName[20];
    int RGBval[3];
}color;

typedef struct Node{
    color data;
    struct Node *next;
}node, *nodePtr;

typedef nodePtr palette[max];

void insert(palette, color);
void delete(palette, char*);
color search(palette, char*);
void initDict(palette);
int hash(color);
void display(palette);

int main(){
    palette a;
    initDict(a);

    // A bigger set of colors (30+) to really test collisions
    color colors[] = {
        {"Red",       {255, 0, 0}},
        {"Green",     {0, 255, 0}},
        {"Blue",      {0, 0, 255}},
        {"Yellow",    {255, 255, 0}},
        {"Cyan",      {0, 255, 255}},
        {"Magenta",   {255, 0, 255}},
        {"Orange",    {255, 165, 0}},
        {"Purple",    {128, 0, 128}},
        {"Pink",      {255, 192, 203}},
        {"Brown",     {165, 42, 42}},
        {"Gray",      {128, 128, 128}},
        {"Black",     {0, 0, 0}},
        {"White",     {255, 255, 255}},
        {"Maroon",    {128, 0, 0}},
        {"Olive",     {128, 128, 0}},
        {"Navy",      {0, 0, 128}},
        {"Teal",      {0, 128, 128}},
        {"Lime",      {191, 255, 0}},
        {"Indigo",    {75, 0, 130}},
        {"Violet",    {238, 130, 238}},
        {"Gold",      {255, 215, 0}},
        {"Silver",    {192, 192, 192}},
        {"Beige",     {245, 245, 220}},
        {"Coral",     {255, 127, 80}},
        {"Turquoise", {64, 224, 208}},
        {"Khaki",     {240, 230, 140}},
        {"Lavender",  {230, 230, 250}},
        {"Salmon",    {250, 128, 114}},
        {"Crimson",   {220, 20, 60}},
        {"Mint",      {189, 252, 201}},
        {"Azure",     {240, 255, 255}},
        {"Ivory",     {255, 255, 240}}
    };

    int n = sizeof(colors) / sizeof(colors[0]);

    // Insert all colors
    for(int i = 0; i < n; i++){
        insert(a, colors[i]);
    }

    printf("\n--- Display after inserting %d colors ---\n", n);
    display(a);

    return 0;
}


void initDict(palette a){
    for(int i = 0; i < max; i++){
        a[i] = NULL;
    }
}

void insert(palette a, color n){
    int index = hash(n);
    
    nodePtr newNode = malloc(sizeof(node));
    newNode->data = n;
    newNode->next = NULL;
    
    if(a[index] == NULL){
        a[index] = newNode;
    }else{
        nodePtr *trav;
        for(trav = &a[index]; (*trav) != NULL ; trav = &(*trav)->next);
        *trav = newNode;
    }
}

void delete(palette a, char* name){
    bool flag = false;
    for(int i = 0; i < max && !flag; i++){
        nodePtr *trav, temp;
        for(trav = &a[i]; *trav != NULL && strcmp((*trav)->data.colorName, name) ; trav = &(*trav)->next);
        if(*trav != NULL){
            temp = *trav;
            *trav = temp->next;
            free(temp);
            flag = true;
        }
    }
    if(!flag) printf("\nCould not find color with name %s");
}

color search(palette a, char* name){
    color retVal = {"", {-1, -1,}};
    bool flag = false;
    for(int i = 0; i < max && !flag; i++){
        nodePtr *trav;
        for(trav = &a[i]; *trav != NULL && strcmp((*trav)->data.colorName, name) != 0; trav = &(*trav)->next);
        if(*trav != NULL){
            retVal = (*trav)->data;
            flag = true;
        }
    }
    if(!flag){
        printf("\nCould not find color with name %s");
    } 
    return retVal;
}

int hash(color rgb){
    return (rgb.RGBval[0] + rgb.RGBval[1] + rgb.RGBval[2])%64;
}

void display(palette a){
    for(int i = 0; i < max; i++){
        if(a[i] != NULL){
            printf("[%02d] -> ", i);  // only non-empty buckets
            nodePtr trav = a[i];
            while(trav != NULL){
                printf("%s(%d,%d,%d) -> ",
                       trav->data.colorName,
                       trav->data.RGBval[0],
                       trav->data.RGBval[1],
                       trav->data.RGBval[2]);
                trav = trav->next;
            }
            printf("NULL\n");
        }
    }
}