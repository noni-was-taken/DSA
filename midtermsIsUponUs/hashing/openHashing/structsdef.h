#ifndef STRUCTSDEF_H
#define STRUCTSDEF_H

#define maxHash 64
#define maxString 20

typedef struct{
    char fname[maxString];
    char lname[maxString];
}name;

typedef struct{
    int id;
    name fullName;
}student;

typedef struct node{
    student data;
    struct node* next;
}Node, *NodePtr;

typedef NodePtr Dictionary[maxHash];

#endif