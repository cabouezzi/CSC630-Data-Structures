//
//  Testing.c
//  LinkedLists
//
//  Created by Chaniel Ezzi on 5/30/22.
//

#include "Testing.h"
#include <stdlib.h>
#include <assert.h>

void test_push(void) {
    Node *head = NULL;
    for (int i = 0; i < 1000; i++) {
        int n = rand();
        int l;
        if (head != NULL)
            l = head->data;
        push(&head, n);
        assert(head->data == n);
        
        if (head->next != NULL)
            assert(head->next->data == l);
    }
}

void test_pop(void) {
    Node *head = NULL;
    for (int i = 0; i < 1000; i++)
        push(&head, rand());
    
    for (int i = 0; i < 1000; i++) {
        if (head->next == NULL)
            continue;
        int n = head->next->data;
        pop(&head);
        assert(head->data == n);
    }
    
}

void test_insertion(void) {
    Node *head = NULL;
    int ar[1000];
    for (int i = 0; i < 999; i++) {
        // 'inserting' doesn't get rid of the node already at
        // the given index. Instead, it adds a node in between
        // indices i and i-1.
        insertAt(&head, i, i);
        ar[i] = i;
        // Therefore, it should be indexed the same as an array
        // if i increments by 1.
        assert(dataAt(&head, i) == ar[i]);
    }
}
void test_removal(void) {
    Node *head = NULL;
    
    for (int i = 0; i < 1000; i++)
        push(&head, 999-i);
    
    for (int i = 999; i > 0; i--) {
        removeAt(&head, i);
        assert(!contains(&head, i));
    }
}

void test_get_data(void) {
    Node *head = NULL;
    int ar[1000];
    
    for (int i = 0; i < 1000; i++) {
        int n = rand();
        push(&head, n);
        ar[999-i] = n;
    }
    
    for (int i = 0; i < 1000; i++)
        assert(dataAt(&head, i) == ar[i]);
    
}

void test_sum(void) {
    Node *head = NULL;
    int s = 0;
    for (int i = 0; i < 1000; i++) {
        int n = rand();
        push(&head, n);
        s += n;
    }
    assert(sum(&head) == s);
}

void test_min(void) {
    Node *head = NULL;
    int m;
    for (int i = 0; i < 1000; i++) {
        int n = rand();
        push(&head, n);
        if (i == 0)
            m = n;
        else if (n < m)
            m = n;
    }
    assert(min(&head) == m);
}

void test_max(void) {
    Node *head = NULL;
    int m;
    for (int i = 0; i < 1000; i++) {
        int n = rand();
        push(&head, n);
        if (i == 0)
            m = n;
        else if (n > m)
            m = n;
    }
    assert(max(&head) == m);
}

void test_reverse(void) {
    Node *one = NULL;
    Node *two = NULL;
    
    for (int i = 0; i < 1000; i++) {
        push(&one, i);
        push(&two, i);
    }
    
    reverse(&two);
    
    for (int i = 0; i < 1000; i++)
        assert(dataAt(&one, i) == dataAt(&two, 999-i));
    
}

void test_destroy(void) {
    Node *head = NULL;
    for (int i = 0; i < 1000; i++)
        push(&head, i);
    destroy(&head);
    assert(head == NULL);
}
