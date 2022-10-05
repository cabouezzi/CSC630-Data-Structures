//
//  main.c
//  Sorting
//
//  Created by Chaniel Ezzi on 5/5/22.
//

#include <stdio.h>
#include <stdlib.h>
#include "Sorting.h"
#include "Testing.h"

int main(int argc, const char * argv[]) {
    
    test_sortings();
    test_mass_insertion();
    test_mass_merge();
    test_mass_heap();
    test_mass_quick();
    
}
