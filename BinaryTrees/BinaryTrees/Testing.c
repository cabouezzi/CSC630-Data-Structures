//
//  Testing.c
//  BinaryTrees
//
//  Created by Chaniel Ezzi on 5/3/22.
//

#include "Node.h"
#include "Testing.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static void test_branching (Node **root) {
    if (*root == NULL)
        return;
    // If has no children
    if ((*root)->left == NULL && (*root)->right == NULL)
        return;
    // Assert that left branch's key is less than the parent's
    if ((*root)->left != NULL)
        assert((*root)->left->key <= (*root)->key);
        test_branching(&((*root)->left));
    // Assert that right branch's key is greater than the parent's
    if ((*root)->right != NULL)
        assert((*root)->right->key > (*root)->key);
        test_branching(&((*root)->right));
}

void test_add(void) {
    
    Node *root = NULL;
    
    // Fills up the tree
    for (int i = 0; i < 1000; i++) add(&root, i, (int) random());
    // Makes sure all nodes were added
    assert(get_size(&root) == 1000);
    // Tests that the branches are organized as intended
    test_branching(&root);
    
}

void test_delete(void) {
    
    Node *root = NULL;
    
    for (int i = 0; i < 1000; i++) add(&root, i, i);
    // Goes through the tree's even keys
    for (int i = 0; i < 1000; i+=2) {
        assert(contains(&root, i));
        int s = get_size(&root);
        delete(&root, i);
        assert(get_size(&root) == s - 1);
        // Make sure the tree doesn't contain the value anymore
        assert(!contains(&root, i));
    }
    
}

void test_contains(void) {
    
    Node *root = NULL;
    
    // Fills the tree
    for (int i = 0; i < 1000; i++) {
        // Makes sure 'contains' returns 0 for keys not added yet
        assert(!contains(&root, i));
        add(&root, i, i);
    }
    
    // Makes sure 'contains' returns 1 for all the keys just added
    for (int i = 0; i < 1000; i++) assert(contains(&root, i));
    
}

void test_get_value(void) {
    
    Node *root = NULL;
    
    // Keeps track of values in array form
    int values[1000];
    
    // Fills the tree and array
    for (int i = 0; i < 1000; i++) {
        int value = (int) random();
        values[i] = value;
        add(&root, i, value);
    }
    
    // Makes sure the tree and array return equal values for each key
    for (int i = 0; i < 1000; i++) assert(get_value(&root, i) == values[i]);
    
}

void test_change_value(void) {
    
    Node *root = NULL;
    
    for (int i = 0; i < 1000; i++) {
        add(&root, i, (int) random());
        // Hold the old value
        int previous = get_value(&root, i);
        // Inverses the bits of the value
        change_value(&root, i, ~previous);
        // Makes sure the new value is different from its old value
        assert(get_value(&root, i) != previous);
    }
    
}

// Pretty self explanatory?
void test_get_size(void) {
    
    Node *root = NULL;
    
    for (int i = 0; i < 1000; i++) {
        assert(get_size(&root) == i);
        add(&root, i, i);
        assert(get_size(&root) == i+1);
    }
    
}

// Also self explanatory
void test_destroy(void) {
    
    Node *root = NULL;
    
    for (int i = 0; i < 1000; i++) add(&root, i, i);
    
    assert(get_size(&root) != 0);
    destroy(&root);
    assert(get_size(&root) == 0);
    
}
