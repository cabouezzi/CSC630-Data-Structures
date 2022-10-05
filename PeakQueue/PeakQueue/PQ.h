//
//  PQ.h
//  PeakQueue
//
//  Created by Chaniel Ezzi on 4/28/22.
//

#pragma once
#include <stdio.h>
#include "PQNode.h"

typedef struct pq PQ;

struct pq {
    int size;
    int capacity;
    PQNode *queue;
};

void print(PQ *queue);
void add(int priority, int data, PQ *queue);
int peek(PQ *queue);
int delete(PQ *queue);
