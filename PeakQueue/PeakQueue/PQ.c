//
//  PQ.c
//  PeakQueue
//
//  Created by Chaniel Ezzi on 4/28/22.
//

#include "PQ.h"
#include <assert.h>
#include <stdlib.h>

void print(PQ *queue) {
    
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->queue[i].data);
    }
    
}

void add(int priority, int data, PQ *queue) {
    assert(queue->size < queue->capacity);
    
    queue->queue[queue->size++] = (PQNode) {priority, data};
    
    
    
}
