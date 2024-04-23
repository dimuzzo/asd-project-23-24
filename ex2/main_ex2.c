// libraries declaration
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int edit_distance(const char *s1, const char* s2){
    if(*s1 == '\0'){
        return strlen(s2);
    }
    if(*s2 == '\0'){
        return strlen(s1);
    }

    int no_op = edit_distance(s1+1, s2+1);
    int canc = 1 + edit_distance(s1, s2+1);
    int ins = 1 + edit_distance(s1+1, s2);

    return ((no_op < canc) ? ((no_op < ins) ? no_op : ins) : ((canc < ins) ? canc : ins));
}

int edit_distance_dyn(const char *s1, const char* s2){

}

int main(){
    const char *s1 = "casa";
    const char *s2 = "cara";
    printf("The edit distance between '%s' and '%s' is '%d\n'", s1, s2, edit_distance(s1, s2));
    return 0;
}