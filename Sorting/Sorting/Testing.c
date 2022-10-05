//
//  Testing.c
//  Sorting
//
//  Created by Chaniel Ezzi on 6/1/22.
//

#include "Testing.h"
#include "Sorting.h"
#include <assert.h>
#include <time.h>

void test_sortings (void) {
    // 2^20
    int size = 1000;
    int insertion[size];
    int heap[size];
    int merge[size];
    int quick[size];
    
    for (int i = 0; i < size; i++) {
        int n = rand() % size;
        insertion[i] = n;
        heap[i] = n;
        merge[i] = n;
        quick[i] = n;
    }
    
    insertion_sort(insertion, size);
    heap_sort(heap, size);
    merge_sort(merge, size);
    quick_sort(quick, 0, size-1);
    
    for (int i = 0; i < size; i++) {
        assert(insertion[i] == merge[i]);
        assert(merge[i] == quick[i]);
        assert(heap[i] == merge[i]);
    }
    
}

void test_mass_insertion (void) {
    // 2^20
    int size = 10000;
    int array[size];
    
    for (int i = 0; i < size; i++)
        array[i] = rand() % size;
    
    clock_t start = clock();
    insertion_sort(array, size);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    
    for (int i = 0; i < size - 1; i++)
        assert(array[i] <= array[i+1]);
    
    printf("Insertion sorting took %f seconds (array size of 10,000)\n", seconds);
    
}

void test_mass_heap (void) {
    // 2^20
    int size = 1048576;
    int array[size];
    
    for (int i = 0; i < size; i++)
        array[i] = rand() % size;
    
    clock_t start = clock();
    heap_sort(array, size);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    
    for (int i = 0; i < size - 1; i++)
        assert(array[i] <= array[i+1]);
    
    printf("Heap sorting took %f seconds\n", seconds);
    
}

void test_mass_merge (void) {
    // 2^20
    int size = 10000;
    int array[size];
    
    for (int i = 0; i < size; i++)
        array[i] = rand() % size;
    
    clock_t start = clock();
    merge_sort(array, size);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    
    for (int i = 0; i < size - 1; i++)
        assert(array[i] <= array[i+1]);
    
    printf("Merge sorting took %f seconds (array size of 10,000)\n", seconds);
    
}

void test_mass_quick (void) {
    // 2^20
    int size = 1048576;
    int array[size];
    
    for (int i = 0; i < size; i++)
        array[i] = rand() % size;
    
    clock_t start = clock();
    quick_sort(array, 0, size-1);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    
    for (int i = 0; i < size - 1; i++)
        assert(array[i] <= array[i+1]);
    
    printf("Quick sorting took %f seconds\n", seconds);
    
}

