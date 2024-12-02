// Libraries declaration
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "edit_distance.h"

#define MAX_WORD_SIZE 50

void process_edit_distance(FILE *dictionary, FILE *correctme) {
    char word_to_correct[MAX_WORD_SIZE]; // Word from the "correctme" file
    char dictionary_word[MAX_WORD_SIZE]; // Word from the dictionary
    int min_edit_distance;               // Tracks the minimum edit distance for the current word

    // Process each word from the "correctme" file
    while (fscanf(correctme, "%49s", word_to_correct) == 1) {
        // Convert the input word to lowercase
        for (int i = 0; word_to_correct[i]; i++) {
            word_to_correct[i] = tolower(word_to_correct[i]);
        }

        printf("Word analyzed:\n\t%s\n", word_to_correct);
        printf("Suggested words:\n");

        min_edit_distance = MAX_WORD_SIZE; // Set initial value for the minimum edit distance

        // First find the minimum edit distance for the current word
        while (fscanf(dictionary, "%49s", dictionary_word) == 1) {
            // Convert the dictionary word to lowercase
            for (int i = 0; dictionary_word[i]; i++) {
                dictionary_word[i] = tolower(dictionary_word[i]);
            }

            int edit_distance = edit_distance_dyn(word_to_correct, dictionary_word);
            if (edit_distance < min_edit_distance) {
                min_edit_distance = edit_distance;
            }
        }

        rewind(dictionary); // Reset the dictionary file pointer for the printing

        // Then print all dictionary words with the minimum edit distance
        while (fscanf(dictionary, "%49s", dictionary_word) == 1) {
            for (int i = 0; dictionary_word[i]; i++) {
                dictionary_word[i] = tolower(dictionary_word[i]);
            }

            int edit_distance = edit_distance_dyn(word_to_correct, dictionary_word);
            if (edit_distance == min_edit_distance) {
                printf("\t%s\n", dictionary_word);
            }
        }

        rewind(dictionary); // Reset the dictionary file pointer for the next word
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary.txt> <correctme.txt>\n", argv[0]);
        return 1;
    }

    char *dictionary_path = argv[1];
    char *correctme_path = argv[2];

    FILE *dictionary_file = fopen(dictionary_path, "r");
    if (!dictionary_file) {
        fprintf(stderr, "Error: unable to open the dictionary file '%s'.\n", dictionary_path);
        return 1;
    }

    FILE *correctme_file = fopen(correctme_path, "r");
    if (!correctme_file) {
        fprintf(stderr, "Error: unable to open the file to correct '%s'.\n", correctme_path);
        fclose(dictionary_file);
        return 1;
    }

    process_edit_distance(dictionary_file, correctme_file);

    // Close open files
    fclose(dictionary_file);
    fclose(correctme_file);

    return 0;
}