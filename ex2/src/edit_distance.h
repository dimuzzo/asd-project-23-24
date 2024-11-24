#ifndef EDIT_DISTANCE_H
#define EDIT_DISTANCE_H

int min(int st, int nd, int rd);
int edit_distance(const char *s1, const char* s2);
int edit_distance_dyn_recursive(const char *s1, const char *s2, int lens1, int lens2, int **mat);
int edit_distance_dyn(const char *s1, const char *s2);

#endif