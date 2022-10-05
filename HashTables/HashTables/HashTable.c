//
//  HashTable.c
//  HashTables
//
//  Created by Chaniel Ezzi on 5/30/22.
//

#include "HashTable.h"
#include <stdlib.h>

HashTable NewHashTable(void) {
    HashTable table = (HashTable) {{0}};
    for (int i = 0; i < LENGTH; i++)
        table.buckets[i] = NULL;
    
    return table;
}

int hash (char *key) {
    int i = 0;
    int value = 0xABC; // obviously not the best seed
    while (key[i] != 0) {
        value *= key[i++] ;
    }
    
    value %= LENGTH;
    
    return value;
}

void print (HashTable *table) {
    for (int i = 0; i < LENGTH; i++) {
        if (table->buckets[i] == NULL)
            printf("%d\t–\t–\n", i);
        else
            printf("%d\t%s\t%d\n", i, table->buckets[i]->key, table->buckets[i]->value);
    }
    printf("\n");
}

int add (char *key, int value, HashTable *table) {
    int i = hash(key);
    
    if (table->buckets[i] == NULL) {
        table->buckets[i] = malloc(sizeof(Node));
        table->buckets[i]->key = key;
        table->buckets[i]->value = value;
        return 1;
    }
    else
        return 0;
}

int get (char *key, HashTable *table) {
    int i = hash(key);
    // Crash if NULL, implementer's fault >_>
    return table->buckets[i]->value;
}

int contains (char *key, HashTable *table) {
    int i = hash(key);
    if (table->buckets[i] != NULL)
        return 1;
    else
        return 0;
}

void delete (char *key, HashTable *table) {
    int i = hash(key);
    free(table->buckets[i]);
    table->buckets[i] = NULL;
}

void change (char *key, int value, HashTable *table) {
    int i = hash(key);
    if (table->buckets[i] != NULL)
        table->buckets[i]->value = value;
}

void destroy (HashTable *table) {
    for (int i = 0; i < LENGTH; i++) {
        if (table->buckets[i] != NULL) {
            free(table->buckets[i]);
            table->buckets[i] = NULL;
        }
    }
}
