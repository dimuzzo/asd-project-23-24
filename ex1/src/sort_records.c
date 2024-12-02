// Libraries declaration
#include <stdio.h>      
#include <stdlib.h>     
#include <string.h>     
#include <time.h>       
#include "mergesort_quicksort.h" // Header containing merge_sort and quick_sort implementations

#define MAX_LENGTH 1000  // Maximum length for string fields
#define TOTAL_RECORDS 20000000  // Total number of records to process

// Structure representing a single data record
struct data_rec {
    int id;             
    char field1[350];   
    int field2;         
    double field3;      
};

// Comparison function for field1 (string)
int compare_data_char(const void *a, const void *b) {
    struct data_rec *Data_A = (struct data_rec *)a;
    struct data_rec *Data_B = (struct data_rec *)b;
    return strcmp(Data_A->field1, Data_B->field1);
}

// Comparison function for field2 (integer)
int compare_data_int(const void *a, const void *b) {
    struct data_rec *Data_A = (struct data_rec *)a;
    struct data_rec *Data_B = (struct data_rec *)b;
    if (Data_A->field2 > Data_B->field2) return 1;
    else if (Data_A->field2 < Data_B->field2) return -1;
    else return 0;
}

// Comparison function for field3 (floating-point)
int compare_data_fp(const void *a, const void *b) {
    struct data_rec *Data_A = (struct data_rec *)a;
    struct data_rec *Data_B = (struct data_rec *)b;
    if (Data_A->field3 > Data_B->field3) return 1;
    else if (Data_A->field3 < Data_B->field3) return -1;
    else return 0;
}

// Main function to sort records read from a file and write sorted records to another file
void sort_records(FILE *infile, FILE *outfile, size_t field, size_t algo) {
    // Allocate memory for the records array
    struct data_rec *records = malloc(TOTAL_RECORDS * sizeof(struct data_rec));
    char line[MAX_LENGTH * 4]; // Buffer for reading lines
    size_t data_count = 0;     // Number of records read

    // Check for memory allocation failure
    if (!records) {
        printf("Memory allocation failed. Ensure sufficient memory is available.\n");
        return;
    }

    printf("Reading records into memory...\n");
    clock_t start_time = clock(); // Record the start time for reading

    while (fgets(line, sizeof(line), infile) != NULL && data_count < TOTAL_RECORDS) {
        // Parse each line into the corresponding fields of data_rec structure
        sscanf(line, "%d,%999[^,],%d,%lf", &records[data_count].id, records[data_count].field1, &records[data_count].field2, &records[data_count].field3);
        data_count++;
    }

    if (data_count == 0) {
        printf("No records to sort.\n");
        free(records); // Free allocated memory
        return;
    }

    printf("Sorting %zu records...\n", data_count);

    // Select the appropriate comparison function based on the chosen field
    int (*compar)(const void *, const void *);
    if (field == 1) compar = compare_data_char;     
    else if (field == 2) compar = compare_data_int; 
    else compar = compare_data_fp;                  

    // Sort using the chosen algorithm: Merge Sort or Quick Sort
    if (algo == 1) {
        merge_sort(records, data_count, sizeof(struct data_rec), compar); 
    } else {
        quick_sort(records, data_count, sizeof(struct data_rec), compar);
    }

    clock_t sort_time = clock(); // Record the sorting completion time
    printf("Sorting completed in %f seconds.\n", (double)(sort_time - start_time) / CLOCKS_PER_SEC);

    // Write sorted records to the output file
    printf("Writing sorted records to the output file...\n");
    for (size_t i = 0; i < data_count; i++) {
        fprintf(outfile, "%d,%s,%d,%lf\n", records[i].id, records[i].field1, records[i].field2, records[i].field3);
    }

    clock_t end_time = clock(); // Record the writing completion time
    printf("Writing completed in %f seconds.\n", (double)(end_time - sort_time) / CLOCKS_PER_SEC);
    printf("Total time: %f seconds.\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    free(records); // Free allocated memory
}

int main(int argc, char *argv[]) {
    // Check if the required arguments are provided
    if (argc != 5) {
        printf("Usage: %s <input_file> <output_file> <field> <algorithm>\n", argv[0]);
        return 1;
    }

    // Parse command-line arguments
    char *input_file = argv[1];     // Input file path
    char *output_file = argv[2];    // Output file path
    int field = atoi(argv[3]);      // Field to sort by (1, 2, or 3)
    int algo = atoi(argv[4]);       // Sorting algorithm (1 for Merge Sort, 2 for Quick Sort)

    // Open input file for reading
    FILE *infile = fopen(input_file, "r");
    if (!infile) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open output file for writing
    FILE *outfile = fopen(output_file, "w");
    if (!outfile) {
        printf("Error opening output file.\n");
        fclose(infile); // Close the input file before exiting
        return 1;
    }

    // Call the sort_records function
    sort_records(infile, outfile, field, algo);

    // Close the input and output files
    fclose(infile);
    fclose(outfile);

    return 0;
}