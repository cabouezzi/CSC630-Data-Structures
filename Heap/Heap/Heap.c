//
//  Heap.c
//  Heap
//
//  Created by Chaniel Ezzi on 4/26/22.
//

#include "Heap.h"
#include "Testing.h"

Heap NewHeap(int capacity) {
    Heap heap;
    heap.size = 0;
    heap.capacity = capacity;
    heap.queue = malloc(sizeof(HeapNode) * capacity);
    return heap;
}

void print(Heap *heap) {
    for (int i = 0; i < heap->size; i++) {
        printf("%d:%d", heap->queue[i].key, heap->queue[i].data);
        if (i+1 != heap->size) printf(" | ");
    }
    printf("\n");
}

void swap(HeapNode *x, HeapNode *y) {
    HeapNode holder = *x;
    *x = *y;
    *y = holder;
}

HeapNode peek(Heap *heap) {
    return heap->queue[0];
}

void add(HeapNode node, Heap *heap) {
    if (heap->size == heap->capacity) grow(heap);
    
    heap->queue[heap->size] = node;
    bubble_up(heap->size++, heap);
}

HeapNode pop(Heap *heap) {
    swap(heap->queue, (heap->queue)+--(heap->size));
    bubble_down(0, heap);
    return heap->queue[heap->size];
}

void grow(Heap *heap) {
    heap->capacity *= 2;
    heap->queue = realloc(heap->queue, sizeof(HeapNode) * heap->capacity);
}

void bubble_up(int index, Heap *heap) {
    if (index == 0) return;
    int parent = (index - 1) / 2;
    if (heap->queue[parent].key > heap->queue[index].key) {
        swap(heap->queue + parent, heap->queue + index);
        bubble_up(parent, heap);
    }
}

void bubble_down(int index, Heap *heap) {
    int c1 = 2*index + 1;
    if (c1 >= heap->size) return;
    int c2 = c1 + 1;
    int mindex;
    if (c2 >= heap->size || heap->queue[c1].key <= heap->queue[c2].key) mindex = c1;
    else mindex = c2;
    if (heap->queue[index].key > heap->queue[mindex].key) {
        swap(heap->queue + index, heap->queue + mindex);
        bubble_down(mindex, heap);
    }
}

void heapify(HeapNode *array, int size) {
    Heap heap = NewHeap(size);
    heap.size = size;
    heap.queue = array;
    
    for (int i = 0; i < size; i++)
        bubble_up(i, &heap);
    
}
