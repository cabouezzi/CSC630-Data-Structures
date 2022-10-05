//
//  Sorting.h
//  Sorting
//
//  Created by Chaniel Ezzi on 5/5/22.
//

#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y);
void print(int array[], int size);

void insertion_sort(int array[], int size);
void heap_sort(int *array, int size);

void merge_sort(int *array, int size);
void quick_sort(int *array, int start, int end);
