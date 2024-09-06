// libraries declaration
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "edit_distance.h"

int min(int st, int nd, int rd){
    if(st <= nd && st <= rd) return st;

    if(nd <= st && nd <= rd) return nd;

    else return rd;
}

int edit_distance(const char *s1, const char* s2){
    if(*s1 == '\0') return strlen(s2);

    if(*s2 == '\0') return strlen(s1);

    if(s1[0] == s2[0]) return edit_distance(s1+1, s2+1);

    else{
        int ins = 1 + edit_distance(s1 + 1, s2);
        int canc = 1 + edit_distance(s1, s2 + 1);
        int sub = (s1[0] == s2[0]) ? 1 + edit_distance(s1 + 1, s2 + 1) : INT_MAX;
        return min(ins, canc, sub);
    }
}

// Funzione ricorsiva per calcolare la distanza di modifica tra due stringhe
int edit_distance_dyn_recursive(const char *s1, const char *s2, int lens1, int lens2, int **mat) {
    if (lens1 == 0) return lens2;
    if (lens2 == 0) return lens1;

    // Se il risultato è già stato calcolato, ritorna il valore memorizzato
    if (mat[lens1][lens2] != -1) return mat[lens1][lens2];

    // Calcolo dei costi delle tre operazioni possibili
    int no_op = (s1[0] == s2[0]) ? edit_distance_dyn_recursive(s1 + 1, s2 + 1, lens1 - 1, lens2 - 1, mat) : INT_MAX;
    int canc = 1 + edit_distance_dyn_recursive(s1, s2 + 1, lens1, lens2 - 1, mat); // Cancella s2[0]
    int ins = 1 + edit_distance_dyn_recursive(s1 + 1, s2, lens1 - 1, lens2, mat); // Inserisce s1[0] in s2

    // Memorizza il risultato nella tabella e restituisce il valore
    mat[lens1][lens2] = min(no_op, canc, ins);
    return mat[lens1][lens2];
}

int edit_distance_dyn(const char *s1, const char *s2) {
    if(s1 == NULL || s2 == NULL) return -1;

    int lens1 = strlen(s1);
    int lens2 = strlen(s2);
    
    int **mat = malloc((lens1 + 1) * sizeof(int *));
    
    for(int i = 0; i <= lens1; i++){
        mat[i] = malloc((lens2 + 1) * sizeof(int));
        memset(mat[i], -1, (lens2 + 1) * sizeof(int));
    }
    
    int res = edit_distance_dyn_recursive(s1, s2, lens1, lens2, mat);
    
    for(int i = 0; i <= lens1; i++){
        free(mat[i]);
    }
    
    free(mat);
    return res;
}
