// Libraries declaration
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mergesort_quicksort.h"
#define MAX_LENGTH 1000 // Maximum string length for each field
#define MAX_NUM_DATA 2000000 // Maximum number of data to read from the file

// Record structure
struct data_rec{
    int id;
    char field1[1000];  
    int field2;
    float field3;
};

// Comparison functions for the different fields of the record
int compare_data_char(const void *a, const void *b) {
    struct data_rec *Data_A = (struct data_rec *)a;
    struct data_rec *Data_B = (struct data_rec *)b;
    return strcmp(Data_A -> field1, Data_B -> field1);
}

int compare_data_int(const void *a, const void *b) {
    struct data_rec *Data_A = (struct data_rec *)a;
    struct data_rec *Data_B = (struct data_rec *)b;
    if ((Data_A -> field2) > (Data_B -> field2)) return 1;
    else if ((Data_A -> field2) < (Data_B -> field2)) return -1;
    else return 0;
}

int compare_data_float(const void *a, const void *b) {
    struct data_rec *Data_A = (struct data_rec *)a;
    struct data_rec *Data_B = (struct data_rec *)b;
    if ((Data_A -> field3) > (Data_B -> field3)) return 1;
    else if ((Data_A -> field3) < (Data_B -> field3)) return -1;
    else return 0;
}

// Function to sort records in CSV file
void sort_records(FILE *infile, FILE *outfile, size_t field, size_t algo) {
    
    struct data_rec *records = malloc(MAX_NUM_DATA * sizeof(struct data_rec));
    char line[MAX_LENGTH];
    size_t data_count = 0;
    
    if(records == NULL){
        printf("Memory allocation error");
        return;
    }
    
    // Modify reading to allow strings of arbitrary length
        while(fgets(line, sizeof(line), infile) != NULL && (data_count < MAX_NUM_DATA)){
        sscanf(line, "%d,%999[^,],%d,%f\n", &records[data_count].id, records[data_count].field1, &records[data_count].field2, &records[data_count].field3);
        data_count++;
    }

    // Select the correct comparator
    int (*compar)(const void *, const void *);
    if (field == 1)
        compar = compare_data_char;
    else if (field == 2)
        compar = compare_data_int;
    else
        compar = compare_data_float;

    // Select the sorting algorithm
    if (algo == 1) {
        merge_sort(records, data_count, sizeof(struct data_rec), compar);
    } else {
        quick_sort(records, data_count, sizeof(struct data_rec), compar);
    }

    // Write the sorted records to the output file
    for (size_t i = 0; i < data_count; i++) {
        fprintf(outfile, "%d,%s,%d,%f\n", records[i].id, records[i].field1, 
                records[i].field2, records[i].field3);
    }

    free(records);
    return;
}

int main(int argc, char *argv[]) {
    
    if(argc != 5){
        return 1;
    }
    
    char *set_records = argv[1];
    char *sorted_records = argv[2];
    int field = atoi(argv[3]);
    int algo = atoi(argv[4]);
    
    FILE *infile;
    FILE *outfile;

    infile = fopen(set_records, "r");
    if (infile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    outfile = fopen(sorted_records, "w");
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