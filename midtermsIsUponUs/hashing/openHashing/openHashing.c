#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#include"structsdef.h"
#include"openHashFunctions.h"

int main(){
    system("cls");

    Dictionary studBook;
    initDict(studBook);
    
    printf("Welcome to the USC student book\n\n");

    char input;
    student newStud;
    int id;
    student catchStud;

    while(tolower(input) != 'e'){
        printf("\nWhat do you want to do?\n");
        printf("A.insert a student  B.delete a student  C.find a student  D.show all students E.exit\n");
        scanf(" %c", &input);
        switch(tolower(input)){
            case 'a':
                printf("\n\nInserting a student\n");
                printf("ID: ");
                scanf(" %d", &newStud.id);
                printf("First Name: ");
                scanf(" %s", &newStud.fullName.fname);
                printf("Last Name: ");
                scanf(" %s", &newStud.fullName.lname);

                insert(newStud, studBook);
                break;
            case 'b':
                printf("\n\nDeleting a student\n");
                printf("ID: ");
                scanf(" %d", &id);
                delete(id, studBook);
                break;
            case 'c':
                printf("\n\nFinding a student\n");
                printf("ID: ");
                scanf(" %d", &id);
                catchStud = findStud(id, studBook);

                if(catchStud.fullName.fname != '\0'){
                    printf("\nStudent Found!\n");
                    printf("ID: %d\n", catchStud.id);
                    printf("Full Name: %s %s", catchStud.fullName.fname, catchStud.fullName.lname);
                }
                break;
            case 'd':
                printf("\n\nDisplay student book\n");
                display(studBook);
                break;
            case 'e':
                printf("\nThanks");
                break;
            default:
                printf("invalid input.\n");
                break;
        }
    }

    return 0;
}
