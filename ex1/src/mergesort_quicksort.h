#ifndef MERGESORT_QUICKSORT_H
#define MERGESORT_QUICKSORT_H

void merge(void *base, size_t mid, size_t nitems, size_t size, int (*compar)(const void *, const void *));

void merge_sort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *));

void three_way_partition(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *), size_t *lt, size_t *gt);

void quick_sort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *));

#endif