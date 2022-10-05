//
//  Testing.c
//  HashTables
//
//  Created by Chaniel Ezzi on 5/30/22.
//

#include "Testing.h"
#include <stdlib.h>
#include <assert.h>

#define STR_LEN 8

void test_add(void) {
    
    HashTable table = NewHashTable();
    
    for (int times = 0; times < LENGTH; times++) {
        char key[STR_LEN];
        for (int i = 0; i < STR_LEN; i++)
            key[i] = rand();
        if (add(key, times, &table))
            assert(contains(key, &table));
        else; // Collision
    }
    
    print(&table);
    
}

void test_get(void) {
    HashTable table = NewHashTable();
    
    for (int i = 0; i < LENGTH; i++) {
        char key[] = {i};
        int n = rand();
        if (add(key, n, &table))
            assert(get(key, &table) == n);
    }
}

void test_delete(void) {
    HashTable table = NewHashTable();
    
    for (int i = 0; i < LENGTH; i++) {
        char key[] = {i};
        if (add(key, i, &table))
            assert(contains(key, &table));
    }
    
    for (int i = 0; i < LENGTH; i++) {
        char key[] = {i};
        delete(key, &table);
        assert(!contains(key, &table));
    }
}

void test_change(void) {
    HashTable table = NewHashTable();
    
    for (int i = 0; i < LENGTH; i++) {
        char key[] = {i};
        add(key, i, &table);
        int old = get(key, &table);
        change(key, ~old, &table);
        assert(get(key, &table) != old);
    }
}

void test_destroy(void) {
    HashTable table = NewHashTable();
    
    for (int i = 0; i < LENGTH; i++) {
        char key[] = {i};
        add(key, i, &table);
    }
    
    destroy(&table);
    
    for (int i = 0; i < LENGTH; i++)
        assert(table.buckets[i] == NULL);
}

