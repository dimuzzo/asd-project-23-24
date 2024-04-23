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
        size_t mid = left + ((right - left)/2);
        merge_sort_wrap(base, size, left, mid, compar);
        merge_sort_wrap(base, size, mid + 1, right, compar);
        merge(base, size, left, mid, right, compar);
    }
}

void merge(void *base, size_t size, size_t left, size_t mid, size_t right, int (*compar)(const void*, const void*)){
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;

    size_t i = 0;
    size_t j = 0;
    size_t k = left;

    void arr_1 = malloc(n1 * size);
    void arr_2 = malloc(n2 * size);

    memcpy(arr_1, (char *)base + left*size, n1*size);
    memcpy(arr_2, (char *)base + (mid + 1)*size, n2*size);

    while(i < n1 && j < n2){
        if(compar((char *)arr_1 + i*size, (char *)arr_2 + j*size) <= 0){
            memcpy((char *)base + k*size, (char *)arr_1 + i*size, size);
            i++;
        }
        else{
            memcpy((char *)base + k*size, (char *)arr_2 + j*size, size);
            j++;
        }
        k++;
    }

    while(i < n1){
        memcpy((char *)base + k*size, (char *)arr_1 + i*size, size);
        i++;
        k++;
    }

    while(j < n2){
        memcpy((char *)base + k*size, (char *)arr_2 + j*size, size);
        j++;
        k++;
    }

    free(arr_1);
    free(arr_2);
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

size_t partition(void *base, size_t size, size_t left, size_t right, int (*compar)(const void*, const void*)){
    void *mid = (char *)base + right*size;
    size_t i = left - 1;

    for(size_t j = left; j < right; j++){
        if(compar((char *)base + j*size, mid) <= 0){
            i++;
            void *temporary = malloc(size);
            memcpy(temporary, (char *)base + i*size, size);
            memcpy((char *)base + i*size, (char *)base + j*size, size)
            memcpy((char *)base + j*size, temporary, size);
            free(temporary);

            return i+1;
        }
    }
}

int main(){
    return 0;
}