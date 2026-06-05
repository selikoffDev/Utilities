#ifndef VECTOR_TEST_HPP
#define VECTOR_TEST_HPP

#include "UtilsLib.hpp"
#include "test.hpp"

//initializationTests
bool vec3_initTest1();
bool vec3_initTest2();
bool vec3_initTest3();

// equivalent
bool vec3_equivalentTest();

//equal
bool vec3_equalTest();

//index
bool vec3_indexTest();

//sum diff
bool vec3_addTest();
bool vec3_subTest();

//mul div
bool vec3_multTest();
bool vec3_divTest();

//vec ops
bool vec3_normTest();
bool vec3_uvecTest();
bool vec3_normalizeTest();

//dot and cross
bool vec3_dotTest();
bool vec3_crossTest();

TestSet genVec3TestSet();
#endif
