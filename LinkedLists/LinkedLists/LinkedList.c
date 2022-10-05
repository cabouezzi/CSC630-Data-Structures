#include <stdio.h>
#include <stdlib.h> 
#include "LinkedList.h"

void push(Node **head, int data) {
    Node *toAdd = malloc(sizeof(Node));
    toAdd->data = data;
    toAdd->next = *head;
    *head = toAdd;
}

void print (Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    printf("%d ", (*head)->data);
    if ((*head)->next != NULL) print(&((*head)->next));
    else printf("\n");
    
}

void pop(Node **head) {
    
    Node *garb = *head;
    *head = (*head)->next;
    free(garb);
    
}

void insertAt(Node **head, int index, int data) {
    
    if (index == 0) {
        push(head, data);
        return;
    }
    
    Node *last = NULL;
    Node *cur = *head;
    
    for (int i = 0; i < index; i++) {
        last = cur;
        cur = cur->next;
    }
    
    Node *new = malloc(sizeof(Node));
    new->data = data;
    new->next = cur;
    
    if (last != NULL) {
        last->next = new;
    }
}

void removeAt(Node **head, int index) {
    
    if (index == 0) {
        pop(head);
        return;
    }
    
    Node *last = NULL;
    Node *cur = *head;
    
    for (int i = 0; i < index; i++) {
        last = cur;
        cur = cur->next;
    }
    
    if (!cur) return;
    
    last->next = cur->next;
    free(cur);
    
}

int dataAt(Node **head, int index) {
    
    Node *cur = *head;
    
    for (int i = 0; i < index; i++) {
        cur = cur->next;
    }
    
    return cur->data;
    
}


int sum(Node **head) {
    
    Node *cur = *head;
    
    int s = 0;
    
    while (cur != NULL) {
        s += cur->data;
        cur = cur->next;
    }
    
    return s;
}

int min(Node **head) {
    
    Node *cur = *head;
    
    int m = cur->data;
    
    while (cur != NULL) {
        
        if (cur->data < m) {
            m = cur->data;
        }
        
        cur = cur->next;
    }
    
    return m;
}

int max(Node **head) {
    
    Node *cur = *head;
    int m = cur->data;
    
    while (cur != NULL) {
        
        if (cur->data > m) {
            m = cur->data;
        }
        
        cur = cur->next;
    }
    
    return m;
}

void reverseRec(Node *node, Node **head) {
    
    if (node->next != NULL) {
        reverseRec(node->next, head);
        node->next->next = node;
        node->next = NULL;
    }
    else {
        *head = node;
    }
    
}

void reverse(Node **head) {
    
    reverseRec(*head, head);
    return;
    
    Node *last = NULL;
    Node *cur = *head;
    Node *next = cur->next;
    
    while (cur != NULL) {
        
        next = cur->next;
        cur->next = last;
        
        last = cur;
        cur = next;
        
    }
    
    *head = last;
    
}

void destroy(Node **head) {
    
    Node *cur = *head;
    
    while (cur != NULL) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
    
    *head = NULL;
    
}

int contains(Node **head, int data) {
    Node *cur = *head;
    while (cur != NULL) {
        if (cur->data == data)
            return 1;
        cur = cur->next;
    }
    
    return 0;
}
