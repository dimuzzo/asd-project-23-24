// Libraries declaration
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// This function is used to determine the minimum cost operation (no operation, insert or delete) during the edit distance calculation
int min(int st, int nd, int rd) {
    if(st <= nd && st <= rd) return st;
    if(nd <= st && nd <= rd) return nd;
    else return rd;
}

// Recursive function to calculate the edit distance between two strings
// It computes the minimum number of operations required to convert string s2 into string s1
int edit_distance(const char *s1, const char* s2) {
    // If s1 is empty, the number of operations equals the length of s2 (all insertions)
    if(*s1 == '\0') return strlen(s2);

    // If s2 is empty, the number of operations equals the length of s1 (all deletions)
    if(*s2 == '\0') return strlen(s1);

    // If the first characters are the same, no operation is needed, just continue with the rest of the strings
    if(s1[0] == s2[0]) return edit_distance(s1 + 1, s2 + 1);

    else {
        // Calculate the costs of the three possible operations
        int no_op = (s1[0] == s2[0]) ? edit_distance(s1 + 1, s2 + 1) : INT_MAX; 
        int ins = 1 + edit_distance(s1 + 1, s2);  
        int canc = 1 + edit_distance(s1, s2 + 1);
        
        // Return the minimum of the three possible operations
        return min(no_op, ins, canc);
    }
}

// Support function for calculating the result of edit_distance_dyn
int edit_distance_dyn_recursive(const char *s1, const char *s2, int lens1, int lens2, int **mat) {
    // Base case: if one string is empty, return the length of the other string
    if (lens1 == 0) return lens2;
    if (lens2 == 0) return lens1;

    // If the result has already been calculated, return the stored value
    if (mat[lens1][lens2] != -1) return mat[lens1][lens2];

    // Recursive case: calculate the costs of the three possible operations
    int no_op = (s1[0] == s2[0]) ? edit_distance_dyn_recursive(s1 + 1, s2 + 1, lens1 - 1, lens2 - 1, mat) : INT_MAX;
    int canc = 1 + edit_distance_dyn_recursive(s1, s2 + 1, lens1, lens2 - 1, mat);
    int ins = 1 + edit_distance_dyn_recursive(s1 + 1, s2, lens1 - 1, lens2, mat);

    // Store the result in the matrix and return the minimum value
    mat[lens1][lens2] = min(no_op, canc, ins);
    return mat[lens1][lens2];
}

// Recursive dynamic function to calculate the edit distance between two strings
// This function initializes the matrix and calls the recursive function to compute the edit distance
int edit_distance_dyn(const char *s1, const char *s2) {
    if(s1 == NULL || s2 == NULL) return -1;

    int lens1 = strlen(s1);
    int lens2 = strlen(s2);
    
    // Allocate memory for a two dimension matrix to store the results
    int **mat = malloc((lens1 + 1) * sizeof(int *));
    
    // Initialize the matrix, filling it with -1 (uncalculated values)
    for(int i = 0; i <= lens1; i++) {
        mat[i] = malloc((lens2 + 1) * sizeof(int));
        memset(mat[i], -1, (lens2 + 1) * sizeof(int));
    }
    
    int res = edit_distance_dyn_recursive(s1, s2, lens1, lens2, mat);
    
    // Free the allocated memory for the matrix
    for(int i = 0; i <= lens1; i++) {
        free(mat[i]);
    }
    free(mat);

    return res;
}