#ifndef OPEN_HASH_FUNCTIONS_H
#define OPEN_HASH_FUNCTIONS_H

void initDict(Dictionary d){
    for(int i = 0; i < maxHash; i++){
        d[i] = NULL;
    }
}

int hash(int id){
    return id%64;
}

void insert(student s, Dictionary d){
    //insert first
    int index = hash(s.id);

    NodePtr newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        printf("BreadCrumbs!");
        exit(1);
    } 
    newNode->data = s;
    newNode->next = d[index];

    d[index] = newNode;
    
    //insert last (unya)
}
void delete(int id, Dictionary d){
    int index = hash(id);

    NodePtr *trav = &d[index];
    for(;*trav != NULL && (*trav)->data.id != id ;trav = &(*trav)->next);
    if(*trav == NULL){
        printf("\nData not found.\n");
    }else{
        NodePtr temp = *trav;
        *trav = temp->next;
        free(temp);
    }        

}
student findStud(int id, Dictionary d){
    student retval; 

    int index = hash(id);

    NodePtr *trav = &d[index];
    for(;*trav != NULL && (*trav)->data.id != id ;trav = &(*trav)->next);
    if(*trav == NULL){
        printf("\nData not found.\n");
    }else{
        retval = (*trav)->data;
    }

    return retval;
}
void display(Dictionary d){
    for(int i = 0; i < maxHash; i++){
        NodePtr trav = d[i];
        if(trav != NULL){
            printf("[%d]", i);
            for(; trav != NULL; trav = trav->next){
                printf("-> <%d> %s, %s", trav->data.id, trav->data.fullName.lname, trav->data.fullName.fname);
            }
            printf("\n");
        } 
    }
}


#endif