#include "vectorTests.hpp"

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

//equal
//index
//sum diff
//mul div
//vec ops
//dot and cross

TestSet genVec3TestSet() {
   TestSet ts("Vec3 Tests");

   //initializationTests
   ts.registerTest(Test("Initialization 1",vec3_initTest1));
   ts.registerTest(Test("Initialization 2",vec3_initTest1));
   ts.registerTest(Test("Initialization 3",vec3_initTest1));

   //equal
   //index
   //sum diff
   //mul div
   //vec ops
   //dot and cross

   return ts;
}
