// libraries declaration
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// methods declaration:
// base = pointer to the first element of the array to order
// nitems = number of elements of the array to order
// size = size in bytes of each element of the array
// compar = criteria on how to order the elements of the array
void merge_sort(void *base, size_t nitems, size_t size, int (*compar)(const void*, const void*));
void quick_sort(void *base, size_t nitems, size_t size, int (*compar)(const void*, const void*));

// merge_sort method: algoritmo di ordinamento che divide il vettore in due parti da ordinare 
// in maniera separata tramite la ricorsione.
void merge_sort(void *base, size_t nitems, size_t size, int (*compar)(const void*, const void*)){
    if(nitems == 0){
    }
    else{
        merge_sort_wrap(base, size, 0, nitems - 1, compar);
    }
}

void merge_sort_wrap(void *base, size_t size, size_t left, size_t right, int (*compar)(const void*, const void*)){
    if(left < right){
        size_t mid = (left + right)/2;
        merge_sort_wrap(base, size, left, mid, compar);
        merge_sort_wrap(base, size, mid + 1, right, compar);
        merge(base, size, left, mid, right, compar);
    }
}

void merge(void *base, size_t size, size_t left, size_t mid, size_t right, int (*compar)(const void*, const void*)){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int arr_1[] = ;
    int arr_2[] = ;
    for(int i = 1; i <= n1; i++){
        arr_1[i] = [left + i - 1];
    }
    for(int j = 1; j <= n2; j++){
        arr_2[j] = [mid + j];
    }
    int i = 1;
    int j = 1;
    for(int k = left; k <= right; k++){
        if(arr_1[i] <= arr_2[j]){
            [k] = arr_1[i];
            i = i + 1;
        }
        else{
            [k] = arr_2[j];
            j = j + 1;
        }
    }
}

// quick_sort method: algoritmo di ordinamento che fa uso di un elemento centrale (pivot) 
// utilizzato per confrontare gli elementi del vettore da ordinare tramite la ricorsione.
void quick_sort(void *base, size_t nitems, size_t size, int (*compar)(const void*, const void*)){
    if(nitems == 0){
    }
    else{
        quick_sort_wrap(base, size, 0, nitems - 1, compar);
    }
}

void quick_sort_wrap(void *base, size_t size, size_t left, size_t right, int (*compar)(const void*, const void*)){
    if(left < right){
        size_t mid = partition(base, size, left, right, compar);
        quick_sort_wrap(base, size, left, mid - 1, compar);
        quick_sort_wrap(base, size, mid + 1, right, compar)
    }
}

int partition(void *base, size_t size, size_t left, size_t right, int (*compar)(const void*, const void*)){
    int x = [right];
    int i = left - 1;
    for(int j = left; j < right; j++){
        if( [j] <= x){
            i = i + 1;
            [i] = [j];
        }
    }
    [i + 1] = [right];
    return i + 1;
}

int main(){
    return 0;
}