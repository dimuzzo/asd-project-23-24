// Libraries declaration
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Merge Sort */
void merge(void *base, size_t left, size_t middle, size_t right, size_t size, int (*compar)(const void*, const void*)) {
    size_t i, j, k;
    size_t left_size = middle - left + 1;
    size_t right_size = right - middle;

    // Allocate temporary arrays
    void *left_arr = malloc(left_size * size);
    void *right_arr = malloc(right_size * size);

    // Copy data to temporary arrays
    memcpy(left_arr, base + left * size, left_size * size);
    memcpy(right_arr, base + (middle + 1) * size, right_size * size);

    // Merge temporary arrays back into base
    i = 0;
    j = 0;
    k = left;
    while (i < left_size && j < right_size) {
        if (compar(left_arr + i * size, right_arr + j * size) <= 0) {
            memcpy(base + k * size, left_arr + i * size, size);
            i++;
        } else {
            memcpy(base + k * size, right_arr + j * size, size);
            j++;
        }
        k++;
    }

    // Copy remaining elements of left_arr
    while (i < left_size) {
        memcpy(base + k * size, left_arr + i * size, size);
        i++;
        k++;
    }

    // Copy remaining elements of right_arr
    while (j < right_size) {
        memcpy(base + k * size, right_arr + j * size, size);
        j++;
        k++;
    }

    // Free temporary arrays
    free(left_arr);
    free(right_arr);
}

void merge_sort_helper(void *base, size_t left, size_t right, size_t size, int (*compar)(const void*, const void*)) {
    if (left < right) {
        size_t middle = left + (right - left) / 2;
        merge_sort_helper(base, left, middle, size, compar);
        merge_sort_helper(base, middle + 1, right, size, compar);
        merge(base, left, middle, right, size, compar);
    }
}

void merge_sort(void *base, size_t nitems, size_t size, int (*compar)(const void*, const void*)) {
    merge_sort_helper(base, 0, nitems - 1, size, compar);
}

/* Quick Sort */
void swap(void *a, void *b, size_t size) {
    void *temp = malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

size_t partition(void *base, size_t low, size_t high, size_t size, int (*compar)(const void*, const void*)) {
    void *pivot = base + high * size;
    size_t i = low - 1;

    for (size_t j = low; j < high; j++) {
        if (compar(base + j * size, pivot) < 0) {
            i++;
            swap(base + i * size, base + j * size, size);
        }
    }
    swap(base + (i + 1) * size, base + high * size, size);
    return i + 1;
}

void quick_sort_helper(void *base, size_t low, size_t high, size_t size, int (*compar)(const void*, const void*)) {
    if (low < high) {
        size_t pi = partition(base, low, high, size, compar);
        quick_sort_helper(base, low, pi - 1, size, compar);
        quick_sort_helper(base, pi + 1, high, size, compar);
    }
}

void quick_sort(void *base, size_t nitems, size_t size, int (*compar)(const void*, const void*)) {
    quick_sort_helper(base, 0, nitems - 1, size, compar);
}

/* Esempio di utilizzo */
int compare_int(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int arr[] = {9, 2, 5, 1, 7, 3, 8, 4, 6};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    
    // Merge Sort
    merge_sort(arr, n, sizeof(int), compare_int);
    printf("Array ordinato con Merge Sort: ");
    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Quick Sort
    int arr2[] = {9, 2, 5, 1, 7, 3, 8, 4, 6};
    quick_sort(arr2, n, sizeof(int), compare_int);
    printf("Array ordinato con Quick Sort: ");
    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    return 0;
}
