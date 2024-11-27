#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mergesort_quicksort.h"

// Merge function for Merge Sort
void merge(void *base, size_t mid, size_t nitems, size_t size, int (*compar)(const void *, const void *)) {
    void *temp = malloc(nitems * size);
    if (!temp) return;

    size_t i = 0, j = mid, k = 0;
    while (i < mid && j < nitems) {
        if (compar((char *)base + i * size, (char *)base + j * size) <= 0) {
            memcpy((char *)temp + k * size, (char *)base + i * size, size);
            i++;
        } else {
            memcpy((char *)temp + k * size, (char *)base + j * size, size);
            j++;
        }
        k++;
    }

    while (i < mid) {
        memcpy((char *)temp + k * size, (char *)base + i * size, size);
        i++;
        k++;
    }

    while (j < nitems) {
        memcpy((char *)temp + k * size, (char *)base + j * size, size);
        j++;
        k++;
    }

    memcpy(base, temp, nitems * size);
    free(temp);
}

// Merge Sort implementation
void merge_sort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *)) {
    if (nitems < 2) return;

    size_t mid = nitems / 2;
    merge_sort(base, mid, size, compar);
    merge_sort((char *)base + mid * size, nitems - mid, size, compar);
    merge(base, mid, nitems, size, compar);
}

// Partition function for Quick Sort
size_t partition(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *)) {
    void *pivot = (char *)base + (nitems - 1) * size;
    size_t i = 0;

    for (size_t j = 0; j < nitems - 1; j++) {
        if (compar((char *)base + j * size, pivot) <= 0) {

            void *temp = malloc(size);
            memcpy(temp, (char *)base + i * size, size);
            memcpy((char *)base + i * size, (char *)base + j * size, size);
            memcpy((char *)base + j * size, temp, size);
            free(temp);
            i++;
        }
    }

    void *temp = malloc(size);
    memcpy(temp, (char *)base + i * size, size);
    memcpy((char *)base + i * size, pivot, size);
    memcpy(pivot, temp, size);
    free(temp);

    return i;
}

// Quick Sort implementation
void quick_sort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *)) {
    if (nitems < 2) return;

    size_t pivot_index = partition(base, nitems, size, compar);
    quick_sort(base, pivot_index, size, compar);
    quick_sort((char *)base + (pivot_index + 1) * size, nitems - pivot_index - 1, size, compar);
}