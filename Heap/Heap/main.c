//
//  main.c
//  Heap
//
//  Created by Chaniel Ezzi on 4/26/22.
//

#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"
#include "Testing.h"

int main(int argc, const char * argv[]) {
    
    int testSize = 1000;
    
    // The heap to be used for testing
    Heap heap = NewHeap(testSize);
    // An array for the heapify test
    HeapNode array[testSize];
    
    for (int i = 0; i < testSize; i++) {
        // Create a node with a random key and value.
        // The randomness of the key is important to test heapify
        HeapNode newNode = NewHeapNode(rand() % testSize, rand() % 10);
        // Add the node to the heap
        add(newNode, &heap);
        // Add the node to the array
        array[i] = newNode;
    }
    
    test_structure(&heap);
    test_peek(&heap);
    test_popping(&heap);
    test_heapify(array, testSize);
    
    return 0;
}
