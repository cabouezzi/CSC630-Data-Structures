//
//  Testing.c
//  Heap
//
//  Created by Chaniel Ezzi on 5/18/22.
//

#include "Testing.h"

static void test_children(Heap *heap, int i) {
    // Get the indices of the node's two children
    int c1 = i*2 + 1;
    int c2 = c1 + 1;
    if (c1 < heap->size) {
        // Make sure the first child's priority is greater
        assert(heap->queue[c1].key >= heap->queue[i].key);
        // Make sure the first child's children have greater (or equal)
        // priorities than itself.
        test_children(heap, c1);
    }
    // Repeat c1 stuff for c2;
    if (c2 < heap->size) {
        assert(heap->queue[c2].key >= heap->queue[i].key);
        test_children(heap, c2);
    }
}

void test_structure(Heap *heap) {
    // Call a recursive function that checks that both child nodes
    // of a node have greater priorities.
    test_children(heap, 0);
    printf("Structure test successful: Each child's key is greater than or equal to that of it's parent.\n");
}

void test_popping(Heap *heap) {
    if (heap->size == 0) {
        printf("Pop test successful: Each popped node had a greater or equal priority than the node that preceded it.\n");
        return;
    }
    // Keep track of the popped node.
    HeapNode p = pop(heap);
    // Make sure the new peek has a greater priority than the previously
    // popped node.
    assert(peek(heap).key >= p.key);
    // Continue until empty.
    test_popping(heap);
}

void test_peek(Heap *heap) {
    HeapNode p = peek(heap);
    int min = p.key;
    // Make sure no other keys have a lower priority.
    for (int i = 0; i < heap->size; i++)
        if (heap->queue[i].key < min)
            min = heap->queue[i].key;
    // Make sure the minimum priority key is the same as the node
    // returned from peek(Heap).
    assert(min == p.key);
    printf("Peek test successful: The first node of the heap has the lowest priority key.\n");
    
}

void test_heapify(HeapNode *array, int arraySize) {
    // Call heapify on the array.
    heapify(array, arraySize);
    // Create a Heap to pass into the test_structure(Heap) function.
    Heap heapifiedArray = NewHeap(arraySize);
    // Assign the array as the heap's array.
    heapifiedArray.size = arraySize;
    heapifiedArray.queue = array;
    // Test the structure of this new heap.
    test_structure(&heapifiedArray);
    printf("Heapify test successful: An unsorted array was successfully turned into a heap and passed the structure test.\n");
}
