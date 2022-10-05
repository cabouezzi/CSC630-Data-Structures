//
//  Heap.h
//  Heap
//
//  Created by Chaniel Ezzi on 4/26/22.
//

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "HeapNode.h"

typedef struct heap Heap;

struct heap {
    int size;
    int capacity;
    HeapNode *queue;
};

Heap NewHeap(int capacity);

void swap(HeapNode *x, HeapNode *y);
void print(Heap *heap);

void add(HeapNode node, Heap *heap);
HeapNode peek(Heap *heap);
HeapNode pop(Heap *heap);
void heapify(HeapNode *array, int size);

void grow(Heap *heap);

void bubble_up(int index, Heap *heap);
void bubble_down(int index, Heap *heap);
