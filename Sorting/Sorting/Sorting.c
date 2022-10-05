//
//  Sorting.c
//  Sorting
//
//  Created by Chaniel Ezzi on 5/5/22.
//

#include "Sorting.h"

void swap(int *x, int *y) {
    int holder = *x;
    *x = *y;
    *y = holder;
}

void print(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i != size-1) printf(" – ");
    }
}

void insertion_sort(int array[], int size) {
    for (int i = 1; i < size; i++)
        for (int j = i-1; j >= 0; j--)
            if (array[j] > array[j+1])
                swap(array + j, array + j + 1);
    
}

static void heapify(int *arr, int size, int i) {
    
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < size && arr[left] > arr[largest])
        largest = left;
  
    if (right < size && arr[right] > arr[largest])
        largest = right;
    
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, size, largest);
    }
}

void heap_sort(int *arr, int size) {
    for (int i = (size / 2) - 1; i >= 0; i--)
        heapify(arr, size, i);
    
    for (int i = size - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void merge(int *left, int leftSize, int *right, int rightSize, int *container) {
    
    int index = 0;
    int l = 0;
    int r = 0;
    
    while (l < leftSize && r < rightSize) {
        if (left[l] <= right[r])
            container[index++] = left[l++];
        else
            container[index++] = right[r++];
    }
    
    while (l < leftSize)
        container[index++] = left[l++];
    
    while (r < rightSize)
        container[index++] = right[r++];
    
}

void merge_sort(int *array, int size) {
    
    if (size <= 1)
        return;
    
    int leftSize, rightSize;
    if ((size % 2) != 0) {
        rightSize = size / 2;
        leftSize = rightSize + 1;
    }
    else {
        rightSize = size / 2;
        leftSize = rightSize;
    }
    
    int left[leftSize];
    int right[rightSize];
    
    for (int i = 0; i < leftSize; i++)
        left[i] = array[i];
    for (int i = 0; i < rightSize; i++)
        right[i] = array[leftSize + i];
    
    merge_sort(left, leftSize);
    merge_sort(right, rightSize);
    
    merge(left, leftSize, right, rightSize, array);
    
}

int partition (int array[], int start, int end) {
    int p = array[end];
    int i = start - 1;
    
    for (int j = start; j < end; j++) {
        if (array[j] <= p) {
            i++;
            swap(&(array[i]), &(array[j]));
        }
    }
    
    swap(&array[i + 1], &array[end]);
    return i + 1;
}

void quick_sort(int *array, int start, int end) {
    if (start < end) {
        int p = partition(array, start, end);
        quick_sort(array, start, p - 1);
        quick_sort(array, p + 1, end);
    }
}
