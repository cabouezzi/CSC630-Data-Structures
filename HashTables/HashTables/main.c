//
//  main.c
//  HashTables
//
//  Created by Chaniel Ezzi on 5/30/22.
//

#include <stdio.h>
#include "HashTable.h"
#include "Testing.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    test_add();
    printf("'add' test passed. (With many collisions)\n");
    test_get();
    printf("'get' test passed.\n");
    test_change();
    printf("'change' test passed.\n");
    test_delete();
    printf("'delete' test passed.\n");
    test_destroy();
    printf("'destroy' test passed.\n");
    
    return 0;
}
