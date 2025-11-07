#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define EMPTY '~'
#define DELETED '!'
#define MAX 211

/*********************************/
/*    USER-DEFINED DATA TYPES    */
/*********************************/
typedef struct {
    char elem;
    int frequency;
} Element;

typedef Element Dictionary[MAX];

/*********************************/
/*       HELPER FUNCTIONS        */
/*********************************/
void initDict(Dictionary D);
int hash(char elem);

/*********************************/
/*          YOUR TASKS           */
/*********************************/

void insert(Dictionary D, char elem);
void delete(Dictionary D, char elem);
bool isMember(Dictionary D, char elem);
bool isAnagram(char* s, char* t);

int main(void) {
    char s1[100], s2[100];

    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    if (isAnagram(s1, s2)) {
        printf("\"%s\" and \"%s\" are anagrams.\n", s1, s2);
    } else {
        printf("\"%s\" and \"%s\" are NOT anagrams.\n", s1, s2);
    }

    return 0;
}

/*********************************/
/*       HELPER FUNCTIONS        */
/*********************************/
void initDict(Dictionary D) {
    for (int i = 0; i < MAX; i++) {
        D[i].elem = EMPTY;
        D[i].frequency = 0;
    }
}

int hash(char elem) {
    return ((int)elem) % MAX;
}

/*********************************/
/*          YOUR TASKS           */
/*********************************/


void insert(Dictionary D, char elem) {
    // TODO: Implement insert with linear probing
  int idx = hash(elem);

  for(;D[idx].elem != EMPTY && D[idx].elem != elem; idx = (idx+1) % MAX){}
  
  if(D[idx].elem != elem) D[idx].elem = elem;

  D[idx].frequency +=1;
  
}

void delete(Dictionary D, char elem) {
    // TODO: Implement delete with linear probing
  int idx = hash(elem);

  for(;D[idx].elem != elem && D[idx].elem != EMPTY; idx = (idx+1)%MAX){}

  if(D[idx].elem != EMPTY){
    if(D[idx].frequency < 2) D[idx].elem = DELETED;
    D[idx].frequency -= 1;
  }

}

bool isMember(Dictionary D, char elem) {
    // TODO: Implement membership check
  int idx = hash(elem);
  
  for(;D[idx].elem != elem && D[idx].elem != EMPTY; idx = (idx+1)%MAX){}

  return (D[idx].elem != EMPTY);
}

bool isAnagram(char* s, char* t) {
    // TODO: Implement anagram checker
    bool retVal = true;
  
    int lens = strlen(s);
    int lent = strlen(t);

    if(lens == lent){
      Dictionary d;
      initDict(d);
        
      for(int i = 0; i < lens; i++){
        insert(d, s[i]);
      }

      for(int i = 0; i < lent; i++){
        if(isMember(d, t[i])){
          delete(d, t[i]);
        }
        else retVal = false;
      }
      
    }else{
      retVal = false;
    }
  
    return retVal;
}