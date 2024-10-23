// Libraries declaration
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "unity.h"
#include "edit_distance.h"
#include "unity_internals.h"

// Tests for static edit_distance
void edit_distance_test_onecanc(){
    TEST_ASSERT(edit_distance("casa", "cassa") == 1);
}
void edit_distance_test_onecanc_oneins(){
    TEST_ASSERT(edit_distance("casa", "cara") == 2);
}
void edit_distance_test_twoins(){
    TEST_ASSERT(edit_distance("vinaio", "vino") == 2);
}
void edit_distance_test_threecanc_oneins(){
    TEST_ASSERT(edit_distance("tassa", "passato") == 4);
}
void edit_distance_test_no_op(){
    TEST_ASSERT(edit_distance("pioppo", "pioppo") == 0);
}
void edit_distance_test_twocanc(){
    TEST_ASSERT(edit_distance("petto", "spettro") == 2);
}
void edit_distance_test_no_op_void(){
    TEST_ASSERT(edit_distance("", "") == 0);
}
void edit_distance_test_fourcanc_fiveins(){
    TEST_ASSERT(edit_distance("sette", "anno") == 9);
}

// Tests for dynamic edit_distance
void edit_distance_test_onecanc_dyn(){
    TEST_ASSERT(edit_distance_dyn("casa", "cassa") == 1);
}
void edit_distance_test_onecanc_oneins_dyn(){
    TEST_ASSERT(edit_distance_dyn("casa", "cara") == 2);
}
void edit_distance_test_twoins_dyn(){
    TEST_ASSERT(edit_distance_dyn("vinaio", "vino") == 2);
}
void edit_distance_test_threecanc_oneins_dyn(){
    TEST_ASSERT(edit_distance_dyn("tassa", "passato") == 4);
}
void edit_distance_test_no_op_dyn(){
    TEST_ASSERT(edit_distance_dyn("pioppo", "pioppo") == 0);
}
void edit_distance_test_twocanc_dyn(){
    TEST_ASSERT(edit_distance_dyn("petto", "spettro") == 2);
}
void edit_distance_test_no_op_void_dyn(){
    TEST_ASSERT(edit_distance_dyn("", "") == 0);
}
void edit_distance_test_fourcanc_fiveins_dyn(){
    TEST_ASSERT(edit_distance_dyn("sette", "anno") == 9);
}

int main(){
    UNITY_BEGIN();

    // Static tests
    RUN_TEST(edit_distance_test_onecanc);
    RUN_TEST(edit_distance_test_onecanc_oneins);
    RUN_TEST(edit_distance_test_twoins);
    RUN_TEST(edit_distance_test_threecanc_oneins);
    RUN_TEST(edit_distance_test_no_op);
    RUN_TEST(edit_distance_test_twocanc);
    RUN_TEST(edit_distance_test_no_op_void);
    RUN_TEST(edit_distance_test_fourcanc_fiveins);

    // Dynamic tests
    RUN_TEST(edit_distance_test_onecanc_dyn);
    RUN_TEST(edit_distance_test_onecanc_oneins_dyn);
    RUN_TEST(edit_distance_test_twoins_dyn);
    RUN_TEST(edit_distance_test_threecanc_oneins_dyn);
    RUN_TEST(edit_distance_test_no_op_dyn);
    RUN_TEST(edit_distance_test_twocanc_dyn);
    RUN_TEST(edit_distance_test_no_op_void_dyn);
    RUN_TEST(edit_distance_test_fourcanc_fiveins_dyn);

    return UNITY_END();
}
