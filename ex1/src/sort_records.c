// Libraries declaration
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "mergesort_quicksort.h"

#define MAX_LENGTH 1000  // Maximum string length for each field
#define TOTAL_RECORDS 20000000  // Total number of records

// Record structure
struct data_rec {
    int id;
    char field1[350];  
    int field2;
    double field3;
};

// Comparison functions for the different fields of the record
int compare_data_char(const void *a, const void *b) {
    struct data_rec *Data_A = (struct data_rec *)a;
    struct data_rec *Data_B = (struct data_rec *)b;
    return strcmp(Data_A->field1, Data_B->field1);
}

int compare_data_int(const void *a, const void *b) {
    struct data_rec *Data_A = (struct data_rec *)a;
    struct data_rec *Data_B = (struct data_rec *)b;
    if (Data_A->field2 > Data_B->field2) return 1;
    else if (Data_A->field2 < Data_B->field2) return -1;
    else return 0;
}

int compare_data_fp(const void *a, const void *b) {
    struct data_rec *Data_A = (struct data_rec *)a;
    struct data_rec *Data_B = (struct data_rec *)b;
    if (Data_A->field3 > Data_B->field3) return 1;
    else if (Data_A->field3 < Data_B->field3) return -1;
    else return 0;
}

// Main sorting function
void sort_records(FILE *infile, FILE *outfile, size_t field, size_t algo) {
    struct data_rec *records = malloc(TOTAL_RECORDS * sizeof(struct data_rec));
    char line[MAX_LENGTH * 4];
    size_t data_count = 0;

    if (!records) {
        printf("Memory allocation failed. Ensure sufficient memory is available.\n");
        return;
    }

    printf("Reading records into memory...\n");
    clock_t start_time = clock();

    // Load all records into memory
    while (fgets(line, sizeof(line), infile) != NULL && data_count < TOTAL_RECORDS) {
        sscanf(line, "%d,%999[^,],%d,%lf", &records[data_count].id, records[data_count].field1, &records[data_count].field2, &records[data_count].field3);
        data_count++;
    }

    if (data_count == 0) {
        printf("No records to sort.\n");
        free(records);
        return;
    }

    printf("Sorting %zu records...\n", data_count);

    // Select the comparison function
    int (*compar)(const void *, const void *);
    if (field == 1) compar = compare_data_char;
    else if (field == 2) compar = compare_data_int;
    else compar = compare_data_fp;

    // Sort the records
    if (algo == 1) {
        merge_sort(records, data_count, sizeof(struct data_rec), compar);
    } else {
        quick_sort(records, data_count, sizeof(struct data_rec), compar);
    }

    clock_t sort_time = clock();
    printf("Sorting completed in %f seconds.\n", (double)(sort_time - start_time) / CLOCKS_PER_SEC);

    // Write sorted records to the output file
    printf("Writing sorted records to the output file...\n");
    for (size_t i = 0; i < data_count; i++) {
        fprintf(outfile, "%d,%s,%d,%lf\n", records[i].id, records[i].field1, records[i].field2, records[i].field3);
    }

    clock_t end_time = clock();
    printf("Writing completed in %f seconds.\n", (double)(end_time - sort_time) / CLOCKS_PER_SEC);
    printf("Total time: %f seconds.\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    free(records);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <input_file> <output_file> <field> <algorithm>\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    int field = atoi(argv[3]);
    int algo = atoi(argv[4]);

    FILE *infile = fopen(input_file, "r");
    if (!infile) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *outfile = fopen(output_file, "w");
    if (!outfile) {
        printf("Error opening output file.\n");
        fclose(infile);
        return 1;
    }

    sort_records(infile, outfile, field, algo);

    fclose(infile);
    fclose(outfile);

    return 0;
}