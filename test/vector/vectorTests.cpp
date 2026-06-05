#include "vectorTests.hpp"

#include <iostream>

#include "UtilsLib.hpp"
#include "test.hpp"

//initializationTests
bool vec3_initTest1() {
   vec3 vec;

   return vec.mData[0] == 0.0 and vec.mData[1] == 0.0 and vec.mData[2] == 0.0;
}

bool vec3_initTest2() {
   double val {69.0};
   vec3 vec(val);

   return vec.mData[0] == val and vec.mData[1] == val and vec.mData[2] == val;
}

bool vec3_initTest3() {
   double vals[3] {69.0, 420.0, 69420.0};
   vec3 vec(vals);

   return vec.mData[0] == vals[0] and vec.mData[1] == vals[1] and vec.mData[2] == vals[2];
}

//equivalent
bool vec3_equivalentTest() {
   double vals[3] {69.0, 420.0, 69420.0};
   vec3 vec1(vals);
   vec3 vec2(vals);

   return vec1 == vec2;
}

//equal
bool vec3_equalTest() {
   double vals[3] {69.0, 420.0, 69420.0};
   vec3 vec1(vals);
   vec3 vec2;
   vec2 = vec1;

   return vec1 == vec2;
}

//index
bool vec3_indexTest() {
   double vals[3] {69.0, 420.0, 69420.0};
   vec3 vec(vals);

   return vec[0] == vals[0] && vec[1] == vals[1] && vec[2] == vals[2];
}

//sum diff
bool vec3_addTest() {
   double vals[3] {69.0, 420.0, 69420.0};
   vec3 vec1(vals);
   vec3 vec2(vals);
   vec3 vec;
   vec = vec1 + vec2;

   return vec[0] == 2.0*vals[0] && vec[1] == 2.0*vals[1] && vec[2] == 2.0*vals[2];
}

bool vec3_subTest() {
   double vals[3] {69.0, 420.0, 69420.0};
   vec3 vec1(vals);
   vec3 vec2(vals);
   vec3 vec;
   vec = vec1 - vec2;

   return vec[0] == 0.0 && vec[1] == 0.0 && vec[2] == 0.0;
}

//mul div
bool vec3_multTest() {
   double vals[3] {69.0, 420.0, 69420.0};
   vec3 vec1(vals);
   vec3 vec2(vals);
   vec3 vec;
   vec = vec1*vec2;

   return vec[0] == vals[0]*vals[0] && vec[1] == vals[1]*vals[1] && vec[2] == vals[2]*vals[2];
}

bool vec3_divTest() {
   double vals[3] {69.0, 420.0, 69420.0};
   vec3 vec1(vals);
   vec3 vec2(vals);
   vec3 vec;
   vec = vec1/vec2;

   return vec[0] == 1.0 && vec[1] == 1.0 && vec[2] == 1.0;
}

//vec ops
bool vec3_normTest() {
   double vals[3] {69.0, 420.0, 69420.0};
   vec3 vec(vals);
   double norm;
   norm = vec.norm();

   return norm == vec[0] + vec[1] + vec[2];
}

bool vec3_uvecTest() {
   double vals[3] {69.0, 420.0, 69420.0};
   vec3 vec(vals);
   vec3 uvec;
   double norm = vals[0] + vals[1] + vals[2];

   uvec = vec.uvec();

   return uvec[0] == vals[0]/norm && uvec[1] == vals[1]/norm && uvec[2] == vals[2]/norm;
}

bool vec3_normalizeTest() {
   double vals[3] {69.0, 420.0, 69420.0};
   vec3 vec(vals);
   double norm = vals[0] + vals[1] + vals[2];

   vec.normalize();

   return vec[0] == vals[0]/norm && vec[1] == vals[1]/norm && vec[2] == vals[2]/norm;
}

//dot and cross
bool vec3_dotTest() {
   double vals[3] {69.0, 420.0, 69420.0};
   vec3 vec1(vals);
   vec3 vec2(vals);
   double dotTrue = vals[0]*vals[0] + vals[1]*vals[1] + vals[2]*vals[2];

   double dot = vec1.dot(vec2);

   return dot == dotTrue;
}

bool vec3_crossTest() {
   double vals1[3] {69.0, 420.0, 69420.0};
   double vals2[3] {420.0, 69420.0, 69.0};
   vec3 vec1(vals1);
   vec3 vec2(vals2);
   double crossI = vals1[1]*vals2[2] - vals1[2]*vals2[1];
   double crossJ = vals1[2]*vals2[0] - vals1[0]*vals2[2];
   double crossK = vals1[0]*vals2[1] - vals1[1]*vals2[0];

   vec3 cross = vec1.cross(vec2);

   return cross[0] == crossI && cross[1] == crossJ && cross[2] == crossK;
}

TestSet genVec3TestSet() {
   TestSet ts("Vec3 Tests");

   //initializationTests
   ts.registerTest(Test("Initialization 1",vec3_initTest1));
   ts.registerTest(Test("Initialization 2",vec3_initTest1));
   ts.registerTest(Test("Initialization 3",vec3_initTest1));

   //equivalent
   ts.registerTest(Test("Equivalency",vec3_equivalentTest));

   //equal
   ts.registerTest(Test("Equals",vec3_equalTest));

   //index
   ts.registerTest(Test("Index",vec3_indexTest));

   //sum diff
   ts.registerTest(Test("Addition",vec3_addTest));
   ts.registerTest(Test("Subtraction",vec3_subTest));

   //mul div
   ts.registerTest(Test("Multiplication",vec3_multTest));
   ts.registerTest(Test("Division",vec3_divTest));

   //vec ops
   ts.registerTest(Test("Norm",vec3_normTest));
   ts.registerTest(Test("Unit Vector",vec3_uvecTest));
   ts.registerTest(Test("Normalization",vec3_normalizeTest));

   //dot and cross
   ts.registerTest(Test("Dot Product",vec3_dotTest));
   ts.registerTest(Test("Cross Product",vec3_crossTest));

   return ts;
}
