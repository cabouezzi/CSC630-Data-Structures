//
//  HeapNode.c
//  Heap
//
//  Created by Chaniel Ezzi on 4/28/22.
//

#include "HeapNode.h"

HeapNode NewHeapNode(int key, int data) {
    
    HeapNode node;
    node.key = key;
    node.data = data;
    
    return node;
    
}
