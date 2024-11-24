// Libraries declaration
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mergesort_quicksort.h"
#include "unity.h"
#include "unity_internals.h"

int compare_data_char(const void *a, const void *b) {
    return strcmp((char*)a, (char*)b);
}

int compare_data_int(const void *a, const void *b) {
    if (*(int*)a > *(int*)b) return 1;
    else if (*(int*)a < *(int*)b) return -1;
    else return 0;
}

int compare_data_float(const void *a, const void *b) {
    if (*(float*)a > *(float*)b) return 1;
    else if (*(float*)a < *(float*)b) return -1;
    else return 0;
}

// Merge Sort Tests

// Char
void mergesort_char_test_zero_elements() {
    char arr[0];
    merge_sort(arr, 0, sizeof(char), compare_data_char);
    TEST_ASSERT_EQUAL(0, sizeof(arr)); 
}

void mergesort_char_test_one_element() {
    char arr[] = {'a'};
    merge_sort(arr, 1, sizeof(char), compare_data_char);
    TEST_ASSERT_EQUAL('a', arr[0]);
}

void mergesort_char_test_four_elements() {
    char arr[] = {'d', 'b', 'a', 'c'};
    char expected[] = {'a', 'b', 'c', 'd'};
    merge_sort(arr, 4, sizeof(char), compare_data_char);
    TEST_ASSERT_EQUAL_INT8_ARRAY(expected, arr, 4);
}

// Int
void mergesort_int_test_zero_elements() {
    int arr[0];
    merge_sort(arr, 0, sizeof(int), compare_data_int);
    TEST_ASSERT_EQUAL(0, sizeof(arr));
}

void mergesort_int_test_one_element() {
    int arr[] = {42};
    merge_sort(arr, 1, sizeof(int), compare_data_int);
    TEST_ASSERT_EQUAL(42, arr[0]);
}

void mergesort_int_test_four_elements() {
    int arr[] = {4, 2, 1, 3};
    int expected[] = {1, 2, 3, 4};
    merge_sort(arr, 4, sizeof(int), compare_data_int);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, arr, 4);
}

// Float
void mergesort_float_test_zero_elements() {
    float arr[0];
    merge_sort(arr, 0, sizeof(float), compare_data_float);
    TEST_ASSERT_EQUAL(0, sizeof(arr));
}

void mergesort_float_test_one_element() {
    float arr[] = {42.42};
    merge_sort(arr, 1, sizeof(float), compare_data_float);
    TEST_ASSERT_EQUAL_FLOAT(42.42, arr[0]); 
}

void mergesort_float_test_four_elements() {
    float arr[] = {4.4, 2.2, 1.1, 3.3};
    float expected[] = {1.1, 2.2, 3.3, 4.4};
    merge_sort(arr, 4, sizeof(float), compare_data_float);
    TEST_ASSERT_EQUAL_FLOAT_ARRAY(expected, arr, 4);
}

// Quick Sort Tests

// Char
void quicksort_char_test_zero_elements() {
    char arr[0];
    quick_sort(arr, 0, sizeof(char), compare_data_char);
    TEST_ASSERT_EQUAL(0, sizeof(arr));
}

void quicksort_char_test_one_element() {
    char arr[] = {'a'};
    quick_sort(arr, 1, sizeof(char), compare_data_char);
    TEST_ASSERT_EQUAL('a', arr[0]);
}

void quicksort_char_test_four_elements() {
    char arr[] = {'d', 'b', 'a', 'c'};
    char expected[] = {'a', 'b', 'c', 'd'};
    quick_sort(arr, 4, sizeof(char), compare_data_char);
    TEST_ASSERT_EQUAL_INT8_ARRAY(expected, arr, 4);
}

// Int
void quicksort_int_test_zero_elements() {
    int arr[0];
    quick_sort(arr, 0, sizeof(int), compare_data_int);
    TEST_ASSERT_EQUAL(0, sizeof(arr));
}

void quicksort_int_test_one_element() {
    int arr[] = {42};
    quick_sort(arr, 1, sizeof(int), compare_data_int);
    TEST_ASSERT_EQUAL(42, arr[0]);
}

void quicksort_int_test_four_elements() {
    int arr[] = {4, 2, 1, 3};
    int expected[] = {1, 2, 3, 4};
    quick_sort(arr, 4, sizeof(int), compare_data_int);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, arr, 4);
}

// Float
void quicksort_float_test_zero_elements() {
    float arr[0];
    quick_sort(arr, 0, sizeof(float), compare_data_float);
    TEST_ASSERT_EQUAL(0, sizeof(arr));
}

void quicksort_float_test_one_element() {
    float arr[] = {42.42};
    quick_sort(arr, 1, sizeof(float), compare_data_float);
    TEST_ASSERT_EQUAL_FLOAT(42.42, arr[0]); 
}

void quicksort_float_test_four_elements() {
    float arr[] = {4.4, 2.2, 1.1, 3.3};
    float expected[] = {1.1, 2.2, 3.3, 4.4};
    quick_sort(arr, 4, sizeof(float), compare_data_float);
    TEST_ASSERT_EQUAL_FLOAT_ARRAY(expected, arr, 4);
}

int main(){
    UNITY_BEGIN();
    
    // Testing Merge Sort
    
    // Char tests
    RUN_TEST(mergesort_char_test_zero_elements);
    RUN_TEST(mergesort_char_test_one_element);
    RUN_TEST(mergesort_char_test_four_elements);
    
    // Int tests
    RUN_TEST(mergesort_int_test_zero_elements);
    RUN_TEST(mergesort_int_test_one_element);
    RUN_TEST(mergesort_int_test_four_elements);
    
    // Float tests
    RUN_TEST(mergesort_float_test_zero_elements);
    RUN_TEST(mergesort_float_test_one_element);
    RUN_TEST(mergesort_float_test_four_elements);

    // Testing Quick Sort
    
    // Char tests
    RUN_TEST(quicksort_char_test_zero_elements);
    RUN_TEST(quicksort_char_test_one_element);
    RUN_TEST(quicksort_char_test_four_elements);
    
    // Int tests
    RUN_TEST(quicksort_int_test_zero_elements);
    RUN_TEST(quicksort_int_test_one_element);
    RUN_TEST(quicksort_int_test_four_elements);
    
    // Float tests
    RUN_TEST(quicksort_float_test_zero_elements);
    RUN_TEST(quicksort_float_test_one_element);
    RUN_TEST(quicksort_float_test_four_elements);

    return UNITY_END();
}