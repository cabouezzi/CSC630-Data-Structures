//
//  PQNode.c
//  PeakQueue
//
//  Created by Chaniel Ezzi on 4/28/22.
//

#include "PQNode.h"

void swap(PQNode *x, PQNode *y) {
   PQNode holder = *x;
   *x = *y;
   *y = holder;
   
}
