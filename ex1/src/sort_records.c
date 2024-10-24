// Libraries declaration
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 1000 // Maximum string length for each field
#define MAX_NUM_DATA 20000000 // Maximum number of data to read from the file (20 million for local file, 100 for moodle testing)

typedef struct{
    int id;
    char f1[500];
    int f2;
    double f3;
}Fields;

int compar_char(const void *a, const void *b) {
    return strcmp(((Fields *)a)->f1, ((Fields *)b)->f1);
}

int compar_int(const void *a, const void *b) {
    return ((Fields *)a)->f2 - ((Fields *)b)->f2;
}

int compar_double(const void *a, const void *b) {
    if (((Fields *)a)->f3 > ((Fields *)b)->f3) return 1;
    else if (((Fields *)a)->f3 < ((Fields *)b)->f3) return -1;
    else return 0;
}

void sort_records(FILE *infile, FILE *outfile, size_t field, size_t algo) {
    // Record read from the file
    Fields *records = NULL;
    size_t count = 0, capacity = 100;
    field = malloc(capacity * sizeof(Fields));

    while (fscanf(infile, "%d,%49[^,],%d,%f\n", &records[count].id, records[count].f1,
                  &records[count].f2, &records[count].f3) == 4) {
        count++;
        if (count == capacity) {
            capacity *= 2;
            records = realloc(records, capacity * sizeof(Fields));
        }
    }

    int (*compar)(const void*, const void*);
    if (field == 1)
        compar = compar_char;
    else if (field == 2)
        compar = compar_int;
    else
        compar = compar_double;

    // Select the sorting algorithm
    if (algo == 1) {
        merge_sort(records, count, sizeof(Fields), compar);
    } else {
        quick_sort(records, count, sizeof(Fields), compar);
    }

    // Writes the sorted records into the output file
    for (size_t i = 0; i < count; i++) {
        fprintf(outfile, "%d,%s,%d,%f\n", records[i].id, records[i].f1,
                records[i].f2, records[i].f3);
    }

    free(records);
}
