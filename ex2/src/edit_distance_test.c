// libraries declaration
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "unity.h"
#include "edit_distance.h"

void edit_distance_test(){
    TEST_ASSERT(edit_distance_dyn("casa", "cassa") == 1);
    TEST_ASSERT(edit_distance_dyn("casa", "cara") == 2);
    TEST_ASSERT(edit_distance_dyn("vinaio", "vino") == 2);
    TEST_ASSERT(edit_distance_dyn("tassa", "passato") == 4);
    TEST_ASSERT(edit_distance_dyn("pioppo", "pioppo") == 0);
    TEST_ASSERT(edit_distance_dyn("plettro", "spettro") == 2);
    TEST_ASSERT(edit_distance_dyn("", "") == 0);
    TEST_ASSERT(edit_distance_dyn("sette", "anno") == 9);
    TEST_ASSERT(edit_distance_dyn(NULL, "indice") == -1);
    TEST_ASSERT(edit_distance_dyn("colonia", NULL) == -1);
}

int main(){
    UNITY_BEGIN();
    RUN_TEST(edit_distance_test);
    return UNITY_END();
}