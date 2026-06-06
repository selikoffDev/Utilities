#include "vectorTests.hpp"

#include "UtilsLib.hpp"

int main() {
   std::vector<TestSet> tests;

   tests.push_back(genVec3TestSet());

   for (auto ts: tests) {
      ts.runTests();
      ts.genReport();
   }
   return 0;
}
