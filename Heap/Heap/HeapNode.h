//
//  HeapNode.h
//  Heap
//
//  Created by Chaniel Ezzi on 4/28/22.
//

#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct heapnode HeapNode;

struct heapnode {
    int key;
    int data;
};

HeapNode NewHeapNode(int key, int data);
