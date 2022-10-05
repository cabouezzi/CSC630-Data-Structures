#pragma once

typedef struct node Node;

struct node {
    int data;
    Node *next;
};

void push(Node **head, int data);
void print(Node **head);
void pop(Node **head);
void insertAt(Node **head, int index, int data);
void removeAt(Node **head, int index);
int dataAt(Node **head, int index);
int sum(Node **head);
int min(Node **head);
int max(Node **head);
void reverse(Node **head);
void destroy(Node **head);
int contains(Node **head, int data);
