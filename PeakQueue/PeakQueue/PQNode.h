//
//  PQNode.h
//  PeakQueue
//
//  Created by Chaniel Ezzi on 4/28/22.
//

#pragma once
#include <stdio.h>

typedef struct pqnode PQNode;

struct pqnode {
    int priority;
    int data;
};

void swap(PQNode *x, PQNode *y);
