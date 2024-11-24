#ifndef MERGESORT_QUICKSORT_H
#define MERGESORT_QUICKSORT_H

void merge(void *base, size_t mid, size_t nitems, size_t size, int (*compar)(const void *, const void *));

void merge_sort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *));

size_t partition(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *));

void quick_sort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *));

#endif
