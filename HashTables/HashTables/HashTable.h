//
//  HashTable.h
//  HashTables
//
//  Created by Chaniel Ezzi on 5/30/22.
//

#pragma once
#include <stdio.h>
#include <string.h>

#define LENGTH 100

typedef struct {
    char *key;
    int value;
} Node;

typedef struct {
    Node* buckets[LENGTH];
} HashTable;

HashTable NewHashTable(void);

int hash (char *key);

void print (HashTable *table);
int add (char *key, int value, HashTable *table);
int get (char *key, HashTable *table);
int contains (char *key, HashTable *table);
void delete (char *key, HashTable *table);
void change (char *key, int value, HashTable *table);
void destroy (HashTable *table);
