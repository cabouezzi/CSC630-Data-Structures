//
//  main.c
//  BinaryTrees
//
//  Created by Chaniel Ezzi on 4/12/22.
//

#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
#include "Testing.h"

int main(int argc, const char * argv[]) {
    
    printf("Beginning tests:\n");
    test_add();
    printf("'add' function successful. \n");
    test_contains();
    printf("'contains' function successful. \n");
    test_get_value();
    printf("'get_value' function successful. \n");
    test_change_value();
    printf("'change_value' function successful. \n");
    test_get_size();
    printf("'get_size' function successful. \n");
    test_delete();
    printf("'delete' function successful. \n");
    test_destroy();
    printf("'destroy' function successful. \n");
    
    return 0;
}
