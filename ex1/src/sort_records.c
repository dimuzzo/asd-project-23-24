// Libraries declaration
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "mergesort_quicksort.h"

#define MAX_LENGTH 1000  // Maximum string length for each field
#define MAX_NUM_DATA 1000  // Maximum number of records to read

// Record structure
struct data_rec {
    int id;
    char field1[1000];  
    int field2;
    float field3;
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

int compare_data_float(const void *a, const void *b) {
    struct data_rec *Data_A = (struct data_rec *)a;
    struct data_rec *Data_B = (struct data_rec *)b;
    if (Data_A->field3 > Data_B->field3) return 1;
    else if (Data_A->field3 < Data_B->field3) return -1;
    else return 0;
}

// Function to print the number of records sorted
void print_sorted_count(size_t count) {
    printf("Total sorted records: %zu.\n", count);
}

// Function to sort records in a file
void sort_records(FILE *infile, FILE *outfile, size_t field, size_t algo) {
    struct data_rec *records = malloc(MAX_NUM_DATA * sizeof(struct data_rec));
    char line[MAX_LENGTH];
    size_t data_count = 0;
    size_t total_sorted = 0;

    if (!records) {
        printf("Memory allocation failed.\n");
        return;
    }

    // Determine and print sorting algorithm and field
    const char *algo_name = (algo == 1) ? "Merge Sort" : "Quick Sort";
    const char *field_name = NULL;
    
    if (field == 1) field_name = "field1 - String";
    else if (field == 2) field_name = "field2 - Integer";
    else if (field == 3) field_name = "field3 - Float";
    
    printf("Sorting using %s on %s.\n", algo_name, field_name);

    // Records are read, sorted and wrote in chunks to minimize memory usage
    clock_t start_time = clock();
    while (fgets(line, sizeof(line), infile) != NULL) {
        if (data_count < MAX_NUM_DATA) {
            sscanf(line, "%d,%999[^,],%d,%f", &records[data_count].id, records[data_count].field1, &records[data_count].field2, &records[data_count].field3);
            data_count++;
        }
        
        // Sort when the chunk is full
        if (data_count == MAX_NUM_DATA) {
            // Select the correct comparator based on the field
            int (*compar)(const void *, const void *);
            if (field == 1) compar = compare_data_char;
            else if (field == 2) compar = compare_data_int;
            else compar = compare_data_float;

            // Choose the sorting algorithm
            if (algo == 1) {
                merge_sort(records, data_count, sizeof(struct data_rec), compar);
            } else {
                quick_sort(records, data_count, sizeof(struct data_rec), compar);
            }

            // Write the sorted chunk just analyzed to file
            for (size_t i = 0; i < data_count; i++) {
                fprintf(outfile, "%d,%s,%d,%f\n", records[i].id, records[i].field1, records[i].field2, records[i].field3);
            }

            total_sorted += data_count;
            data_count = 0;  // Reset to have enough space for the next chunk
        }
    }

    // If there are any remaining records to sort (less than MAX_NUM_DATA)
    if (data_count > 0) {
        int (*compar)(const void *, const void *);
        if (field == 1) compar = compare_data_char;
        else if (field == 2) compar = compare_data_int;
        else compar = compare_data_float;

        if (algo == 1) {
            merge_sort(records, data_count, sizeof(struct data_rec), compar);
        } else {
            quick_sort(records, data_count, sizeof(struct data_rec), compar);
        }

        for (size_t i = 0; i < data_count; i++) {
            fprintf(outfile, "%d,%s,%d,%f\n", records[i].id, records[i].field1, records[i].field2, records[i].field3);
        }

        total_sorted += data_count;
    }
    
    print_sorted_count(total_sorted);  // Print the count of sorted records
    clock_t end_time = clock();
    printf("Sorting took %f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
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
    if (infile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *outfile = fopen(output_file, "w");
    if (outfile == NULL) {
        printf("Error opening output file.\n");
        fclose(infile);
        return 1;
    }

    sort_records(infile, outfile, field, algo);

    fclose(infile);
    fclose(outfile);

    return 0;
}