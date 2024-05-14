// libraries declaration
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int minimum(int ins, int canc, int sub){
    if(ins <= canc && ins <= sub){
        return ins;
    }
    if(canc <= ins && canc <= sub){
        return canc;
    }
    else{
        return sub;
    }
}

int edit_distance(const char *s1, const char* s2){
    if(*s1 == '\0'){
        return strlen(s2);
    }
    if(*s2 == '\0'){
        return strlen(s1);
    }
    if(s1[0] == s2[0]){
        return edit_distance(s1+1, s2+1);
    }
    else{
        int ins = 1 + edit_distance(s1+1, s2);
        int canc = 1 + edit_distance(s1, s2+1);
        int sub = 0;

        if(s1[0] == s2[0]){
            sub = 1 + edit_distance(s1+1, s2+1);
        }
        if(s1[0] != s2[0]){
            sub = INT_MAX;
        }

        return minimum(ins, canc, sub);
    }
}

int main(){
    const char *s1 = "casa";
    const char *s2 = "cara";
    printf("The edit distance between '%s' and '%s' is '%d\n'", s1, s2, edit_distance(s1, s2));
    return 0;
}