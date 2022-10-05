//
//  Node.c
//  BinaryTrees
//
//  Created by Chaniel Ezzi on 4/12/22.
//

#include "Node.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void print (Node **root) {
    if (*root == NULL) return;
    print(&((*root)->left));
    printf("%d:%d – ", (*root)->key, (*root)->value);
    print(&((*root)->right));
}

void add (Node **root, int key, int value) {
    
    if (*root == NULL) {
        *root = malloc(sizeof(Node));
        **root = (Node) { key, value, NULL, NULL };
    }
    else if (key <= (*root)->key)
        add(&((*root)->left), key, value);
    else
        add(&((*root)->right), key, value);
    
}

void delete (Node **root, int key);

static Node *largest(Node **root) {
    if ((*root)->right)
        return largest(&((*root)->right));
    else
        return *root;
}

static void two_kids (Node **root, int key) {
    Node *l = largest(&((*root)->left));
    delete(root, l->key);
    (*root)->key = l->key;
    (*root)->value = l->value;
}

void delete (Node **root, int key) {
    
    if (key != (*root)->key) {
        
        if (key <= (*root)->key)
            delete(&((*root)->left), key);
        else
            delete(&((*root)->right), key);
        
        return;
    }
    
    if ((*root)->left == NULL && (*root)->right == NULL) {
        free(*root);
        *root = NULL;
    }
    else if ((*root)->left == NULL) {
        free(*root);
        *root = (*root)->right;
    }
    else if ((*root)->right == NULL) {
        free(*root);
        *root = (*root)->left;
    }
    else {
        two_kids(root, key);
    }
    
}

int contains(Node **root, int key) {
    if (*root == NULL) return 0;
    int cur = (*root)->key;
    
    if (key < cur)
        return contains(&((*root)->left), key);
    else if (key > cur)
        return contains(&((*root)->right), key);
    else
        return 1;
}

int get_value(Node **root, int key) {
    if (*root == NULL) abort();
    int cur = (*root)->key;
    
    if (key < cur)
        return get_value(&((*root)->left), key);
    else if (key > cur)
        return get_value(&((*root)->right), key);
    else
        return (*root)->value;
}

int change_value(Node **root, int key, int value) {
    if (*root == NULL) abort();
    int cur = (*root)->key;
    
    if (key < cur)
        return change_value(&((*root)->left), key, value);
    else if (key > cur)
        return change_value(&((*root)->right), key, value);
    else {
        int h = (*root)->value;
        (*root)->value = value;
        return h;
    }
}

int get_size (Node **root) {
    if (*root == NULL)
        return 0;
    else if ((*root)->right == NULL && (*root)->left == NULL)
        return 1;
    else if ((*root)->left == NULL)
        return 1 + get_size(&((*root)->right));
    else if ((*root)->right == NULL)
        return 1 + get_size(&((*root)->left));
    else
        return 1 + get_size(&((*root)->left)) + get_size(&((*root)->right));
    
}

void destroy(Node **root) {
    if ((*root)->left != NULL) destroy(&((*root)->left));
    if ((*root)->right != NULL) destroy(&((*root)->right));
    free(*root);
    *root = NULL;
}
