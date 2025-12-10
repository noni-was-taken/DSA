#include<stdio.h>
#include<stdbool.h>
#define HASH_BUCKETS 120 //for the shits ang giggles lang karon
#define RESULT_COUNT 3

typedef struct CacheEntry {
    char *key;                   // The search query string (dynamically allocated)
    char **results;              // Array of result strings (dynamically allocated), size RESULT_COUNT
    struct CacheEntry *next;     // Pointer for separate chaining (Open Hashing)
} CacheEntry;
// Structure for the entire Hash Table
typedef struct {
    CacheEntry *buckets[HASH_BUCKETS];
} HashTable;


void init_cache(HashTable *table){
    for(int i = 0; i < HASH_BUCKETS; i++){
        table->buckets[i] = NULL;        
    }
}
// Initializes the hash table, setting all buckets to NULL
 

char **lookup_cache(HashTable *table, const char *key){
    int idx = hash(key);
    
    CacheEntry **trav;
    for(trav = &table->buckets[idx]; *trav != NULL && strcmp((*trav)->key, key) != 0 ; trav = &(*trav)->next){}

    return (*trav != NULL) ? (*trav)->results : NULL;

}

// Looks up a key in the cache
// Returns a pointer to the internal result array (size 3) if found (CACHE HIT), otherwise NULL
 

bool insert_cache(HashTable *table, const char *key){
    bool retval = true;
    int index = hash(key);

    
    CacheEntry **trav = &table->buckets[index];
    for(;*trav != NULL && strcmp((*trav)->key, key) != 0; trav = &(*trav)->next){}

    if(*trav == NULL){
        CacheEntry *newCache = malloc(sizeof(CacheEntry));
        newCache->results = malloc(sizeof(char*) * RESULT_COUNT);
        char **results = simulate_database_fetch(key);
        if(results != NULL){
            for(int i = 0; i < RESULT_COUNT; i++){
                newCache->results[i] = malloc(strlen(results[i]) + 1);
                strcpy(newCache->results[i], results[i]);
            }
            newCache->key = malloc(strlen(key) + 1);
            strcpy(newCache->key,key);
            newCache->next = NULL;
            (*trav) = newCache;
        }else{
            retval = false;
        }
    }

    return retval;
}


// Attempts to insert a new key/value pair into the cache
// If the key already exists, the insertion is skipped
// If the key is new, it calls simulate_database_fetch() to get the results
// Returns true on successful insertion or if key already exists (skipped), false on failure
 

// char **simulate_database_fetch(const char *key)

// Simulates an expensive database query to get results
// Returns a dynamically allocated array of result strings, or NULL
// This function is GIVEN - all you need to do is CALL it