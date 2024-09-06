// libraries declaration
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "unity.h"
#include "edit_distance.h"
#include "unity_internals.h"

void edit_distance_test_onecanc(){
    TEST_ASSERT(edit_distance_dyn("casa", "cassa") == 1);
}
void edit_distance_test_onecanc_oneins(){
    TEST_ASSERT(edit_distance_dyn("casa", "cara") == 2);
}
void edit_distance_test_twoins(){
    TEST_ASSERT(edit_distance_dyn("vinaio", "vino") == 2);
}
void edit_distance_test_threecanc_oneins(){
    TEST_ASSERT(edit_distance_dyn("tassa", "passato") == 4);
}
void edit_distance_test_no_op(){
    TEST_ASSERT(edit_distance_dyn("pioppo", "pioppo") == 0);
}
void edit_distance_test_twocanc(){
    TEST_ASSERT(edit_distance_dyn("petto", "spettro") == 2);
}
void edit_distance_test_no_op_void(){
    TEST_ASSERT(edit_distance_dyn("", "") == 0);
}
void edit_distance_test_fourcanc_fiveins(){
    TEST_ASSERT(edit_distance_dyn("sette", "anno") == 9);
}
void edit_distance_test_null_correctword(){
    TEST_ASSERT(edit_distance_dyn(NULL, "indice") == -1);
}
void edit_distance_test_null_wrongword(){
    TEST_ASSERT(edit_distance_dyn("colonia", NULL) == -1);
}

int main(){
    UNITY_BEGIN();
    RUN_TEST(edit_distance_test_onecanc);
    RUN_TEST(edit_distance_test_onecanc_oneins);
    RUN_TEST(edit_distance_test_twoins);
    RUN_TEST(edit_distance_test_threecanc_oneins);
    RUN_TEST(edit_distance_test_no_op);
    RUN_TEST(edit_distance_test_twocanc);
    RUN_TEST(edit_distance_test_no_op_void);
    RUN_TEST(edit_distance_test_fourcanc_fiveins);
    RUN_TEST(edit_distance_test_null_correctword);
    RUN_TEST(edit_distance_test_null_wrongword);
    return UNITY_END();
}
