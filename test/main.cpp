#include "vectorTests.hpp"

#include "UtilsLib.hpp"

int main() {
   TestSet tests = genVec3TestSet();
   tests.runTests();
   tests.genReport();

   Logger lgr;
   lgr.logLevelTest();
   lgr.symbolTest();


   return 0;
}
