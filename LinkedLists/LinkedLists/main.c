#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"
#include "Testing.h"

int main(int argc, char ** argv) {
    
    test_push();
    printf("'push' test successful.\n");
    test_pop();
    printf("'pop' test successful.\n");
    test_get_data();
    printf("'dataAt' test successful.\n");
    test_removal();
    printf("'removeAt' test successful.\n");
    test_insertion();
    printf("'insertAt' test successful.\n");
    test_sum();
    printf("'sum' test successful.\n");
    test_min();
    printf("'min' test successful.\n");
    test_max();
    printf("'max' test successful.\n");
    test_reverse();
    printf("'reverse' test successful.\n");
    test_destroy();
    printf("'destroy' psuedo test successful.\n");
    
}
