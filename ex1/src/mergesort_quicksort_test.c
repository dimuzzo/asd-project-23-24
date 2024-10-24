#include <stdio.h>
#include <assert.h>
#include <string.h>

void test_merge_sort() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int expected[] = {1, 2, 5, 5, 6, 9};
    merge_sort(arr, 6, sizeof(int), (int (*)(const void*, const void*)) strcmp);
    assert(memcmp(arr, expected, sizeof(arr)) == 0);
}

void test_quick_sort() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int expected[] = {1, 2, 5, 5, 6, 9};
    quick_sort(arr, 6, sizeof(int), (int (*)(const void*, const void*)) strcmp);
    assert(memcmp(arr, expected, sizeof(arr)) == 0);
}

int main() {
    test_merge_sort();
    test_quick_sort();
    printf("All tests passed!\n");
    return 0;
}
