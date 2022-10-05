//
//  Testing.h
//  Heap
//
//  Created by Chaniel Ezzi on 5/18/22.
//

#pragma once
#include <stdio.h>
#include <assert.h>
#include "Heap.h"

void test_structure(Heap *heap);
void test_popping(Heap *heap);
void test_peek(Heap *heap);
void test_heapify(HeapNode *array, int arraySize);
