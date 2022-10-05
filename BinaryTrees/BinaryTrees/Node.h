//
//  Node.h
//  BinaryTrees
//
//  Created by Chaniel Ezzi on 4/12/22.
//

#pragma once

typedef struct node Node;

struct node {
    int key;
    int value;
    Node *left;
    Node *right;
};

void print (Node **root);

void add(Node **root, int key, int value);
void delete(Node **root, int key);
int contains(Node **root, int key);
int get_value(Node **root, int key);
int change_value(Node **root, int key, int value);
int get_size(Node **root);
void destroy(Node **root);
