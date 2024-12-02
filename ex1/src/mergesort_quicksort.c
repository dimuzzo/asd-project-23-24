// Libraries declaration
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 

// Merge function used by Merge Sort
void merge(void *base, size_t mid, size_t nitems, size_t size, int (*compar)(const void *, const void *)) {
    // Allocate temporary memory for merging the two halves
    void *temp = malloc(nitems * size);
    
    if (!temp) return; // Return if memory allocation fails

    size_t i = 0;         // Index for the left half
    size_t j = mid;       // Index for the right half
    size_t k = 0;         // Index for the merged array

    // Merge elements from the two halves based on comparison
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

    // Copy remaining elements from the left half
    while (i < mid) {
        memcpy((char *)temp + k * size, (char *)base + i * size, size);
        i++;
        k++;
    }

    // Copy remaining elements from the right half
    while (j < nitems) {
        memcpy((char *)temp + k * size, (char *)base + j * size, size);
        j++;
        k++;
    }

    // Copy the merged array back to the original array
    memcpy(base, temp, nitems * size);
    free(temp); // Free temporary memory allocated
}

// Merge Sort implementation
void merge_sort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *)) {
    if (nitems < 2) return; // Base case: arrays with 1 or 0 elements are already sorted

    size_t mid = nitems / 2; // Calculate the midpoint of the array

    // Recursive case: sort the left and right halves
    merge_sort(base, mid, size, compar);                               // Left half
    merge_sort((char *)base + mid * size, nitems - mid, size, compar); // Right half

    // Merge the two sorted halves
    merge(base, mid, nitems, size, compar);
}

// 3-Way Partition function used by Quick Sort
void three_way_partition(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *), size_t *lt, size_t *gt) {
    // Allocate memory for the pivot element
    void *pivot = malloc(size);
    
    if (!pivot) return; // Return if memory allocation fails

    // Select the first element as the pivot
    memcpy(pivot, base, size);

    size_t i = 0;             // Current index
    size_t low = 0;           // Boundary for elements less than pivot
    size_t high = nitems - 1; // Boundary for elements greater than pivot

    // Partition the array into three parts: less than pivot, equals to pivot and greater than pivot
    while (i <= high) {
        int cmp_res = compar((char *)base + i * size, pivot);
        if (cmp_res < 0) {
            // Swap base[i] and base[low], then increment both low and i
            void *temp = malloc(size);
            memcpy(temp, (char *)base + low * size, size);
            memcpy((char *)base + low * size, (char *)base + i * size, size);
            memcpy((char *)base + i * size, temp, size);
            free(temp); // Free temporary memory allocated

            low++;
            i++;
        } else if (cmp_res > 0) {
            // Swap base[i] and base[high], then decrement high
            void *temp = malloc(size);
            memcpy(temp, (char *)base + high * size, size);
            memcpy((char *)base + high * size, (char *)base + i * size, size);
            memcpy((char *)base + i * size, temp, size);
            free(temp); // Free temporary memory allocated

            high--;
        } else {
            // Element equals to the pivot, move to the next element of the array
            i++;
        }
    }

    *lt = low;   // Elements less than pivot end at index `low - 1`
    *gt = high;  // Elements greater than pivot start at index `high + 1`
    free(pivot); // Free memory allocated for pivot
}

// Quick Sort implementation with 3-Way Partitioning
void quick_sort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *)) {
    if (nitems <= 1 || base == NULL) return; // Base case: array of size 1 or empty

    size_t lt, gt; // Indices used as boundaries of the three partitions

    // Partition the array into three parts (explained in three_way_partition function) 
    three_way_partition(base, nitems, size, compar, &lt, &gt);

    // Recursive case: sort the parts less than and greater than the pivot
    quick_sort(base, lt, size, compar);                                        // Sort elements less than pivot
    quick_sort((char *)base + (gt + 1) * size, nitems - gt - 1, size, compar); // Sort elements greater than pivot
}