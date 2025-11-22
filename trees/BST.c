#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node* left;
    struct node* right;
    int data;
}Node, *NodePtr;

typedef struct
{
    NodePtr head;
}BST;

void init(BST* b){
    b->head = NULL;
}

void insert(BST* b, int data){
    NodePtr *trav;
    for(trav = &b->head;*trav != NULL && (*trav)->data != data;){
        if(data > (*trav)->data){
            trav = &(*trav)->right;
        }else{
            trav = &(*trav)->left;
        }
    }
    if(*trav == NULL){
        NodePtr newNode = malloc(sizeof(Node));
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->data = data;
        *trav = newNode;
    } 
}

void delete(BST* b, int data){
    //find data as root
    NodePtr *newRoot;
    for(newRoot = &b->head; *newRoot != NULL && (*newRoot)->data != data;){
        if(data > (*newRoot)->data){
            newRoot = &(*newRoot)->right;
        }else{
            newRoot = &(*newRoot)->left;
        }   
    }
    if(*newRoot != NULL){
        NodePtr toBeDeleted = *newRoot;
        
        //parent has no child
        if((*newRoot)->left == NULL && (*newRoot)->right == NULL){
            *newRoot = NULL;
        }
        
        //parent has only one child
        else if((*newRoot)->left == NULL && (*newRoot)->right == NULL){
            if((*newRoot)->left != NULL){
                *newRoot = (*newRoot)->left;
            }else{
                *newRoot = (*newRoot)->right;
            }
        }
        
        //parent has 2 children
        else{
            //using successor
            NodePtr *trav = &(*newRoot)->right;  
            for(;(*trav)->left != NULL; trav = (*trav)->left);
            NodePtr temp = *trav;
            NodePtr tempRight = (*trav)->right;
            temp->left = (*newRoot)->left;
            temp->right = (*newRoot)->right;
            *newRoot = temp;            
            *trav = tempRight;
        }

        free(toBeDeleted);
    }
}

void delete(BST* b, int data){
    NodePtr *newRoot;
    for(newRoot = &b->head; *newRoot != NULL && (*newRoot)->data != data;){
        if(data > (*newRoot)->data){
            newRoot = &(*newRoot)->right;
        }else{
            newRoot = &(*newRoot)->left;
        }   
    }
    if(*newRoot != NULL){
        NodePtr toBeDeleted = *newRoot;
        
        // No children
        if((*newRoot)->left == NULL && (*newRoot)->right == NULL){
            *newRoot = NULL;
        }
        
        // One child
        else if((*newRoot)->left == NULL || (*newRoot)->right == NULL){
            if((*newRoot)->left != NULL){
                *newRoot = (*newRoot)->left;
            }else{
                *newRoot = (*newRoot)->right;
            }
        }
        
        // Two children
        else{
            NodePtr *successorParent = &(*newRoot)->right;
            while((*successorParent)->left != NULL){
                successorParent = &(*successorParent)->left;
            }
            NodePtr successor = *successorParent;
            *successorParent = successor->right; // Remove successor from its position
            
            successor->left = (*newRoot)->left;
            successor->right = (*newRoot)->right;
            *newRoot = successor;
        }

        free(toBeDeleted);
    }
}