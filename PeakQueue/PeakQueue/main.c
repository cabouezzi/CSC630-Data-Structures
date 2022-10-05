//
//  main.c
//  PeakQueue
//
//  Created by Chaniel Ezzi on 4/28/22.
//

#include <stdio.h>
#include "stdlib.h"
#include "PQ.h"

int main(int argc, const char * argv[]) {
    
    PQ pq;
    pq.size = 0;
    pq.capacity = 8;
    pq.queue = malloc(sizeof(PQNode) * pq.capacity);
    
    add(3, 3, &pq);
    add(1, 1, &pq);
    add(2, 2, &pq);
    
    print(&pq);
    
    return 0;
}
