#include "vectorTests.hpp"

#include <iostream>

int main() {
   TestSet tests = genVec3TestSet();
   tests.runTests();
   tests.genReport();

   return 0;
}
