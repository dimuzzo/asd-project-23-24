#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "edit_distance.h"
#define MAX_WORD_SIZE 30

void main_edit_distance(FILE *correct, FILE *dictionary){

    char word[MAX_WORD_SIZE]; // Stringa temporanea per leggere una riga dal file
    char dict[MAX_WORD_SIZE];
    int word_readed = 0; // Contatore per il numero di dati letti

    while (fscanf(correct, "%29s", word) == 1) {
        *word = tolower(*word);
        printf("Parola: \t %s\n", word);
        printf("Suggerimenti: \n");
        int min_edit = strlen(word);
        while (fscanf(dictionary, "%29s", dict) == 1) {
            int res = edit_distance_dyn(word,dict);
        if(res < min_edit)
            min_edit = res;
    }
    rewind(dictionary);
    while (fscanf(dictionary, "%29s", dict) == 1) {
        *word = tolower(*word);
        int res = edit_distance_dyn(word,dict);
        if(res == min_edit)
            printf("\t %s\n",dict);
    }
    rewind(dictionary);
    }
   
}

int main(int argc, char *argv[]){

    if (argc != 3) {
        printf("Usage: %s <file input path correctme.txt> <file input path dictionary.txt> \n", argv[0]);
        return 1;
    }

    char *filename_read_correct = argv[1]; // Nome file CSV che leggo
    char *filename_read_dictionary = argv[2]; // Nome file CSV che scrivo

    FILE *file_input1;
    FILE *file_input2;
   
    file_input1 = fopen(filename_read_correct, "r");
    if (file_input1 == NULL) {
        printf("Impossibile aprire il file %s\n", filename_read_correct);
        return 1;
    }
   
    file_input2 = fopen(filename_read_dictionary, "r");
    if (file_input2 == NULL) {
        printf("Impossibile aprire il file %s\n", filename_read_dictionary);
        return 1;
    }
   
    main_edit_distance(file_input1,file_input2);

    // Chiusura dei file
    fclose(file_input1);
    fclose(file_input2);

    return 0;
}