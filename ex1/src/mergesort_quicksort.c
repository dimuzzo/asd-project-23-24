// Libraries declaration
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

// 3-Way Partition function for Quick Sort
void three_way_partition(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *), size_t *lt, size_t *gt) {
    void *pivot = malloc(size);
    if (!pivot) return;

    memcpy(pivot, base, size); // Select the first element as the pivot
    size_t i = 0, low = 0, high = nitems - 1;

    while (i <= high) {
        int cmp = compar((char *)base + i * size, pivot);
        if (cmp < 0) {
            // Swap base[i] and base[low]
            void *temp = malloc(size);
            memcpy(temp, (char *)base + low * size, size);
            memcpy((char *)base + low * size, (char *)base + i * size, size);
            memcpy((char *)base + i * size, temp, size);
            free(temp);

            low++;
            i++;
        } else if (cmp > 0) {
            // Swap base[i] and base[high]
            void *temp = malloc(size);
            memcpy(temp, (char *)base + high * size, size);
            memcpy((char *)base + high * size, (char *)base + i * size, size);
            memcpy((char *)base + i * size, temp, size);
            free(temp);

            high--;
        } else {
            i++;
        }
    }

    *lt = low;
    *gt = high;
    free(pivot);
}

// Quick Sort implementation with 3-Way Partitioning
void quick_sort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *)) {
    if (nitems <= 1 || base == NULL) return;  // No sorting needed

    size_t lt, gt;
    three_way_partition(base, nitems, size, compar, &lt, &gt);

    quick_sort(base, lt, size, compar); // Sort elements less than pivot
    quick_sort((char *)base + (gt + 1) * size, nitems - gt - 1, size, compar); // Sort elements greater than pivot
}