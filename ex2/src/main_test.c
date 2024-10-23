// Libraries declaration
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "edit_distance.h"
#define MAX_WORD_SIZE 30

void main_edit_distance(FILE *correct, FILE *dictionary){
    char word[MAX_WORD_SIZE]; // Temporary string to read a line from the file
    char dict[MAX_WORD_SIZE]; // String to read a line from the dictionary
    int word_readed = 0; // Counter for the number of data read

    // While loop to get the words suggested by the dictionary
    // Furthermore, there are calls to the tolower() function to also compare words in the file with uppercase letters
    while (fscanf(correct, "%29s", word) == 1) {
        *word = tolower(*word);
        printf("Word: \t %s\n", word);
        printf("Suggested words: \n");
        int min_edit = strlen(word);
        while (fscanf(dictionary, "%29s", dict) == 1) {
            *word = tolower(*word);
            int res = edit_distance_dyn(word, dict);
            if(res < min_edit)
                min_edit = res;
        }
        rewind(dictionary);
        while (fscanf(dictionary, "%29s", dict) == 1) {
            *word = tolower(*word);
            int res = edit_distance_dyn(word, dict);
            if(res == min_edit)
                printf("\t %s\n", dict);
        }
        rewind(dictionary);
    } 
}

int main(int argc, char *argv[]){

    if (argc != 3) {
        printf("Usage: %s <file input path correctme.txt> <file input path dictionary.txt> \n", argv[0]);
        return 1;
    }

    char *filename_read_correct = argv[1];
    char *filename_read_dictionary = argv[2];

    FILE *file_input1;
    FILE *file_input2;
   
    file_input1 = fopen(filename_read_correct, "r");
    if (file_input1 == NULL) {
        printf("Unable to open file: %s\n", filename_read_correct);
        return 1;
    }
   
    file_input2 = fopen(filename_read_dictionary, "r");
    if (file_input2 == NULL) {
        printf("Unable to open file: %s\n", filename_read_dictionary);
        return 1;
    }
   
    main_edit_distance(file_input1, file_input2);

    // Closing open files
    fclose(file_input1);
    fclose(file_input2);

    return 0;
}