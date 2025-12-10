#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node* left;
    struct node* right;
    int data;
}Node, *NodePtr;

typedef NodePtr BST;

void init(BST* b){
    (*b) = NULL;
}

void insert(BST* b, int data){
    // NodePtr *trav;
    // for(trav = &b->head;*trav != NULL && (*trav)->data != data;){
    //     if(data > (*trav)->data){
    //         trav = &(*trav)->right;
    //     }else{
    //         trav = &(*trav)->left;
    //     }
    // }
    // if(*trav == NULL){
    //     NodePtr newNode = malloc(sizeof(Node));
    //     newNode->left = NULL;
    //     newNode->right = NULL;
    //     newNode->data = data;
    //     *trav = newNode;
    // } 

    if(*b == NULL){
        NodePtr newNode = malloc(sizeof(Node));
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->data = data;

        *b = newNode; 
    }else{
        if((*b)->data < data){
            insert(&(*b)->right, data);
        }else{
            insert(&(*b)->left, data);
        }
    }


}

// void delete(BST* b, int data){
//     //find data as root
//     NodePtr *subRoot;
//     for(subRoot = &b->head; *subRoot != NULL && (*subRoot)->data != data;){
//         if(data > (*subRoot)->data){
//             subRoot = &(*subRoot)->right;
//         }else{
//             subRoot = &(*subRoot)->left;
//         }   
//     }
//     if(*subRoot != NULL){
//         NodePtr toBeDeleted = *subRoot;
        
//         //parent has no child
//         if((*subRoot)->left == NULL && (*subRoot)->right == NULL){
//             *subRoot = NULL;
//         }
        
//         //parent has only one child
//         else if((*subRoot)->left == NULL || (*subRoot)->right == NULL){
//             if((*subRoot)->left != NULL){
//                 *subRoot = (*subRoot)->left;
//             }else{
//                 *subRoot = (*subRoot)->right;
//             }
//         }
        
//         //parent has 2 children
//         else{
//             //using successor
//             NodePtr *sp = &(*subRoot)->right;
//             for(;(*sp)->left != NULL; sp = &(*sp)->left);

//             NodePtr successor = *sp;
//             *sp = (*sp)->right;

//             successor->right = (*subRoot)->right; 
//             successor->left = (*subRoot)->left;
            
//             *subRoot = successor; 
//         }

//         free(toBeDeleted);
//     }
// }

BST delete(BST b, int data){
    if(b == NULL){
        return b;
    }

    if(b->data > data){
        b->left = delete(b->left, data);
    }else if(b->data < data){
        b->right = delete(b->right, data);
    }else{
        if(!b->left){
            NodePtr temp = b;
            b = b->right;
            free(temp);            
        }else if(!b->right){
            NodePtr temp = b;
            b = b->left;
            free(temp);            
        }else{
            
            NodePtr trav = b->right;
            while(trav->left){
                trav = trav->left;
            }   
            b->data = trav->data;
        
            b->right = delete(b->right, b->data);
        }

    }

    return b;
}
